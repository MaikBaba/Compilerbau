int factr (int n) 
{
  double a = 65.0;	
  a--; //= a + 2;
  a++;

  if (true)
    return 1 ;
  else 
    return (n * factr(n-1));
}

int main () 
{
  int i = factr(7);

  while(i == true) {
	i = false;
  }

  return 0 ;

}	
