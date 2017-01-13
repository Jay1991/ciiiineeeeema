<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\Http\Requests;
use App\Item;
use App\ItemType;
use Intervention\Image\ImageServiceProvider;
use Intervention\Image\Facades\Image;
class MovieController extends Controller
{
    //

    private $app;
    private $auth;
    private $type;
    public function __construct()
    {
        $this->app   = new AppController;
        $this->temp  = new DateUserController;
        $this->type  = new ItemTypeController;
    }


    public function index()
    {

    }

    public function store(Request $request)
    {
        try
        {
        $rules                                                                      = array(
        'name'                                                                      => 'required',
        'parental_guidance_id'                                                      => 'required',
        'director_id'                                                               => 'required',
        'director_fee'                                                              => 'required | numeric'
        );
        $errorMessage                                                               = array(

        );

 
        $validator                                                                  = Validator::make($request->all(), $rules,$errorMessage);
        if ($validator->fails()) 
        {
           
            return $validator->messages()->toJson();
        }




        $item                                                                       = Item::find($request->Input('movie_id'));
        $item->name                                                                 = $request->Input('name');
        $item->item_type_id                                                         = $this->type->show('movie')->id;
        $item->parental_guidance_id                                                 = $request->Input('parental_guidance_id');
        $item->director_id                                                          = $request->Input('director_id');
        $item->director_fee                                                         = (float)$request->Input('director_fee');
        $item->status                                                               = true;
        $item->save();



        // $this->temp->temp($item->id);

        if($request->hasFile('avatar') && $request->file('avatar')->isValid())
        {

        $image                                                                      = $request->file('avatar');
        if(!empty($image) && substr($image->getMimeType(), 0, 5)                    == 'image')
        {
        $avatarName                                                                 = uniqid() . $item->id . '.' . 
        $request->file('avatar')->getClientOriginalExtension();

        $request->file('avatar')->move(
        base_path() . '/public/images/items/', $avatarName
        );
        $userAvatar                                                                 = Item::find($item->id);
        $userAvatar->avatar                                                         = $avatarName;
        $userAvatar->save();
        }

        }
        else if ($request->Input('url')                                            != '' && $this->app->isRemoteFileExist($request->Input('url')) == 1)
        {

        $_fileName                                                                 = uniqid() . $item->id;
        $path                                                                      = $request->Input('url');
        $filename                                                                  = basename($path);
        Image::make($path)->save(base_path() . '/public/images/items/' . $_fileName);
        $tempAvatar                                                                = Item::find($item->id);
        $tempAvatar->avatar                                                        = $_fileName;
        $tempAvatar->save();
        }



        return $this->api();

        }
        catch(\Illuminate\Database\QueryException $e)
        {
            return Redirect::to('auth/login');
        }
    }

     public function update(Request $request,$id)
    {
        try
        {
        $rules                                                                      = array(
        // 'name'                                                                      => 'required',
        // 'parental_guidance_id'                                                      => 'required',
        // 'director_id'                                                               => 'required',
        'director_fee'                                                              => 'required | numeric'
        );
        $errorMessage                                                               = array(

        );

 
        $validator                                                                  = Validator::make($request->all(), $rules,$errorMessage);
        if ($validator->fails()) 
        {
           
            return $validator->messages()->toJson();
        }

        $item                                                                       = Item::find($id);
        $item->name                                                                 = $request->Input('name');
        // $item->item_type_id                                                         = $this->type->show('movie')->id;
        // $item->parental_guidance_id                                                 = $request->Input('parental_guidance_id');
        // $item->director_id                                                          = $request->Input('director_id');
        $item->director_fee                                                         = (float)$request->Input('director_fee');
        // $item->status                                                               = true;
        $item->save();


        return $this->api();

        }
        catch(\Illuminate\Database\QueryException $e)
        {
            return response()->jason($e,200);
        }
    }


     public function show()
    {
    $movie                                                                          = Item::where('user_id', Auth::user()->id)
                                                                                    ->where('status',false)
                                                                                    ->where('item_type_id',$this->type->show('movie')->id)
                                                                                    ->with('type')
                                                                                    ->with('director')
                                                                                    ->with('guidance')
                                                                                    ->first(); 
    return response()->json($movie, 201);

    }

     public function add()
    {
    if($this->isAlreadyExist() != 0) return $this->show();
    $movie                                                                          = new Item;
    $movie->status                                                                  = false;
    $movie->item_type_id                                                            = $this->type->show('movie')->id;
    $movie->user_id                                                                 = Auth::user()->id;
    $movie->save();

    return $this->show();

    }

     public function destroy($id)
    {
        $item         = Item::where('id', $id)->delete();
        return $this->api();
    }


     public function api()
    {
        $item_type                                                                  = ItemType::where('name', 'like', '%' . 'movie' . '%')->with('item')
                                                                                    ->first();
        $movies                                                                     = Item::where('item_type_id', $item_type->id)
                                                                                    ->orderBy('created_at','desc')
                                                                                    ->with('type')
                                                                                    ->with('director')
                                                                                    ->with('guidance')
                                                                                    ->get();                             
        return response()->json($movies, 201);
    }

     public function isAlreadyExist()
    {
     $movieLength                                 = Item::where('user_id', Auth::user()->id)
                                                  ->where('status',false)
                                                  ->where('item_type_id',$this->type->show('movie')->id)
                                                  ->count(); 
     if($movieLength == 0) return 0;return 1;   
    }

     public function seller()
    {
    
    // $movie                                         = new DateUserController;
    // return $movie->load();

    $movie                                        = Item::where('item_type_id',$this->type->show('movie')->id)
                                                  ->where('status',true)
                                                  ->orderBy('created_at','desc')
                                                  ->take(40)
                                                  ->get();
    return response()->json($movie, 201);

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
            base_path() . '/public/images/items/', $avatarName
            );
            // $img                                                                 = Image::make(base_path() . '/public/images/items/' . $avatarName);
            // $img->resize(100, null, function ($constraint) {
            //     $constraint->aspectRatio();
            // });
            // $img->save();
            $userAvatar                                                             = Item::find($id);
            $userAvatar->avatar                                                     = $avatarName;
            $userAvatar->save();

            return $this->api();
        }

        }

    }
    


}
