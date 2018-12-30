#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define PI acos(-1)
#define eps 1e-10
#define mem(x) memset(x,0,sizeof(x))
#define _for(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define __for(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)

const int INF=0x3f3f3f3f;
const int MAX=1e5+5;
const int MOD=1e9+7;


int t;
char Find[MAX*10];
char s[MAX*10];
int NEXT[10*MAX];
int lenFind,lens;
void getNext(){
    int i=0,j=NEXT[0]=-1;
    while(i<lenFind){
        if(j==-1||Find[i]==Find[j]){
            i++,j++,NEXT[i]=j;
        }
        else j=NEXT[j];
    }
}

int ManyKMP(){
    int i=0,j=0;
    int ans=0;
    while(i<lens){
        if(j==-1||Find[j]==s[i]){
            i++,j++;
            if(j==lenFind){
                ans++;
                j=NEXT[j];
            }
        }
        else j=NEXT[j];
    }
    return ans;
}

int main(){
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(Find);
        gets(s);
        lenFind=strlen(Find);
        lens=strlen(s);
        getNext();
        printf("%d\n",ManyKMP());
    }
    

    return 0;
}






