#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;
 
const int MAX=20000+10;
int *rank,r[MAX],sa[MAX],height[MAX];
int wa[MAX],wb[MAX],wm[MAX];
 
bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a+l] == r[b+l];
}
 
void makesa(int *r,int *sa,int n,int m){
	int *x=wa,*y=wb,*t;
	for(int i=0;i<m;++i)wm[i]=0;
	for(int i=0;i<n;++i)wm[x[i]=r[i]]++;
	for(int i=1;i<m;++i)wm[i]+=wm[i-1];
	for(int i=n-1;i>=0;--i)sa[--wm[x[i]]]=i;
	for(int i=0,j=1,p=0;p<n;j=j*2,m=p){
		for(p=0,i=n-j;i<n;++i)y[p++]=i;
		for(i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<m;++i)wm[i]=0;
		for(i=0;i<n;++i)wm[x[y[i]]]++;
		for(i=1;i<m;++i)wm[i]+=wm[i-1];
		for(i=n-1;i>=0;--i)sa[--wm[x[y[i]]]]=y[i];
		for(t=x,x=y,y=t,i=p=1,x[sa[0]]=0;i<n;++i){
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
		}
	}
	rank=x;
}
 
void calheight(int *r,int *sa,int n){
	for(int i=0,j=0,k=0;i<n;height[rank[i++]]=k){
		for(k?--k:0,j=sa[rank[i]-1];r[i+k] == r[j+k];++k);
	}
}
 
int main(){
	int n;
	while(cin>>n,n){
		for(int i=0;i<n;++i)scanf("%d",&r[i]);
		for(int i=0;i<n-1;++i)r[i]=r[i+1]-r[i]+100; 
		r[--n]=0;
		makesa(r,sa,n+1,200);
		calheight(r,sa,n);//这里注意不要传递n+1过去,rank[n]-1=0-1=-1 
		int l=1,r=n+1,mid,L,R;
		bool flag=false;
		while(l<=r){
			mid=l+r>>1;
			L=INF,R=-INF,flag=false;
			for(int i=1;i<=n;++i){
				if(height[i]>=mid){
					L=min(L,sa[i]);
					L=min(L,sa[i-1]);
					R=max(R,sa[i]);
					R=max(R,sa[i-1]);
				}else{
					if(L+mid+1<=R)flag=true;//这里注意是L+mid+1,因为r[L+mid]=r[L+mid+1]-r[L+mid],从L开始原串中前面那个子串包括L+mid+1 
					L=INF,R=-INF;
				}
			}
			if(L+mid+1<=R)flag=true;
			if(flag)l=mid+1;
			else r=mid-1;
		}
		if(l>=5)cout<<l<<endl;
		else cout<<0<<endl;
	}
	return 0;
}