#include<iostream>
#include<string>
using namespace std;
const int MAX=1e6+5;

int n;
string Find;
int NEXT[MAX];

void getNext(){
    int i=0,j=NEXT[0]=-1;
    while(i<Find.size()){
        if(j==-1||Find[i]==Find[j]){
            i++,j++,NEXT[i]=j;
        }
        else j=NEXT[j];
    }
}



int main(){
    int t=1;
    while(cin>>n){
      if(n==0) break;

      cin>>Find;
      getNext();
      cout<<"Test case #"<<t++<<endl;
      for(int i=2;i<=n;i++){
        if(NEXT[i]==0||NEXT[i]==-1) continue;
        int j=i-NEXT[i];
        if(i%j==0) cout<<i<<' '<<i/j<<endl;
      }cout<<endl;
    }
}