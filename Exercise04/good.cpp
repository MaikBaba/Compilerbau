int factr (int n) 
{
  int a = 65;
  a++; //= a + 2;

  if (a)
    return 1 ;
  else 
    return (n * factr(n-1));
}

int main () 
{
  int i = factr(7);
  return 0 ;
}