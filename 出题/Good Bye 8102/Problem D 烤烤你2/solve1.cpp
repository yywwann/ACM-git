#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<stdio.h>
#include<string.h>
using namespace std;
#define ll long long
int f[100];
 
 
int main()
{
    int t;
    scanf("%d",&t);
    int n,y,m;
    while(t--)
    {
        memset(f,0,sizeof(f));
        scanf("%d%d",&n,&y);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m);
            //cout<<(m&y)<<endl;
            if((m&y)==m)
            {
                //cout<<m<<endl;
                    for(int j=0;;j++)
                {
                    if(m<=0)break;
                    if(m%2)f[j]++;
                    m/=2;
                }   
            }
         
        }
        int ans=1000000000;
        for(int i=0;;i++)
        {
            if(y<=0)break;
            if(y%2)ans=min(ans,f[i]);
            y/=2;
        }
        cout<<ans<<endl;
         
    }
     
//0111
//0001
//0010
//0100
//0111
//1000
 
 
 
 
 
     
     
    return 0;
}