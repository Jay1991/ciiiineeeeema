<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\Setting;

use Intervention\Image\ImageServiceProvider;
use Intervention\Image\Facades\Image;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;

use Mike42\Escpos\PrintConnectors\FilePrintConnector;
use Mike42\Escpos\Printer;
use Mike42\Escpos\PrintConnectors\NetworkPrintConnector;
use Mike42\Escpos\EscposImage;

class SettingController extends Controller
{
    //


     public function __construct()
    {
        //blockio init
    }


     public function index()
    {
      return $this->api();
    }

     public function show($id)
    {
      $setting                                                               = Setting::find($id);
      return $setting;
    }

     public function update(Request $request, $id)
    {
    	return $request->Input('app_name');
        $settings                                                             = Setting::find($id);
        // $settings->languange = Input::get('languange');
        $settings->app_name                                                   = $request->Input('app_name');
        $settings->email                                                      = $request->Input('email');
        $settings->phone                                                      = $request->Input('phone');
        $settings->location                                                   = $request->Input('location');
        // $settings->currency_symbol                                                = $request->Input('currency_symbol');
        $settings->save();

        return $this->api();
    }

     public function api()
    {
    $setting                                                                  = Setting::all();
    return response()->json($setting,201);
    }

     public function _put(Request $request, $id)
    {
    $settings                               = Setting::find($id);
    // $settings->languange = Input::get('languange');
    $settings->app_name                     = $request->Input('app_name');
    $settings->email                        = $request->Input('email');
    $settings->phone                        = $request->Input('phone');
    $settings->location                     = $request->Input('location');
    $settings->currency_symbol 	            = $request->Input('currency_symbol');
    $settings->vat_percentage               = $request->Input('vat_percentage');
    $settings->postal_address               = $request->Input('postal_address');
    $settings->tin                          = $request->Input('tin');
    $settings->vrn                          = $request->Input('vrn');
    $settings->uin                          = $request->Input('uin');
    $settings->zno                          = $request->Input('zno');
    $settings->save();


     // process avatar
     if($request->hasFile('logo') && $request->file('logo')->isValid())
    {
    $image                                                                      = $request->file('logo');
    if(!empty($image) && substr($image->getMimeType(), 0, 5)                    == 'image')
    {
        $avatarName                                                             = uniqid() . $id . '.png' . 
        $request->file('logo')->getClientOriginalExtension();

        $request->file('logo')->move(
        base_path() . '/public/images/', $avatarName
        );
        $img                                                                 = Image::make(base_path() . '/public/images/' . $avatarName);
        $img->resize(100, null, function ($constraint) {
            $constraint->aspectRatio();
        });
        $img->save();
        $userAvatar                                                             = Setting::find($id);
        $userAvatar->logo                                                       = $avatarName;
        $userAvatar->save();
    }

    }
    else if ($request->Input('url')                                             != '' && $this->isRemoteFileExist($request->Input('url')) == 1)
    {
    $_fileName                                                                  = uniqid() . $id . '.png';
    $path                                                                       = $request->Input('url');
    $filename = basename($path);
    Image::make($path)->save(base_path() . '/public/images/' . $_fileName);
    $userAvatar                                                                 = Setting::find($id);
    $userAvatar->logo                                                           = $_fileName;
    $userAvatar->save();
    }


    return $this->api();

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
}
