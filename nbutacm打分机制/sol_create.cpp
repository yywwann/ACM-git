#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n,m;
struct node{
	string id;
	string text;
	node(string _id, string _text){
		id = _id;
		text = _text;
	}
};
string s;
vector<node>ans;

bool checkh2(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '<' && s[i+1] == 'h' && s[i+2] == '2'){
			return true;
		}
	}
	return false;
}

string getText(string s){
	int flg = 0;
	string ans = "";
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '<' && flg == 1) return ans;
		if(flg == 1) ans += s[i];
		if(s[i] == '>'){
			flg = 1;
		}
	}
}

string getId(string s){
	int flg = 0;
	string ans = "";
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '"' && flg == 1) return ans;
		if(flg == 1) ans += s[i];
		if(s[i-3] == 'i' && s[i-2] == 'd' && s[i-1] == '=' && s[i] == '"'){
			flg = 1;
		}
	}
}

string getLi(node a){
	string id = a.id;
	string text = a.text;
	//<li><a href="#toc_1" class="nav-link js-scroll-trigger">A.小说知识科普</a></li>
	string ans = "<li><a href=\"#";
	ans += id;
	ans += "\" class=\"nav-link js-scroll-trigger\">";
	ans += text;
	ans += "</a></li>";
	return ans;

}

int main(){
	freopen("/Users/cccccccccchy/Desktop/nbutacm打分机制/sol_in.txt", "r", stdin);
	freopen("/Users/cccccccccchy/Desktop/nbutacm打分机制/sou_out.txt", "w", stdout);
	while(getline(cin,s)){
		//cout << s << endl;
		if(checkh2(s)){
			string id = getId(s);
			string text = getText(s);
			//cout << id << endl;
			//cout << text << endl;
			ans.push_back(node(id, text));
		}
	}
	for(int i = 0; i < ans.size(); i++){
		cout<<getLi(ans[i])<<endl;
	}
}
