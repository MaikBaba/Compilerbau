CC = g++
CCFLAGS = -g -W -Wall

FLEX = flex
FLEX_OPTS = -PCPP

BISON = bison
BISON_OPTS = -t -pCPP

OBJS = Absyn.o Lexer.o Parser.o Printer.o TypeChecker.o

.PHONY: clean distclean

all: TestTypeCheckerCPP

clean:
	rm -f *.o TestCPP CPP.aux CPP.log CPP.pdf CPP.dvi CPP.ps CPP

distclean: clean
	rm -f Absyn.C Absyn.H TestTypeChecker.C Parser.C Parser.H Lexer.C TypeChecker.C TypeChecker.H Printer.C Printer.H Makefile CPP.l CPP.y CPP.tex 

TestTypeCheckerCPP: ${OBJS} TestTypeChecker.o
	@echo "Linking TestTypeCheckerCPP..."
	${CC} ${CCFLAGS} ${OBJS} TestTypeChecker.o -o TestTypeCheckerCPP

Absyn.o: Absyn.C Absyn.H
	${CC} ${CCFLAGS} -c Absyn.C

Lexer.C: CPP.l
	${FLEX} -o Lexer.C CPP.l

Parser.C: CPP.y
	${BISON} CPP.y -o Parser.C

Lexer.o: Lexer.C Parser.H
	${CC} ${CCFLAGS} -c Lexer.C

Parser.o: Parser.C Absyn.H
	${CC} ${CCFLAGS} -c Parser.C

Printer.o: Printer.C Printer.H Absyn.H
	${CC} ${CCFLAGS} -c Printer.C

TypeChecker.o: TypeChecker.C TypeChecker.H Absyn.H
	${CC} ${CCFLAGS} -c TypeChecker.C

TestTypeChecker.o: TestTypeChecker.C Parser.H Printer.H TypeChecker.H Absyn.H
	${CC} ${CCFLAGS} -c TestTypeChecker.C

