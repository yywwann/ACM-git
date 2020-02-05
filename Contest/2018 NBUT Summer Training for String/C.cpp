#include<iostream>
#include<string>
using namespace std;
const int MAX=1e3+5;

string Find,s;
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

int ManyKMP(){
    int i=0,j=0;
    int ans=0;
    while(i<s.size()){
        if(j==-1||Find[j]==s[i]){
            i++,j++;
            if(j==Find.size()){
                ans++;
                j=0;
            }
        }
        else j=NEXT[j];
    }
    return ans;
}

int main(){
	while(cin>>s){
		if(s=="#") break;

		cin>>Find;
		getNext();
		cout<<ManyKMP()<<endl;
	}
}