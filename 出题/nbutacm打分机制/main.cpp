#include<bits/stdc++.h>
using namespace std;
const int K = 5;
int n,m;
struct node{
	int id;
	string name;
	double rate;
	int rank[100];
	double change;

}p[100];

double Trate[100];

int cmp(node a,node b){
	return a.rate > b.rate;
}

int cmpbyid(node a,node b){
	return a.id < b.id;
}

int main(){
	freopen("/Users/cccccccccchy/Desktop/nbutacm打分机制/in.txt", "r", stdin);
	cout << "Start!" << endl;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		p[i].id = i;
		cin >> p[i].name;
		for(int j = 1; j <= m; j++){
			cin >> p[i].rank[j];
		}
		p[i].rate = 1500;
	}

	for(int k = 1; k <= m; k++){
		for(int i = 1; i <= n; i++){
			double s = 0, e = 0;
			for(int j = 1; j <= n; j++){
				double ra = p[i].rank[k];
				double rb = p[j].rank[k];
				double ratea = p[i].rate;
				double rateb = p[j].rate;

				if(i == j) continue;
				if(ra < rb) s += 1;
				//if(ra > rb) s += 0;
				e += 1.0 / (1 + pow(10.0, (rateb - ratea)/400));

			}
			//cout << s << "\t" << e << endl;
			//p[i].rate = p[i].rate + K * (s - e);
			Trate[i] = p[i].rate + K * (s - e);
		}

		for(int i = 1; i <= n; i++){
			p[i].change = Trate[i] - p[i].rate;
		}



		for(int i = 1; i <= n; i++) {
			p[i].rate = Trate[i];
		}
		printf("第%d次周赛\n", k);
		sort(p+1, p+1+n, cmp);
		for(int i = 1; i <= n; i++){
			cout << p[i].name << "\t" << (int)p[i].rate << endl;
		}
		printf("------change---------\n");
		sort(p+1, p+1+n, cmpbyid);
		for(int i = 1; i <= n; i++){
			//if((int)p[i].change >= 0) cout<<"+";
			cout << (int)p[i].change << endl;
		}
		printf("------scort---------\n");
		for(int i = 1; i <= n; i++){
			//if((int)p[i].change >= 0) cout<<"+";
			cout << (int)p[i].rate << endl;
		}
	}


}
