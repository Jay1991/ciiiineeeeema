with (document) {
	write("<style type='text/css'>");
	write(".msghead {font-size:12pt;font-family:Arial,Helvetica;margin-top:2pt;margin-bottom:2pt;}");
	write(".msgbody {margin-left:10px;font-size:10pt;font-family:Arial,Helvetica;margin-top:2pt;margin-bottom:2pt;display:none;}");
	write("</style>");
}

function expandIt(el) {
  var whichEl = document.getElementById(el);
  if (whichEl.style.display != "block") {
    whichEl.style.display = "block";
  }
  else {
    whichEl.style.display = "none";
  }
}

function mf_text(id,msg) {
	document.write('<a class=lb href="#" onClick="expandIt(\''+id+'\');return false;">'+msg+'</a> ');
}
