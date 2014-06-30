# PGMNUM Make File
.SUFFIXES: .c

PGMNUM.EXE: \
  PGMNUM.OBJ \
  PGMNUM.MAK \
  genmidi.lib \
  PGMNUM.DEF
   link386.exe PGMNUM.OBJ /PACKD /NOL /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,PGMNUM.EXE,NUL,genmidi.lib,PGMNUM.DEF;
#debug version
#  link386.exe PGMNUM.OBJ /PACKD /NOL /CO /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,PGMNUM.EXE,NUL,genmidi.lib,PGMNUM.DEF;

{.}.c.obj:
   icc.exe /Tdc /Q /O+ /C /Gh- /Sh- /Ti- /Ts- .\$*.c
#debug version
#  icc.exe /Tdc /Q /Ti /C .\$*.c

!include PGMNUM.DEP
