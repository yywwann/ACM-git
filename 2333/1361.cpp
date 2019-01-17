#include<iostream>
#include<stdio.h>
using namespace std;

int n;
int vis[20], a[20];

bool isprime(int x){
	if(x < 2) return false;
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0) return false;
	}
	return true;
}

void dfs(int x){
	if(x == n+1){
		if(isprime(a[1] + a[n])){
			for(int i = 1; i <= n; i++){
				if(i == 1) cout << a[i];
				else cout << " " << a[i];
			} cout << endl;
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			if(vis[i] == 1) continue;
			vis[i] = 1;
			a[x] = i;
			if(x == 1 || isprime(a[x] + a[x-1])) dfs(x+1);
			vis[i] = 0;
		}
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		if(n == 1) continue;
		for(int i = 1; i < 20; i++) vis[i] = 0;
		a[1] = 1;
		vis[1] = 1;
		dfs(2);
	}
}
