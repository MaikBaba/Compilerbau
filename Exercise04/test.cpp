int factr (int n) 
{
  double a = 65.0;
  double b = 100.02;
  int x = 10;
  a = 10;
  a++; //= a + 2;
  a--;
  return x;
}

int main() {
	int i ;
	int j = 1;
	double d = 1.0;  //Sven sagt, wir können davon ausgehen, dass rechts auch ein double steht
	bool b = true;
	i = 1;

	while(i == d++) { // Vergleiche integer
		i = 1; // -1 gibt syntax fehler
	}

	if (j) {			// llvm fehler: invalid operand types for cmp, ebenso für i >0
		i=2;
	}else{}

	return i;
}


/* TODO vorwärtsdeklaration -> prototyp 
		vergleiche int und double
*/