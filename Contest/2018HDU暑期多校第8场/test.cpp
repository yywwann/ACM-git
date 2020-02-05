#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int k,n=10;
int a[10]={1,2,3,4,5,6,7,8,9,10};
int main()
{
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
   while(scanf("%d",&k))
   {
       cout<<k<<"的第一个大于等于它的位置在"<<((lower_bound(a+1,a+n,k))-a)<<endl;
   }
}