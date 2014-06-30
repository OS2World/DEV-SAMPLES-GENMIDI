# CTLNUM Make File
.SUFFIXES: .c

CTLNUM.EXE: \
  CTLNUM.OBJ \
  CTLNUM.MAK \
  genmidi.lib \
  CTLNUM.DEF
   link386.exe CTLNUM.OBJ /PACKD /NOL /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,CTLNUM.EXE,NUL,genmidi.lib,CTLNUM.DEF;
#debug version
#  link386.exe CTLNUM.OBJ /PACKD /NOL /CO /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,CTLNUM.EXE,NUL,genmidi.lib,CTLNUM.DEF;

{.}.c.obj:
   icc.exe /Tdc /Q /O+ /C /Gh- /Sh- /Ti- /Ts- .\$*.c
#debug version
#  icc.exe /Tdc /Q /Ti /C .\$*.c

!include CTLNUM.DEP
