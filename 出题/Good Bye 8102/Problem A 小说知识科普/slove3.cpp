#include<iostream>
#include<string>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    string a;
    string s[16]={"将夜","仙逆","斗破苍穹","诛仙","遮天","莽荒纪","凡人修仙传","斗罗大陆","神墓","一念永恒","星辰变","庆余年","永夜君王","牧神记","盘龙"};
    string ans[16]={"宁缺","王林","萧炎","张小凡","叶凡","纪宁","韩立","唐三","辰南","白小纯","秦羽","范闲","千夜","秦牧","林雷"};
    while(n--){
        cin>>a;
        for(int i=0;i<16;i++){
            if(s[i]==a){
                cout<<ans[i]<<endl;
                break;
            }
        }
    }
    return 0;
}