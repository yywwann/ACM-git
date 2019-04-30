#include<iostream>
using namespace std;

int n,m;
struct node{
	string name;
	string grade[100];
	string change[100];
}a[100];

int StrToInt(string s){
	int num = 0;
	for(int i = 0; i < 4; i++){
		num = num * 10 + s[i] - '0';
	}
	return num;
}

string checkcolor(int num){
	if(num < 1300) return "	<td style='color: #778899;'>";
	if(num < 1500) return "	<td style='color: #4EEE94;'>";
	if(num < 1600) return "	<td style='color: #228B22;'>";
	if(num < 1900) return "	<td style='color: #436EEE;'>";
	if(num < 2100) return "	<td style='color: #7D26CD;'>";
}

string td(string s){
	return "	<td>" + s + "</td>";
}

string td(int ss){
	string s="";
	while(ss){
		s =  (char)(ss%10+'0') + s;
		ss/=10;
	}
	return "	<td>" + s + "</td>";
}

string spanGrade(string s){
	int num = StrToInt(s);
	string pre, end;
	if(num < 1300) pre = "<span style='color: #778899;'>";
	else if(num < 1500) pre = "<span style='color: #4EEE94;'>";
	else if(num < 1600) pre = "<span style='color: #228B22;'>";
	else if(num < 1900) pre = "<span style='color: #436EEE;'>";
	else if(num < 2100) pre = "<span style='color: #7D26CD;'>";
	end = "</span>";
	return pre + s + end;
}

string spanChange(string s){
	string pre, end;
	if(s[0] == '+') pre = "<span style='color: #00FF00;'>";
	else pre = "<span style='color: #FF0000;'>";
	end = "</span>";
	return pre + '(' + s + ')' + end;
}

bool cmp(node a, node b){
	return StrToInt(a.grade[m]) > StrToInt(b.grade[m]);
}

int main(){
	freopen("/Users/cccccccccchy/Desktop/nbutacm打分机制/grade.txt", "r", stdin);
	freopen("/Users/cccccccccchy/Desktop/nbutacm打分机制/grade_out.txt", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i].name;
		//cout << a[i].name << endl;
		for(int j = 1; j <= m; j++){
			cin >> a[i].grade[j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i].change[j];
			if(a[i].change[j][0]!='-'){
				a[i].change[j] = '+' + a[i].change[j];
			}
		}
	}
	sort(a+1, a+1+n, cmp);
	for(int i = 1; i <= n; i++){
		cout << "<tr>" << endl;
		cout << td(i) << endl;
		cout << td(a[i].name) << endl;
		for(int j = 1; j <= m; j++){
			cout << "	<td>";
			cout << spanGrade(a[i].grade[j]);
			cout << spanChange(a[i].change[j]);
			//cout << td(a[i].grade[j]+'('+a[i].change[j]+')',1) << endl;
			cout << "</td>" << endl;
		}
		cout << "</tr>" << endl;
	}
}
