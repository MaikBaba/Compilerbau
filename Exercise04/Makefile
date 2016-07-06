CC = g++
CCFLAGS = -g -W -Wall -std=c++11

FLEX = flex
FLEX_OPTS = -PCPP

BISON = bison
BISON_OPTS = -t -pCPP

OBJS = Absyn.o Lexer.o Parser.o Printer.o CGTest.o CodeGen.o 

.PHONY: clean distclean

all: TestCodeGenCPP

clean:
	rm -f *.o TestCodeGenCPP CPP.aux CPP.log CPP.pdf CPP.dvi CPP.ps CPP

TestCodeGenCPP: ${OBJS}
	@echo "Linking TestCodeGenCPP..."
	${CC} ${CCFLAGS} ${OBJS} -o TestCodeGenCPP

Absyn.o: Absyn.C Absyn.H
	${CC} ${CCFLAGS} -c Absyn.C

Lexer.C: CPP.l
	${FLEX} -oLexer.C CPP.l

Parser.C: CPP.y
	${BISON} CPP.y -o Parser.C

Lexer.o: Lexer.C Parser.H
	${CC} ${CCFLAGS} -c Lexer.C

Parser.o: Parser.C Absyn.H
	${CC} ${CCFLAGS} -c Parser.C

Printer.o: Printer.C Printer.H Absyn.H
	${CC} ${CCFLAGS} -c Printer.C

CodeGen.o: CodeGen.C CodeGen.H Absyn.H
	${CC} ${CCFLAGS} -c -I /usr/local/lib/llvm-3.8/include CodeGen.C

CGTest.o: CGTest.C Parser.H Printer.H Absyn.H CodeGen.H
	${CC} ${CCFLAGS} -c -I /usr/local/lib/llvm-3.8/include -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS CGTest.C


