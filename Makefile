# this is a comment
SRC=zclunit.cpp zclib.asm zcomponent.cpp zobject.cpp zcommand.cpp funcs.asm fdata.asm
COBJ=$(SRC:.cpp=.o) # replaces the .cpp from SRC with .o
OBJ=$(COBJ:.asm=.o) # replaces the .asm from SRC with .o
EXE=zcl.dll
RES=$(EXE:.dll=.res)
DEF=$(EXE:.dll=.def)
#LIB=import32.lib cw32i.lib sdl.lib
LIB=sdl.lib msvcrt.lib
#BPI=
IPATH=c:\progra~1\sdl\include\sdl
LPATH=c:\progra~1\sdl\lib

#AS=nasm
AS=tasm32
#CC=c:\\progra~1\borland\bcc55\bcc32
CC=bcc32
LINK=ilink32
#AFLAGS=-f coff -O2
#AFLAGS=-E test.err -f obj -O2 -g -F borland
AFLAGS = /la /ml /c /m3
CFLAGS=-c
OFLAGS=-d -O1 -r -u-
LLFLAGS=-m -M -s -v   #Link loggings flags with ilink32
LFLAGS=-c -Tpd -Gi -aa -Gn -Gl -b:0x340000 #Link flags with ilink32
RM=rm

# combined w/ next line will compile recently changed .asm files
%.o: %.asm
	$(AS) $(AFLAGS) $< $@ $(<:.asm=.lst)
#	 $(AS) $(AFLAGS) -l $(<:.asm=.lst) -o $@ $<

%.o: %.cpp
	$(CC) $(CFLAGS) $(OFLAGS) -I$(IPATH) -o $@ $<

.PHONY : all	 # .PHONY ignores files named all
all: $(EXE)	 # all is dependent on $(EXE) to be complete

$(EXE): $(OBJ) $(DEF) $(RES) # $(EXE) is dependent on all of the files in $(OBJ) to exist
	$(LINK)  $(LFLAGS) $(LLFLAGS) -L$(LPATH) $(OBJ) $(BPI) ,$@,, $(LIB), $(DEF), $(RES)

.PHONY : clean	 # .PHONY ignores files named clean
clean:
	-$(RM) -f $(OBJ) *.lst	  # '-' causes errors not to exit the process