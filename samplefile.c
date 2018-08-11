#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  /*
  char *filename;

  if (argc == 1)
  {
    filename = "index.c";
    printf("We passed in no arguments \n");
  }
  else if (argc == 2)
  {
    filename = argv[1];
    printf("We passed in the file %s \n", filename);
  }
  else
  {
    fprintf(stderr, "Too amny arguments! Usage: ./index2 [yourfilename]\n");
    exit(1);
  }
  */
  char *directory_name;

  if (argc == 1)
  {
    directory_name = ".";
  }
  else if (argc == 2)
  {
    directory_name = argv[1];
  }
  else
  {
    fprintf(stderr, "Too many arguments! Usage: ./index2 [your directory name]\n");
    exit(1);
  }

  /*
  DIR *directory = opendir(".");
  char *result = directory == NULL ? "Did not open" : "Succeded!"; // ternary operator
  printf("Testing opening a directory:  %s\n", result);
  closedir(directory);
  */
  DIR *directory = opendir(directory_name);

  // check if directory is open
  if (directory == NULL)
  {
    fprintf(stderr, "The directory open error");
  }

  struct dirent *ent;

  while ((ent = readdir(directory)) != NULL)
  {
    char path[20000];
    struct stat stat_buf;

    // we need the full path
    snprintf(path, sizeof(path), "%s/%s", directory_name, ent->d_name);

    if (stat(path, &stat_buf) == -1)
    {
      fprintf(stderr, "Failed to show the stats for %s\n", path);
      exit(2);
    }

    if (stat_buf.st_mode & S_IFREG)
    {
      // print the file name and its size in bytes
      printf("%20lld %s\n", stat_buf.st_size, ent->d_name);
    }
    else if (stat_buf.st_mode & S_IFDIR)
    {
      // director name
      printf("%20lld %s\n", "<DIR>", ent->d_name);
    }
    else
    {
      printf("%10s %s \n", " ", ent->d_name);
    }
  }

  closedir(directory);

  /*
  struct stat file_stat;

 
  while (argc-- > 1)
  {
    if (lstat(argv[argc], &file_stat) == -1)
      fprintf(stderr, "%s\n", strerror(errno));
    else
    {
      fprintf(stdout, "Links\tUid\tGid\tSize\tName\n");
      fprintf(stdout, "%u\t%u\t%u\t%u\t%s\n", file_stat.st_nlink,
              file_stat.st_uid, file_stat.st_gid, file_stat.st_size,
              argv[argc]);
    }
  }

  */
  return 0;
}