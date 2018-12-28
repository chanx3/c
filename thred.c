#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* my(void *vargp){
  sleep(1);
  printf("yeh\n" );
}

int main(int argc, char const *argv[]) {
  pthread_t thread_id;
  printf("before\n");
  pthread_create(&thread_id,NULL,my,NULL);
  pthread_join(thread_id,NULL);
  printf("after\n");
  exit(0);
}
