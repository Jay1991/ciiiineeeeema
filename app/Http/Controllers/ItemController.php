<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\Item;
use Intervention\Image\ImageServiceProvider;
use Intervention\Image\Facades\Image;
class ItemController extends Controller
{
    //

    private $inventory;
    public function __construct()
    { 
        $this->inventory = new InventoryController;                          
    }



     public function index()
    {
    return $this->api();
    }

     public function store(Request $request)
    {

        try
        {
        $rules                    = array(
        'name'                    => 'required',
        'buying_price'            => 'required | numeric',
        'selling_price'           => 'required | numeric',
        'item_type_id'            => 'required',
        'quantity'                => 'required | numeric',
        );
        $errorMessage                                                               = array(

        );

 
        $validator                                                                  = Validator::make($request->all(), $rules,$errorMessage);
        if ($validator->fails()) 
        {
            return $validator->messages()->toJson();
        }
       
        $item                              = new Item;
        $item->name                        = $request->Input('name');
        $item->buying_price                = $request->Input('buying_price');
        $item->selling_price               = $request->Input('selling_price');
        $item->item_type_id                = $request->Input('item_type_id');
        $item->code                        = $request->Input('code');
        $item->barcode                     = $request->Input('barcode');
        $item->isbn                        = $request->Input('isbn');
        $item->size                        = $request->Input('size');
        $item->quantity                    = $request->Input('quantity');
        $item->save();

        // process inventory
        $this->inventory->store($item->quantity,$item->id);
         // process avatar
         if($request->hasFile('avatar') && $request->file('avatar')->isValid())
        {
        $image                                                                      = $request->file('avatar');
        if(!empty($image) && substr($image->getMimeType(), 0, 5)                    == 'image')
        {
            $avatarName                                                             = uniqid() . $item->id . '.' . 
            $request->file('avatar')->getClientOriginalExtension();

            $request->file('avatar')->move(
            base_path() . '/public/images/items/', $avatarName
            );
            // $img                                                                 = Image::make(base_path() . '/public/images/items/' . $avatarName);
            // $img->resize(100, null, function ($constraint) {
            //     $constraint->aspectRatio();
            // });
            // $img->save();
            $userAvatar                                                             = Item::find($item->id);
            $userAvatar->avatar                                                     = $avatarName;
            $userAvatar->save();
        }

        }
        else if ($request->Input('url')                                             != '' && $this->isRemoteFileExist($request->Input('url')) == 1)
        {
        $_fileName                                                                  = uniqid() . $item->id;
        $path                                                                       = $request->Input('url');
        $filename = basename($path);
        Image::make($path)->save(base_path() . '/public/images/items/' . $_fileName);
        $userAvatar                                                                 = Item::find($item->id);
        $userAvatar->avatar                                                         = $_fileName;
        $userAvatar->save();
        }



    
        return $this->api();


        


        }
        catch(\Illuminate\Database\QueryException $e)
        {
            return response()->json($e, 200);
        }

    }

     public function api()
    {
    $items                         = Item::orderBy('created_at', 'desc')
                                   ->with('type')
                                   ->get();
    return response()->json($items, 201);
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
