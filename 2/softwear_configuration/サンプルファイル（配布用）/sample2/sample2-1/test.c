#include <stdio.h>


int main()
{

  char a[] = "Matsuda";
  char* p;
  
  p = a;
  for(p = a; *p != '\0'; p++)
  {
    printf("*p = %c\n", *p);
  }

}