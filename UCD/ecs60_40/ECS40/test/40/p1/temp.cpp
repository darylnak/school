int main()
{
  char *ptr = new char[100];
  int count = 3;

  while(count != 10)
  {
    if (++ count == 10)
     count = 3;
  }
  return 0;
}
