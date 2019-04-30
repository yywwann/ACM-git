#include<iostream>
#include<cstdio>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm> 
using namespace std;
long long t,n,a[100005],b[100005],f[100005],sz;
struct node{
    long long f,i;
}head[100005];
void push(node x){
    long long i=sz++;
    while (i>0){
        long long p=(i-1)/2;
        if (head[p].f<=x.f) break;
        head[i]=head[p];
        i=p;
    }
    head[i]=x;
}
void pop(){
    node x=head[--sz];
    long long i=0;
    while (i*2+1<sz){
        long long a=i*2+1,b=i*2+2;
        if (b<sz&&head[b].f<head[a].f) a=b;
        if (head[a].f>=x.f) break;
        head[i]=head[a];
        i=a;
    }
    head[i]=x;
}
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        for (long long i=1;i<=n;i++) scanf("%d",&a[i]);
        for (long long i=1;i<=n;i++)     scanf("%d",&b[i]);
        f[1]=a[1];
        sz=0;
        node l;
        l.f=f[1];
        l.i=1;
        push(l);
        for (long long i=2;i<=n;i++){
            while(!(i-head[0].i<=b[head[0].i])) pop();
            f[i]=head[0].f+a[i];
            l.f=f[i];
            l.i=i;
            push(l);
        }
        while (sz) pop();
        printf("%lld\n",f[n]);
    }
    return 0;
}