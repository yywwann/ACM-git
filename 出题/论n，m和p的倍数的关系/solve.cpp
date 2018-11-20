#include<stdio.h> 
#include<iostream>  
#define ll long long 
using namespace std;

ll a[100005],b[100005];  
int main(){
    ll t,n,m,p,ans;
    //scanf("%I64d",&t);
    cin>>t;
    while(t--){
        //scanf("%I64d%I64d%I64d",&n,&m,&p);  
        cin>>n>>m>>p;
        ans=0;  
        for(int i=0;i<p;i++) a[i]=n/p,b[i]=m/p;   
        ll N=n%p;
        ll M=m%p;
        for(int i=1;i<=N;i++) a[i]++;   
        for(int i=1;i<=M;i++) b[i]++;   

        for(int i=0;i<p;i++){  
            for(int j=0;j<p;j++){  
                if((i*j)%p==0) ans+=a[i]*b[j];   
            }  
        }  
        //printf("%I64d\n",ans);
        cout<<ans<<endl;
    }  
    return 0;  
}  