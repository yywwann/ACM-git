#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=100005;
struct node
{
    int x,y;
} a[N],p[N];
int n,tot;

int dis(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int multi(node p0,node p1,node p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int cmp(node p1,node p2)//极角排序；
{
    int x=multi(p1,p2,a[0]);
    if(x>0||(x==0&&dis(p1,a[0])<dis(p2,a[0]))) return 1;
    return 0;
}

void Graham()//先求凸包；
{
    int k=0;
    for(int i=0; i<n; i++)
        if(a[i].y<a[k].y||(a[i].y==a[k].y&&a[i].x<a[k].x)) k=i;
    swap(a[0],a[k]);
    sort(a+1,a+n,cmp);
    tot=2,p[0]=a[0],p[1]=a[1];
    for(int i=2; i<n; i++)
    {
        while(tot>1&&multi(p[tot-2],p[tot-1],a[i])<=0) tot--;
        p[tot++]=a[i];
    }
}

int solve()
{
    Graham();
    int q=1,ans=0;
    p[tot]=p[0];
    for(int i=0; i<tot; i++)
    {
        while(multi(p[i],p[i+1],p[q+1])>multi(p[i],p[i+1],p[q])) q=(q+1)%tot;  //q=(q+1)%tot;
        ans=max(ans,max(dis(p[i],p[q]),dis(p[(i+1)%tot],p[(q+1)%tot])));       //取对踵点与边上两端点距离大的值；
    }
    return ans;
}
 
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++) scanf("%d%d",&a[i].x,&a[i].y);
        int ans=solve();
        printf("%d\n",ans);
    }
    return 0;
}
