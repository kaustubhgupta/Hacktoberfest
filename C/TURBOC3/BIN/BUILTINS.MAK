#
# Turbo C++ - (C) Copyright 1992 by Borland International
# 
CC = TCC
AS = TASM 
PASCAL = TPC
.asm.obj:
      $(AS) $(AFLAGS) $&.asm

.c.exe:
      $(CC) $(CFLAGS) $&.c

.c.obj:
      $(CC) $(CFLAGS) /c $&.c

.cpp.obj:
      $(CC) $(CFLAGS) /c $&.cpp

.pas.exe:
      $(PASCAL) $(PFLAGS) $&.pas


.SUFFIXES: .exe .obj .asm .c .cpp .pas  
