#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("This is whats in the argc: %d\n", argc);

  for (int i = 0; i < argc; i++)
  {
    printf("- %s \n", argv[i]);
  }
  return 0;
}