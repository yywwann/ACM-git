#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf  = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

int t;
int n;
struct node
{
    string t;
    int l,r;
    int add;
}a[maxn];

char s[maxn];

int cmp(node a,node b){
    if(a.l>a.r&&b.l<=b.r) return true;
    if(a.l<=a.r&&b.l>b.r) return false;
    if(a.l<=a.r&&b.l<=b.r) return a.l>b.l;
    return a.r<b.r;
}

int main(){
    t=read();
    while(t--){
        n=read();
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            int len=strlen(s);
            a[i].t="";
            a[i].l=a[i].r=a[i].add=0;

            stack<char>st;
            for(int j=0;j<len;j++){
                if(s[j]=='(') st.push('(');
                else if(!st.empty()){
                    st.pop();
                    a[i].add++;
                }
                else{
                    a[i].r++;
                    a[i].t+=")";
                }
            }
            while(!st.empty()){
                a[i].l++;
                a[i].t+="(";
                st.pop();
            }
        }

        ll ans=0;
        sort(a+1,a+1+n,cmp);
        string ss="";
        for(int i=1;i<=n;i++){
            ss+=a[i].t;
            ans+=a[i].add;
        }
        stack<char>st;
        for(int i=0;i<ss.size();i++){
            if(ss[i]=='(') st.push('(');
            else if(!st.empty()){
                st.pop();
                ans++;
            }
        }
        cout<<ans*2<<endl;
    }
    return 0;
}
