# DRUMNUM Make File
.SUFFIXES: .c

DRUMNUM.EXE: \
  DRUMNUM.OBJ \
  DRUMNUM.MAK \
  genmidi.lib \
  DRUMNUM.DEF
   link386.exe DRUMNUM.OBJ /PACKD /NOL /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,DRUMNUM.EXE,NUL,genmidi.lib,DRUMNUM.DEF;
#debug version
#  link386.exe DRUMNUM.OBJ /PACKD /NOL /CO /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,DRUMNUM.EXE,NUL,genmidi.lib,DRUMNUM.DEF;

{.}.c.obj:
   icc.exe /Tdc /Q /O+ /C /Gh- /Sh- /Ti- /Ts- .\$*.c
#debug version
#  icc.exe /Tdc /Q /Ti /C .\$*.c

!include DRUMNUM.DEP
