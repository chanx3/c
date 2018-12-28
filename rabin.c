#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define d 256

void search(char pat[], char txt[], int q){
  int m= strlen(pat);
  int n=strlen(txt);
  int s=1;
  int phash=0;
  int thash=0;
  int i,j;
  for(i=0;i<m-1;i++){
    s=(s*d)%q;
  }
  for(i=0;i<m;i++){
    phash=(d*phash+pat[i])%q;
    thash=(d*thash+txt[i])%q;
  }
  for(i=0;i<n-m;i++){
    if(phash==thash){
      for(j=0;j<m;j++){
        if(txt[i+j]!=pat[j]){
          break;
        }
      }
      if(j==m){
        printf("pattern found at %d\n", i);
      }
    }
    if(i<n-m){
      thash=(d*(thash-txt[i]*s)+txt[i+m])%q;
      if(thash<0){
        thash=thash+q;
      }
    }
  }
}
int main(){
  char txt[]="aaababcd";
  char pat[]="ba";
  int q=99;
  search(pat,txt,q);
  return 0;
}
