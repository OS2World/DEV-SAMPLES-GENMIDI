# NOTENAME Make File
.SUFFIXES: .c

NOTENAME.EXE: \
  NOTENAME.OBJ \
  NOTENAME.MAK \
  genmidi.lib \
  NOTENAME.DEF
   link386.exe NOTENAME.OBJ /PACKD /NOL /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,NOTENAME.EXE,NUL,genmidi.lib,NOTENAME.DEF;
#debug version
#  link386.exe NOTENAME.OBJ /PACKD /NOL /CO /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,NOTENAME.EXE,NUL,genmidi.lib,NOTENAME.DEF;

{.}.c.obj:
   icc.exe /Tdc /Q /O+ /C /Gh- /Sh- /Ti- /Ts- .\$*.c
#debug version
#  icc.exe /Tdc /Q /Ti /C .\$*.c

!include NOTENAME.DEP
