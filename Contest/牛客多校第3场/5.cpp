// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const ll inf  = 0x3f3f3f3f;
// const ll maxn = 1e6+5;
// ll read(){
//     ll x=0,f=1;char ch=getchar();
//     while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
//     while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
//     return x*f; 
// }
// #define ull unsigned long long
// ull B=1e8+7;

// map<ull,int>mp;
// char s[2*maxn];
// vector<int>ans[maxn];
// int cnt;


// ull p[2*maxn];
// ull sum[2*maxn];
// int len;

// void overlap()//s的后缀和t的前缀的最大长度
// {
//     p[0]=1;
//     sum[0]=0;
//     for(int i=1;i<=len*2;i++) p[i]=p[i-1]*B;
//     for(int i=1;i<=len*2;i++)
//     {
//         sum[i]=sum[i-1]*B+(s[i-1]-'a'+1);
//     }
// } 

// int main(){
// 	scanf("%s",s);
// 	len=strlen(s);
// 	for(int i=0;i<len;i++){
// 		s[i+len]=s[i];
// 	}
// 	overlap();
// 	for(int i=1;i<=len;i++){
// 		int j=i+len-1;
// 		ull t=sum[j]-sum[i-1]*p[j-i+1];
// 		int pos=mp[t];
// 		if(pos==0){
// 			cnt++;
// 			pos=mp[t]=cnt;
// 		}
// 		ans[pos].push_back(i-1);
// 	}

// 	// string t="";
// 	// for(int i=0;i<len;i++){
// 	// 	t+=s[i];
// 	// }
// 	// cout<<tt<<endl;
// 	// int hs=overlap(t);
// 	// cout<<tt<<endl;
// 	// if(mp[hs]==0){
// 	// 	cnt++;
// 	// 	mp[hs]=cnt;
// 	// 	ans[mp[hs]].push_back(0);
// 	// }
// 	// for(int i=1;i<len;i++){

// 	// 	t.erase(t.begin());
// 	// 	t+=s[i+len-1];

// 	// 	if(mp[hs]==0){
// 	// 		cnt++;
// 	// 		mp[hs]=cnt;
// 	// 	}
// 	// 	ans[mp[hs]].push_back(i);
// 	// }
// 	printf("%d\n",cnt);
// 	for(int i=1;i<=cnt;i++){
// 		printf("%d",ans[i].size());
// 		for(int j=0;j<ans[i].size();j++){
// 			printf(" %d",ans[i][j]);
// 		}printf("\n");
// 	}
// 	return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf  = 0x3f3f3f3f;
const ll maxn = 1e6+5;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

char Find[maxn];
int NEXT[maxn];
int len;

void getNEXT() {
	int i = 0, j = NEXT[0] =-1;
	while (i<len){
		if (j == -1 || Find[i] == Find[j]) {
			i++;j++;
			NEXT[i] = j;
			
		}
		else {
			j = NEXT[j];
		}
	}
}


int main(){
	scanf("%s",Find);
	len=strlen(Find);
	getNEXT();
	
	int ans=len-NEXT[len];
	if(len%ans==0){
		//cout<<ans<<endl;
		printf("%d\n",ans);
		for(int i=0;i<ans;i++){
			//cout<<len/ans;
			printf("%d",len/ans);
			for(int j=i;j<len;j+=ans){
				printf(" %d",j);
			}printf("\n");
		}
	}
	else{
		printf("%d\n",len);
		for(int i=0;i<len;i++){
			printf("1 %d\n",i);
		}
	}
	return 0;
}
