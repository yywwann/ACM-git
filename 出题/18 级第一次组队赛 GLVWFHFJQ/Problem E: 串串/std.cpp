#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
string s;
int main()
{

    //ifstream fin("test.txt");


    //ofstream fout;
    //fout.open("test1.txt");
    int n;int t;
    cin>>t;
    while(t--)
    {

        cin>>s;
        ll num=0;
        ll ans=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='1')num++;
            else
            {
                ans+=num;
                num=(num+num)%mod;
                ans%=mod;
            }
        }

        cout<<ans<<endl;

    }
    //fin.close();
    //fout.close();
    return 0;
}
