CC = g++
CCFLAGS = -g -W -Wall -std=c++11

FLEX = flex
FLEX_OPTS = -PCPP

BISON = bison
BISON_OPTS = -t -pCPP

OBJS = Absyn.o Lexer.o Parser.o Printer.o TypeChecker.o TypeException.o Env.o TCTest.o 

.PHONY: clean distclean

all: TestCodeGenCPP

clean:
	rm -f *.o TestCodeGenCPP CPP.aux CPP.log CPP.pdf CPP.dvi CPP.ps CPP

distclean: clean
	rm -f Absyn.C Absyn.H Test.C Parser.C Parser.H Lexer.C Skeleton.C Skeleton.H Printer.C Printer.H Makefile CPP.l CPP.y CPP.tex 

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

TypeChecker.o: TypeChecker.C TypeChecker.H Absyn.H Env.H FunType.H
	${CC} ${CCFLAGS} -c TypeChecker.C
	
TypeException.o: TypeException.C TypeException.H
	${CC} ${CCFLAGS} -c TypeException.C

CodeGen.o: CodeGen.C CodeGen.H
	${CC} ${CCFLAGS} -c -I /usr/local/lib/llvm-3.8/include CodeGen.H
	
Env.o: Env.C Env.H Absyn.H FunType.H TypeException.H
	${CC} ${CCFLAGS} -c Env.C

TCTest.o: TCTest.C Parser.H Printer.H Absyn.H TypeChecker.H TypeException.H CodeGen.H
	${CC} ${CCFLAGS} -c -I /usr/local/lib/llvm-3.8/include TCTest.C


