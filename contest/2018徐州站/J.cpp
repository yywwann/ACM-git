#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 1e18;      		//  | |___  |  _  |   | |     
const ll N   = 1e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}
char c;
ll l,r;
int n,m;
struct node{
	ll c[2];
}a[505][505];
char mp[1005][1005];
struct _1{
	int i,j,flg;
};
vector<_1>wall;
int cmp(_1 aa,_1 b){
	return a[aa.i][aa.j].c[aa.flg]<a[b.i][b.j].c[b.flg];
}

map<int,map<int,int> >id;

struct Node{
    int to,w;
    Node(int to,int w):to(to),w(w){}
};
vector<Node>v[N];

int depth[N],fa[N][31],dis[N];
bool vs[N];


void init(){
    memset(depth,0,sizeof(depth));
    memset(fa,0,sizeof(fa));
    memset(dis,0,sizeof(dis));
    memset(vs,false,sizeof(vs));
    for(int i=1;i<=n;i++) v[i].clear();
}

void dfs(int u){
    vs[u]=true;
    for(int i=0;i<v[u].size();i++){
        Node t=v[u][i];
        if(!vs[t.to]){
            depth[t.to]=depth[u]+1;
            fa[t.to][0]=u;
            dis[t.to]=dis[u]+t.w;
            dfs(t.to);
        }
    }
}
int cnt=1;
//倍增,处理fa数组
void bz(){
	//cout<<"-------------------"<<endl;
    for(int j=1;j<=30;j++){
        for(int i=1;i<=cnt;i++){
            fa[i][j]=fa[fa[i][j-1]][j-1];
     		//cout<<i<<' '<<j<<' '<<fa[i][j]<<endl;
        }
    }
}

int lca(int x,int y){
    //保证深度大的点为x
    //cout<<x<<" "<<y<<endl;
    //cout<<"depth: "<<depth[x]<<' '<<depth[y]<<endl;
    if(depth[x]<depth[y]){
    	int t=x;x=y;y=t;
        //swap(x,y);
    }
    //cout<<x<<' '<<y<<endl;
    int dc=depth[x]-depth[y];
    for(int i=0;i<30;i++){
        if((1<<i)&dc)                 //一个判断，模拟下就会清楚
            x=fa[x][i];//,cout<<x<<endl;
    }
    //cout<<"lca: "<<x<<' '<<y<<endl;
    if(x==y)    return x;           //如果深度一样，两个点相同，直接返回
    for(int i=29;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){     //跳2^i不一样，就跳，否则不跳
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    x=fa[x][0];
    return x;
}


void JianTu(){
	for(int i=0;i<wall.size();i++){
		int x=(wall[i].i-1)*2+1,y=(wall[i].j-1)*2+1,flg=wall[i].flg;
		if(flg==0){
			//cout<<x+1<<" "<<y<<endl;
			mp[x+1][y]='#';
		}
		else{
			//cout<<x<<" "<<y+1<<endl;
			mp[x][y+1]='#';
		}
	}
}
int vis[1005][1005];
int d[4][2]={1,0,-1,0,0,1,0,-1};
struct T_T{
	int x,y,step;
};



void bfs(){
	
	n=n*2;m=m*2;
	queue<T_T>q;
	//vis[1][1]=1;
	q.push(T_T{1,1,0});
	while(!q.empty()){
		T_T u=q.front(); q.pop();
		int x=u.x,y=u.y,step=u.step;
		if(id[x][y]==0) id[x][y]=cnt++;
		//dis[x][y]=step;
		vis[x][y]=1;
		for(int i=0;i<4;i++){
			int X=x+d[i][0];
			int Y=y+d[i][1];
			if((X%2==0&&Y%2==0)||X>=n||Y>=m||X<=0||Y<=0||mp[X][Y]=='#'||vis[X][Y]==1) continue;
			if(X%2==0||Y%2==0){
				if(id[X][Y]==0) id[X][Y]=cnt++;
				//cout<<"-----id-----"<<endl;
				//cout<<X<<' '<<Y<<' '<<id[X][Y]<<endl;
				v[id[x][y]].push_back(Node(id[X][Y],0));
            	v[id[X][Y]].push_back(Node(id[x][y],0));
				q.push(T_T{X,Y,step});

			}
			else{
				if(id[X][Y]==0) id[X][Y]=cnt++;
				//cout<<"-----id-----"<<endl;
				//cout<<X<<' '<<Y<<' '<<id[X][Y]<<endl;
				v[id[x][y]].push_back(Node(id[X][Y],1));
            	v[id[X][Y]].push_back(Node(id[x][y],1));
				q.push(T_T{X,Y,step+1});
			}
		}
	}
}

int main(){
	//init();
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c>>l>>c>>r;
			if(l==0) l=INF;
			if(r==0) r=INF;
			a[i][j].c[0]=l;   //xia
			a[i][j].c[1]=r;   //you
		}
	}
	for(int i=1;i<=n-1;i++){
		vector<_1>v;
		if(i==n-1){
			for(int j=1;j<=m-1;j++){
				if(j==m-1){
					ll MIN=min({a[i][j].c[0],a[i][j].c[1],a[i+1][j].c[0],a[i+1][j].c[1],a[i][j+1].c[0],a[i][j+1].c[1]});
					if(a[i][j].c[0]==MIN){
						v.push_back(_1{i,j,0});
					}
					else if(a[i][j].c[1]==MIN){
						v.push_back(_1{i,j,1});
					}
					else if(a[i+1][j].c[0]==MIN){
						v.push_back(_1{i+1,j,0});
					}
					else if(a[i+1][j].c[1]==MIN){
						v.push_back(_1{i+1,j,1});
					}
					else if(a[i][j+1].c[0]==MIN){
						v.push_back(_1{i,j+1,0});
					}
					else if(a[i][j+1].c[1]==MIN){
						v.push_back(_1{i,j+1,1});
					}
				}
				else{
					ll MIN=min({a[i][j].c[0],a[i][j].c[1],a[i+1][j].c[0],a[i+1][j].c[1]});
					if(a[i][j].c[0]==MIN){
						v.push_back(_1{i,j,0});
					}
					else if(a[i][j].c[1]==MIN){
						v.push_back(_1{i,j,1});
					}
					else if(a[i+1][j].c[0]==MIN){
						v.push_back(_1{i+1,j,0});
					}
					else if(a[i+1][j].c[1]==MIN){
						v.push_back(_1{i+1,j,1});
					}
				}
			}
		}
		else{
			for(int j=1;j<=m-1;j++){
				if(j==m-1){
					ll MIN=min({a[i][j].c[0],a[i][j].c[1],a[i][j+1].c[0],a[i][j+1].c[1]});
					if(a[i][j].c[0]==MIN){
						v.push_back(_1{i,j,0});
					}
					else if(a[i][j].c[1]==MIN){
						v.push_back(_1{i,j,1});
					}
					else if(a[i][j+1].c[0]==MIN){
						v.push_back(_1{i,j+1,0});
					}
					else if(a[i][j+1].c[1]==MIN){
						v.push_back(_1{i,j+1,1});
					}
				}
				else{
					if(a[i][j].c[0]<a[i][j].c[1]){
						v.push_back(_1{i,j,0});
					}
					else{
						v.push_back(_1{i,j,1});
					}
				}
			}
		}
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<m-1;i++){
			wall.push_back(v[i]);
		}
	}
	// cout<<wall.size()<<endl;
	// for(int i=0;i<wall.size();i++){
	// 	int x=wall[i].i,y=wall[i].j,flg=wall[i].flg;
	// 	cout<<a[x][y].c[flg]<<endl;;
	// }
	JianTu();
	bfs();
	dfs(1);
    bz();
	int q=read();
	while(q--){
		int x1=read(),y1=read(),x2=read(),y2=read();
		x1=(x1-1)*2+1;y1=(y1-1)*2+1;x2=(x2-1)*2+1;y2=(y2-1)*2+1;
		//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		//cout<<dis[x1][y1]<<" "<<dis[x2][y2]<<endl;
		int u=id[x1][y1],v=id[x2][y2];
		//cout<<lca(u,v)<<endl;
		//cout<<u<<' '<<v<<endl;
		//cout<<dis[u]<<' '<<dis[v]<<' '<<lca(u,v)<<endl;
		cout<< dis[u]+dis[v]-2*dis[lca(u,v)] <<endl;
		//cout<< abs(dis[x1][y1]-dis[x2][y2]) <<endl;
	}
	return 0;
}
