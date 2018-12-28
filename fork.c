#include <stdio.h>
#include<sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  for (size_t i = 0; i < 3; i++) {
    fork();
    printf("i love you\n");
  }
  return 0;
}
