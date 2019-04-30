#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
#define ll long long
 
int t;
string s;
 
int main(){
    cin >> t;
    while(t--){
        cin >> s;
        s += "wc";
        int pre = 0, ppre = 0, lastwc = 0;
        vector<ll>a;
        ll ans = 0;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == 'w' && s[i+1] == 'c'){
                if(pre == 0){
                    a.push_back(i-pre+1);
                }
                else if(i == s.size()-2){
                    a.push_back(i-pre+1);
                }
                else{
                    a.push_back(i-pre+2);
                }
                pre = i+2;
            }
        }
        // for(int i = 0; i < a.size(); i++){
        //  cout << a[i] << ' ';
        // }cout << endl;
        for(int i = 0; i < a.size()-1; i++){
            ans += a[i] * a[i+1];
        }
        cout << ans << endl;
    }
}