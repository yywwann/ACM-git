#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int num=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>s[num]) num=i;
        }
        s=s.substr(num)+s.substr(0,num);
        cout<<s<<endl;
    }
    return 0;
}