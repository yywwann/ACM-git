#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 1e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}
#define CLR(x) memset(x,0,sizeof(x))

struct node{
	int a,b;
};

struct Trie{
    int ch[N][2];
    int dis[N];
    int val[N];
    int sz;//节点总数 
    void Clear(){sz=1;CLR(ch[0]);CLR(val);CLR(dis);}//初始时只有一个根节点 
    int idx(char c){return c-'0';}//字符c的编号 
    void Insert(const char*s,int v){
        int u=0,n=strlen(s),c;
        for(int i=0;i<n;i++){
            c=idx(s[i]);
            if(!ch[u][c])//创建新的节点 
            {
                CLR(ch[sz]);
                val[sz]=0;//过程中的节点为0 
                ch[u][c]=sz++;//新建节点的编号 
                dis[ch[u][c]]=i;
            }
            u=ch[u][c];//往下走 
        }
        val[u]=v;//给插入的字符串的最后一个字符附加信息为v 
    }
    string fff(string s){
    	string ans="";
    	int u,j;
    	for(int i=0;i<s.size();i++){
    		u=0,j=i;
    		for(;j<s.size();j++){
    			int c=idx(s[j]);
    			if(val[u]!=0){
    				ans+=char(val[u]);
    				break;
    			}
    			u=ch[u][c];
    		}i=j-1;
    	}
    	ans+=char(val[u]);
    	return ans;
    }
}Tree;
int n,m;
char str[2*N];
string s;

int To(char c){
	if('0'<=c&&c<='9') return c-'0';
	if('a'<=c&&c<='z') return c-'a'+10;
	if('A'<=c&&c<='Z') return c-'A'+10;
	return 0;
}

string f(char str[]){
	string s="";
	int len=strlen(str);
	for(int i=0;i<len;i++){
		string T="0000";
		int t=To(str[i]);
		for(int i=0;i<4;i++){
			if(t&(1<<i)) T[4-i-1]='1';
		}
		s+=T;
	}
	return s;
}

string ff(string s){
	string ans="";
	for(int i=1;i*9<=s.size();i++){
		string t="",tt="";
		int _1=0;
		for(int j=(i-1)*9;j<(i-1)*9+9;j++){
			t=t+s[j];
		}
		for(int i=0;i<8;i++){
			if(t[i]=='1') _1++;
			tt+=t[i];
		} 
		if(_1%2==1&&t[8]=='0') ans+=tt;
		if(_1%2==0&&t[8]=='1') ans+=tt;
	}
	return ans;
}

int main(){
	for(int _=read();_;_--){
		n=read(),m=read();
		Tree.Clear();
		for(int i=0;i<m;i++){
			int v=read();
			scanf("%s",str);
			Tree.Insert(str,v);
		}
		scanf("%s",str);
		s=f(str);
		s=ff(s);
		string ans=Tree.fff(s);
		for(int i=0;i<n;i++) cout<<ans[i];cout<<endl;
	}
	return 0;
}
