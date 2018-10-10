
MFCApplication1ps.dll: dlldata.obj MFCApplication1_p.obj MFCApplication1_i.obj
	link /dll /out:MFCApplication1ps.dll /def:MFCApplication1ps.def /entry:DllMain dlldata.obj MFCApplication1_p.obj MFCApplication1_i.obj \
		kernel32.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
.c.obj:
	cl /c /Ox /DREGISTER_PROXY_DLL \
		$<

clean:
	@del MFCApplication1ps.dll
	@del MFCApplication1ps.lib
	@del MFCApplication1ps.exp
	@del dlldata.obj
	@del MFCApplication1_p.obj
	@del MFCApplication1_i.obj
