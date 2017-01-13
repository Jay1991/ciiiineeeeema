with (document) {
	write("<style type='text/css'>");
	write(".msghead {margin-top:2pt;margin-bottom:2pt;}");
	write(".msgbody {margin-left:20px;margin-top:2pt;margin-bottom:2pt;display:none;}");
	write("</style>");
}

function expandIt(el) {
  var whichEl = document.getElementById(el);
  var whichClose = document.getElementById(el + '_close');
  var whichOpen = document.getElementById(el + '_open');
  if (whichEl.style.display != "block") {
    whichEl.style.display = "block";
    whichClose.style.display = "none";
    whichOpen.style.display = "inline";
  }
  else {
    whichEl.style.display = "none";
    whichClose.style.display = "inline";
    whichOpen.style.display = "none";
  }

}

function mf_text(id, msg) {
	document.write('<img border="0" src="closed.gif" width="14" height="14" id="'+id+'_close"><img border="0" src="open.gif" style="display:none" width="14" height="14" id="'+id+'_open">&nbsp;<a class=lb href="#" onClick="expandIt(\''+id+'\');return false;">'+msg+'</a> ');
}

function mf_contents(id, msg) {
	document.write('<img border="0" src="closedred.gif" width="14" height="14" id="'+id+'_close"><img border="0" src="openred.gif" style="display:none" width="14" height="14" id="'+id+'_open">&nbsp;<a class=lb href="#" onClick="expandIt(\''+id+'\');return false;">'+msg+'</a> ');
}

function result_color(zfp)
{
    if (zfp.errorCode)
        result.style.color = "red";
    else
        result.style.color = "black";
}