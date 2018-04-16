#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char * argv[])
{
  //make the process do nothing for awhile
  int i, max = 0x7ffffff;
  for (i = 0; i < max; i++);
  exit();
}
