#include "types.h"
#include "stat.h"
#include "user.h"

//Number of processes to be executed
#define CMDCT 3
int stdout = 1;

int
main(int argc, char * argv[])
{
  int pid, i;

  //array of all of the processes to be executed
  struct
  {
     char * args[2];
  } cmds[CMDCT] = {{{"loop1", 0}}, {{"loop2", 0}}, {{"ss", 0}}};

  for (i = 0; i < CMDCT - 1; i++)
  {
    pid = fork();
    if (pid < 0)
    {
      printf(stdout, "fork failed\n");
      exit();
    } else if (pid == 0)
    {
      if (exec(cmds[i].args[0], cmds[i].args) < 0)
      {
         printf(stdout, "exec %s failed\n", cmds[i].args[0]);
         exit();
      }
    }
    sleep(10);
  }
  //wait for the loop processes to complete
  for (i = 0; i < CMDCT - 1; i++) wait();

  //exec the ss process
  if (exec(cmds[CMDCT - 1].args[0], cmds[CMDCT - 1].args) < 0)
  {
    printf(stdout, "exec %s failed\n", cmds[CMDCT - 1].args[0]);
  }
  
  exit();
}
