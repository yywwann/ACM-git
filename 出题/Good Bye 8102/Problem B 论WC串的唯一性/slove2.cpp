#include<iostream>
#include<cstdio>
#include<map>
#include<stack>
#include<cstring>
#include<cmath>
#include<algorithm> 
using namespace std;
long long t,n,a[100005];
char s[100005]={};
int main()
{
    cin>>t;
    while (t--){
        cin>>s;
        int len=strlen(s);
        long long ans=0;
        a[0]=-1;n=0;
        for (int i=0;i<len-1;i++)
            if (s[i]=='w'&&s[i+1]=='c')
                a[++n]=i;
        a[++n]=len-1;
        for (int i=1;i<n;i++)
            ans+=(a[i]-a[i-1])*(a[i+1]-a[i]);
        cout<<ans<<endl;
    }
    return 0;
}