#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "loggerutils.h"

struct command
{
  char * long_name;
  char * short_name;
};

void start_server()
{

}

void create_new_project(char * name)
{
  printf("Creating Project: %s", name);

  char cwd [2048];

  if(getcwd(cwd, sizeof(cwd)) != NULL)
  {
    printf("Current working dir: %s\n", cwd);
  }
}

// TODO make sure argv exists!
int main(int argc, char **argv)
{
  if(argc <= 1 || argc > 2)
  {
    fprintf(stderr, "Error: Incorrect arguments supplied. Expected (1 or 2) but received %d\n", argc);
    exit(1);
  }

  struct command commands[3] = {
    { "server",   "s" },
    { "generate", "g" },
    { "new",      "n" }
  };

  if(strcmp(argv[1], commands[0].short_name) == 0 || strcmp(argv[1], commands[0].long_name) == 0)
  {
    start_server(argv[2]);
  }
  else if(strcmp(argv[1], commands[1].short_name) == 0 || strcmp(argv[1], commands[1].long_name) == 0)
  {
    printf("Generate\n");
  }
  else if(strcmp(argv[1], commands[2].short_name) == 0 || strcmp(argv[1], commands[2].long_name) == 0)
  {
    create_new_project(argv[2]);
  }
  else
  {
    log_error(__FILE__, __LINE__, "Unknown pontoons command");
    exit(1);
  }

  return 0;
}
