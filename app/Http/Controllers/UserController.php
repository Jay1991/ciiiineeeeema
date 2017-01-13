<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\User;
use Intervention\Image\ImageServiceProvider;
use Intervention\Image\Facades\Image;
class UserController extends Controller
{
    //
    private $app;

    public function __construct()
    {
        $this->app = new AppController;
    }

    public function index()
    {
        return $this->isAdmin();
    }

     public function store(Request $request)
    {

     try
    {
    $rules                                                                      = array(
    'name'                                                                      => 'required',
    'email'                                                                     => 'required|unique:users',
    'password'                                                                  => 'min:6|max:30|confirmed',
    'role_id'                                                                   => 'required',
    
    );
    $errorMessage                                                               = array(

    );


    $validator                                                                  = Validator::make($request->all(), $rules,$errorMessage);
     if ($validator->fails()) 
    {
        return $validator->messages()->toJson();
    }
   
    $users                                                                      = new User;
    $users->name                                                                = $request->Input('name');
    $users->email                                                               = $request->Input('email');
    $users->password                                                            = Hash::make($request->Input('password'));
    $users->role_id                                                             = $request->Input('role_id');
    $users->save();

     // process avatar
     if($request->hasFile('avatar') && $request->file('avatar')->isValid())
    {
    $image                                                                      = $request->file('avatar');
     if(!empty($image) && substr($image->getMimeType(), 0, 5)                    == 'image')
    {
        $avatarName                                                             = uniqid() . $users->id . '.' . 
        $request->file('avatar')->getClientOriginalExtension();

        $request->file('avatar')->move(
        base_path() . '/public/images/users/', $avatarName
        );
        // $img                                                                 = Image::make(base_path() . '/public/images/items/' . $avatarName);
        // $img->resize(100, null, function ($constraint) {
        //     $constraint->aspectRatio();
        // });
        // $img->save();
        $userAvatar                                                             = User::find($users->id);
        $userAvatar->avatar                                                     = $avatarName;
        $userAvatar->save();
    }

    }
     else if ($request->Input('url')                                            != '' && $this->app->isRemoteFileExist($request->Input('url')) == 1)
    {
    $_fileName                                                                  = uniqid() . $users->id;
    $path                                                                       = $request->Input('url');
    $filename = basename($path);
    Image::make($path)->save(base_path() . '/public/images/users/' . $_fileName);
    $userAvatar                                                                 = User::find($users->id);
    $userAvatar->avatar                                                         = $_fileName;
    $userAvatar->save();
    }
    


    
    return $this->api();


    


    }
    catch(\Illuminate\Database\QueryException $e)
    {
        // return redirect('auth/login');
    }


    }


      public function update(Request $request, $id)
    {

     try
    {
    $rules                                                                      = array(
    'name'                                                                      => 'required',
    'email'                                                                     => 'required|unique:users,email,' . $id .'',
    // 'password'                                                                  => 'min:6|max:30|confirmed',
    'role_id'                                                                   => 'required | numeric',
    
    );
    $errorMessage                                                               = array(

    );


    $validator                                                                  = Validator::make($request->all(), $rules,$errorMessage);
     if ($validator->fails()) 
    {
        return $validator->messages()->toJson();
    }
   
    $user                                                                       = User::find($id);
    $user->name                                                                 = $request->Input('name');
    $user->email                                                                = $request->Input('email');
    // $users->password                                                            = Hash::make($request->Input('password'));
    $user->role_id                                                              = $request->Input('role_id');
    $user->save();

    
    
    return $this->api();



    }
    catch(\Illuminate\Database\QueryException $e)
    {
    return response()->json($e,200);
    }


    }

      public function updateAvatar(Request $request, $id)
    {
        // process avatar
         if($request->hasFile('avatar') && $request->file('avatar')->isValid())
        {
        $image                                                                      = $request->file('avatar');
        if(!empty($image) && substr($image->getMimeType(), 0, 5)                    == 'image')
        {
            $avatarName                                                             = uniqid() . $id . '.png' . 
            $request->file('avatar')->getClientOriginalExtension();

            $request->file('avatar')->move(
            base_path() . '/public/images/users/', $avatarName
            );
            // $img                                                                 = Image::make(base_path() . '/public/images/items/' . $avatarName);
            // $img->resize(100, null, function ($constraint) {
            //     $constraint->aspectRatio();
            // });
            // $img->save();
            $userAvatar                                                             = User::find($id);
            $userAvatar->avatar                                                     = $avatarName;
            $userAvatar->save();

            return $this->api();
        }

        }

    }



    public function destroy($id)
    {
    $user                                                  = User::where('id', $id)->delete();
    return $this->api();
    }
    public function auth()
    {
      $auth                                                = User::where('id', Auth::user()->id)->get();
      return response()->json($auth, 201);
    }

     public function api()
    {
        $users                                             = User::orderBy('created_at','desc')->with('role')->get();
        return response()->json($users, 201);
    }

     function isRemoteFileExist($file)
    {
        $feedback                                                                   = 0;
        $external_link                                                              = $file;
        if (@getimagesize($external_link)) {
        $feedback                                                                   =1;
        }

        return $feedback; 
    }

    public function isAdmin()
    {
    if(Auth::check() && strtoupper(Auth::user()->role->name)  == 'ADMIN'){ return Auth::user()->id;}
    return 0;
    }
}
