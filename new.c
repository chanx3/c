#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
  char n1[]="abbaabaabcaba";
  char n2[]="aba";
  int m= strlen(n1);
  int n= strlen(n2);
  for (int j=0;j<m-n+1;j++ ){
    int i;
    for(i=0;i<n;i++){
      if(n1[j+i]!=n2[i]){
        break;
      }
    }
    if(i==n){
      printf("pattern found at %d\n",j);

    }

  }



  return 0;
}
