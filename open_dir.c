#include <stdio.h>
#include <dirent.h> // helps you open a directory

int main(void)
{
  DIR *directory = opendir(".");
  char *result = directory == NULL ? "Did not open" : "Succeded!"; // ternary operator
  printf("Testing opening a directory:  %s\n", result);
  closedir(directory);
  return 0;
}