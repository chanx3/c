#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int x;
  for (x=0;x<3 ;x++) {
    fork();
    printf("x\n");
    printf("y\n");
  }


  return 0;
}
