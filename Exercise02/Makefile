all:
	happy -gca ParMyCPP.y
	alex -g LexMyCPP.x
	ghc --make TestMyCPP.hs -o TestMyCPP

clean:
	-rm -f *.log *.aux *.hi *.o *.dvi

distclean: clean
	-rm -f DocMyCPP.* LexMyCPP.* ParMyCPP.* LayoutMyCPP.* SkelMyCPP.* PrintMyCPP.* TestMyCPP.* AbsMyCPP.* TestMyCPP ErrM.* SharedString.* ComposOp.* myCPP.dtd XMLMyCPP.* Makefile*
	

