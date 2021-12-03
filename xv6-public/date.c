#include "types.h"
#include "user.h"
#include "date.h"

int
main(int argc, char *argv[])
{
  struct rtcdate r;
  
  if(date(&r))
  {
     printf(2, "Erro na chamada de sistema!\n");
     exit();
  }

  printf(1, "%d/%d/%d %d:%d:%d\n", r.day, r.month, r.year, r.hour - 3, r.minute, r.second);

  exit();
}
