#include "types.h"
#include "user.h"

void show_result(int num_ticks, char *tipo)
{
  int segs = num_ticks / 100;
  int resto_segs = num_ticks % 100;

  printf(1, "%s\t%d.", tipo, segs);
  if(resto_segs < 10)
  {
    printf(1, "00%ds\n", resto_segs);
  }
  else if(resto_segs >= 10 && resto_segs < 100)
  {
    printf(1, "0%ds\n", resto_segs);
  }
  else
  {
    printf(1, "%ds\n", resto_segs);
  }
}

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    printf(2, "Erro: uso inválido do comando 'time'\n");
    exit();
  }
  int pid;
  int start_rticks, end_rticks;
  int rticks, uticks, sticks;
  pid = fork();
  start_rticks = uptime();
  time();
  if(pid == 0)
  {
    contabilizar_tempo();
    exec(argv[1], argv + 1);
    contabilizar_tempo();
    exit();
  }
  else
  {
    wait();
  }
  sticks = time();
  end_rticks = uptime();
  rticks = end_rticks - start_rticks;
  show_result(rticks, "real");
  uticks = rticks - sticks;
  show_result(uticks, "user");
  show_result(sticks, "sys");
  exit();
}
