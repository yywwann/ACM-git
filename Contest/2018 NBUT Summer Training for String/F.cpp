#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAX=1e6+5;

int n;
char Find[MAX];
int NEXT[MAX];

void getNext(){
    int i=0,j=NEXT[0]=-1;
    int len=strlen(Find);
    while(i<len){
        if(j==-1||Find[i]==Find[j]){
            i++,j++,NEXT[i]=j;
        }
        else j=NEXT[j];
    }
}



int main(){
    while(gets(Find)){
        if(Find[0]=='.') break;
      getNext();
      int len=strlen(Find);
      int ans=len-NEXT[len];
      if(len%ans==0) cout<<len/ans<<endl;
      else cout<<1<<endl;
    }
}