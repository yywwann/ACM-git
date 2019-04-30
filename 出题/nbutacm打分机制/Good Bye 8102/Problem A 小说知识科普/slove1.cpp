#include<iostream> 
#include<cstring>
using namespace std;
 
char s1[20][20]={"将夜","仙逆","斗破苍穹","诛仙","遮天","莽荒纪","凡人修仙传","斗罗大陆","神墓","一念永恒","星辰变","庆余年","永夜君王","牧神记","盘龙"};
char s2[20][20]={"宁缺","王林","萧炎","张小凡","叶凡","纪宁","韩立","唐三","辰南","白小纯","秦羽","范闲","千夜","秦牧","林雷"};
 
 
int main(){
    char s[15];
    int n;
    cin>>n; 
    while(n--){
        cin>>s;
        for(int i=0;i<15;i++){
            if(strcmp(s,s1[i])==0){
                printf("%s\n",s2[i]);
                break;
            }
        }
    }
    return 0;
}