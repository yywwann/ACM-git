#include<iostream>
using namespace std;

struct node{
	int A, B;
}a[100005];

int t;
int n, la, lb;
int ans;

void dfs(int pos, int lla, int llb, int t){
	if(pos == n + 1){
		ans = max(ans, t);
		return;
	}
	if(lla < la){
		dfs(pos+1, lla+1, llb, t + a[pos].A);
	}
	if(llb < lb){
		dfs(pos+1, lla, llb+1, t + a[pos].B);
	}
	dfs(pos+1, lla, llb, t);
}

int main(){

	scanf("%d", &t);
	while(t--){
		ans = 0;
		scanf("%d %d %d", &n, &la, &lb);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i].A);
			a[i].A = max(a[i].A, 0);
		}
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i].B);
			a[i].B = max(a[i].B, 0);
		}
		dfs(1, 0, 0, 0);
		cout << ans << endl;
	}
}
