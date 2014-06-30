# PGMNAME Make File
.SUFFIXES: .c

PGMNAME.EXE: \
  PGMNAME.OBJ \
  PGMNAME.MAK \
  genmidi.lib \
  PGMNAME.DEF
   link386.exe PGMNAME.OBJ /PACKD /NOL /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,PGMNAME.EXE,NUL,genmidi.lib,PGMNAME.DEF;
#debug version
#  link386.exe PGMNAME.OBJ /PACKD /NOL /CO /PM:VIO /ALIGN:1 /BASE:0x10000 /EXEPACK,PGMNAME.EXE,NUL,genmidi.lib,PGMNAME.DEF;

{.}.c.obj:
   icc.exe /Tdc /Q /O+ /C /Gh- /Sh- /Ti- /Ts- .\$*.c
#debug version
#  icc.exe /Tdc /Q /Ti /C .\$*.c

!include PGMNAME.DEP
