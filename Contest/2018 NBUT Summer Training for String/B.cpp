#include<iostream>
using namespace std;
const int MAX=1e6+5;


int t;
int n,m;
int Find[MAX],s[MAX];
int NEXT[10*MAX];
void getNext(){
    int i=0,j=NEXT[0]=-1;
    while(i<m){
        if(j==-1||Find[i]==Find[j]){
            i++,j++,NEXT[i]=j;
        }
        else j=NEXT[j];
    }
}

int FirstKMP(){
    int i=0,j=0;
    while(i<n){
        if(j==-1||Find[j]==s[i]){
            i++,j++;
            if(j==m){
                return i-j+1;
            }
        }
        else j=NEXT[j];
    }
    return -1;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&s[i]);
        for(int i=0;i<m;i++) scanf("%d",&Find[i]);
        getNext();
    	printf("%d\n",FirstKMP());
    }
    

    return 0;
}






