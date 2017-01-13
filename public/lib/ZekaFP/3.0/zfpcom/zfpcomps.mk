
zfpcomps.dll: dlldata.obj zfpcom_p.obj zfpcom_i.obj
	link /dll /out:zfpcomps.dll /def:zfpcomps.def /entry:DllMain dlldata.obj zfpcom_p.obj zfpcom_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del zfpcomps.dll
	@del zfpcomps.lib
	@del zfpcomps.exp
	@del dlldata.obj
	@del zfpcom_p.obj
	@del zfpcom_i.obj
