#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signal) {
  if (signal == SIGINT) {
    char sig[] = "============Ended============\nThis has been interrupted! How could this happen to me?";
    printf("%s\n", sig);
    exit(1);
  }

  if (signal == SIGUSR1) {
    char sig[] = "I cannot be stopped puny hooman!";
    printf("%s\n", sig);
    printf("Parent is: %i\n", getppid());
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  printf("%s\n", "===========Starting===========");
  while (1) {
    sleep(1);
    printf("Pid: %i\n", getpid());
  }
}
