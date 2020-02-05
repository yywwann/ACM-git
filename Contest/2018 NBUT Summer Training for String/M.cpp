#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}
#define ull unsigned long long
ull B=163;
const int maxn=1e5+5;
char s[maxn];
ull sum[maxn];
ull p[maxn];

void gethash(){
    p[0]=1;
    sum[0]=0;
    int len=strlen(s);
    for(int i=1;i<=len;i++) p[i]=p[i-1]*B;
    for(int i=1;i<=len;i++) sum[i]=sum[i-1]*B+(s[i-1]-'a');
    //for(int i=1;i<=len;i++) cout<<sum[i]<<' '; cout<<endl;
}

int n;
int a[30005];
int main(){
    cin>>s;
    gethash();
    n=read();
    int len=strlen(s);
    while(n--){
        int l=read();
        int r=read();
        ull ans=sum[r]-sum[l-1]*p[r-l+1];
        cout<<ans<<endl;
    }
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll read(){
//     ll x=0,f=1;char ch=getchar();
//     while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
//     while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
//     return x*f; 
// }
// #define ull unsigned long long
// ull B=163;
// const int maxn=1e5+5;
// char s[maxn];
// ull sum[maxn];
// ull p[maxn];

// void gethash(){
//     p[0]=1;
//     sum[0]=0;
//     int len=strlen(s);
//     for(int i=1;i<=len;i++) p[i]=p[i-1]*B;
//     for(int i=1;i<=len;i++) sum[i]=sum[i-1]*B+(s[i-1]-'a');
//     //for(int i=1;i<=len;i++) cout<<sum[i]<<' '; cout<<endl;
// }

// int n;
// int a[30005];
// int main(){
//     cin>>s;
//     gethash();
//     n=read();
//     int len=strlen(s);
//     while(n--){
//         int l=read();
//         int r=read();
//         ull ans=sum[r]-sum[l-1]*p[r-l+1];
//         cout<<ans<<endl;
//     }
// }
