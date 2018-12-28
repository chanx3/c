#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define noc 256


int max (int a, int b){return(a>b)? a:b;}
void bdc(char  *str, int size, int bc[noc]) {
  int i;
  for (i=0;i<noc;i++){
    bc[i]=-1;
  }
  for(i=0;i<size;i++){
    bc[(int) str[i]]=i;
  }
}
void search(char *txt , char *pat) {
  int m =strlen(pat);
  int n= strlen(txt);
  int bcc[noc];

  bdc(pat,m,bcc);
  int s=0;
  while (s<=(n-m)) {
    int j=m-1;
    while(j>=0 && pat[j]==txt[s+j]){
      j--;
    }
    if(j<0){
      printf("pattern found\n");
      s+=(s+m<n)? m-bcc[txt[s+j]] : 1;
    }
    else{
      s+= max(1, j-bcc[txt[s+j]]);
    }
  }

}
int main() {
  char txt[]="abbaabcdab";
  char pat[]="ab";
  search(txt, pat);

  return 0;
}
