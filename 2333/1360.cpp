#include<iostream>
using namespace std;

int n;

void check(){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			cout << i << endl;
			return;
		}
	}
	cout << n << endl;
	return ;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		check();
	}
}
