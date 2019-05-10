#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
#define ll long long
map<string,string >mm;
int main()
{
    mm["将夜"]="宁缺";
    mm["仙逆"]="王林";
    mm["斗破苍穹"]="萧炎";
    mm["诛仙"]="张小凡";
    mm["遮天"]="叶凡";
    mm["莽荒纪"]="纪宁";
    mm["凡人修仙传"]="韩立";
    mm["斗罗大陆"]="唐三";
    mm["神墓"]="辰南";
    mm["一念永恒"]="白小纯";
    mm["星辰变"]="秦羽";
    mm["庆余年"]="范闲";
    mm[ "永夜君王"]="千夜";
    mm["牧神记"]="秦牧";
    mm["盘龙"]="林雷";
    int n;
    cin>>n;
    string s;
    while(n--)
    {
        cin>>s;
        cout<<mm[s]<<endl;
    }
     
     
     
     
    return 0;
}