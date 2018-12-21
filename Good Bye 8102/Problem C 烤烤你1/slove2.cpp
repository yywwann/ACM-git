#include<iostream>
using namespace std;
 
int main()
{
    int T,n;
    cin>>T;
    int f[10010];
    while(T--){
        cin>>n;
        int ans=0;
        f[1]=1;
        f[2]=1;
        for(int i=3;i<10010;i++){
            f[i]=f[i-1]+f[i-2];
        }
        ans=f[n]*(f[n+2]+f[n])-f[n+1]*(f[n+1]+f[n-1]);
        cout<<ans<<endl;
    }
    return 0;
}