#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

long long virus=1;

void* mult(void* arg) {
  long long *limit_ptr=(long long*) arg;
  long long limit= *limit_ptr;
  for (int i=1;i <=limit; i++) {
    virus *=2;
  }
  pthread_exit(0);
}

int main(int argc, char const *argv[]) {

  int num_args=argc-1;


  pthread_t tids[num_args];
  for (int i = 0; i < num_args; i++) {
    long long limit=atoll(argv[i+1]);
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tids[i],&attr,mult,&limit);
  }
  for(int i=0;i<num_args;i++){
      pthread_join(tids[i],NULL);
  }
  printf("virus: %lld\n", virus );
  return 0;
}
