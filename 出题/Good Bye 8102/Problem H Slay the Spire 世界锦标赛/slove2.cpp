#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<stdio.h>
#include<string.h>
using namespace std;
#define ll long long
struct node{
int n,id;   
}a[200000];
int ran[200000];
bool cmp(node x,node y)
{
    return x.n<y.n;
}
 
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i].n);
            a[i].id=i;
        }
        sort(a,a+n,cmp);
     
         
        int l=0,r=0;
        for(int i=0;i<n;i++)
        {
            l=i;
            while(a[r+1].n<=2*a[l].n&&r+1<n)
            r++;
            int nu=0;
            for(int k=i;k>=0;k--)
            {
                if(k==i)continue;
                if(a[k].n==a[i].n)nu++;
                else break;
            }
             
            ran[a[i].id]=(r-l)+nu;
        }
        for(int i=0;i<n;i++)
        {
             
             
            if(i==0)printf("%d",ran[i]);
            else printf(" %d",ran[i]);
        }
        printf("\n");
    }
         
     
    return 0;
}