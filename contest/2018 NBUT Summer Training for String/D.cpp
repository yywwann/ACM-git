#include<iostream>
#include<string>
using namespace std;
const int MAX=1e5+5;

int t;
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
    cin>>t;
    while(t--){
        cin>>Find;
        getNext();
        int len=Find.size();
        int ans=len-NEXT[len];
        if(len==ans) cout<<len<<endl;
        else if(len%ans==0) cout<<0<<endl;
        else cout<<ans-len%ans<<endl;
        
    }
}