# DRUMKEY Make File
.SUFFIXES: .c

DRUMKEY.EXE: \
  DRUMKEY.OBJ \
  DRUMKEY.MAK \
  genmidi.lib \
  DRUMKEY.DEF
   link386.exe DRUMKEY.OBJ /PACKD /NOL /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,DRUMKEY.EXE,NUL,genmidi.lib,DRUMKEY.DEF;
#debug version
#  link386.exe DRUMKEY.OBJ /PACKD /NOL /CO /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,DRUMKEY.EXE,NUL,genmidi.lib,DRUMKEY.DEF;

{.}.c.obj:
   icc.exe /Tdc /Q /O+ /C /Gh- /Sh- /Ti- /Ts- .\$*.c
#debug version
#  icc.exe /Tdc /Q /Ti /C .\$*.c

!include DRUMKEY.DEP
