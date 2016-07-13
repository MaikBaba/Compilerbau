int factr (int n) 
{
  double a = 65;
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
	bool b = 1;
	i = 1;

	while(i == j) { // Vergleiche integer
		i = 1; // -1 gibt syntax fehler
	}

	//if (i >= 0) {			// llvm fehler: invalid operand types for cmp, ebenso für i >0
	if (true) {			// llvm fehler: invalid operand types for cmp, ebenso für i >0
		int x = factr(i);
	}
	else {}		// if ohne else gibt syntaxfehler
	if (d == 1) {
		d++;
	}else{}

	return i;
}


// TODO vorwärtsdeklaration -> prototyp
