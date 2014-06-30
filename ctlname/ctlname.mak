# CTLNAME Make File
.SUFFIXES: .c

CTLNAME.EXE: \
  CTLNAME.OBJ \
  CTLNAME.MAK \
  genmidi.lib \
  CTLNAME.DEF
   link386.exe CTLNAME.OBJ /PACKD /NOL /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,CTLNAME.EXE,NUL,genmidi.lib,CTLNAME.DEF;
#debug version
#  link386.exe CTLNAME.OBJ /PACKD /NOL /CO /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,CTLNAME.EXE,NUL,genmidi.lib,CTLNAME.DEF;

{.}.c.obj:
   icc.exe /Tdc /Q /O+ /C /Gh- /Sh- /Ti- /Ts- .\$*.c
#debug version
#  icc.exe /Tdc /Q /Ti /C .\$*.c

!include CTLNAME.DEP
