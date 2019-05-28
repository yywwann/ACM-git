#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;


struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
};
struct Line{
    Point A,B;
};
typedef Point Vector;

Vector operator -(Point A,Point B){
    return Vector(A.x-B.x,A.y-B.y);
}
int sgn(int d){
    if(d==0) return 0;
    if(d>0) return 1;
    return -1;
}
int Cross(Vector A,Vector B){
    return A.x*B.y-A.y*B.x;
}

int Dot(Vector A,Vector B){
    return A.x*B.x+A.y*B.y;
}

bool OnSegment(Point P,Point a1,Point a2){
    return sgn(Cross(a1-P,a2-P))==0 && sgn(Dot(a1-P,a2-P))<0;
}

bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
    int c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1);
    int c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
    if(!sgn(c1)||!sgn(c2)||!sgn(c3)||!sgn(c4)){
        bool f1=OnSegment(b1,a1,a2);
        bool f2=OnSegment(b2,a1,a2);
        bool f3=OnSegment(a1,b1,b2);
        bool f4=OnSegment(a1,b1,b2);
        bool f=(f1|f2|f3|f4);
        return f;
    }
    return (sgn(c1)*sgn(c2)<0&&sgn(c3)*sgn(c4)<0);
}
double dis(Point A,Point B){
    return sqrt(1.0*(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

int t,n,m;
int vis[1005];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        Point p[1005];
        Line L[1005];
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d%d%d",&L[i].A.x,&L[i].A.y,&L[i].B.x,&L[i].B.y);
        }
        p[0].x=0,p[0].y=0;
        double dist=0;
        for(int i=1;i<=n;i++){
            int flag=0;
            for(int j=1;j<=m;j++){
                if(SegmentProperIntersection(p[0],p[i],L[j].A,L[j].B)){
                    dist+=dis(p[0],p[i]);
                    flag=1;
                    break;
                }
            }
            if(flag==1) continue;
            for(int k=1;k<=n;k++){
                if(i!=k){
                    if(OnSegment(p[k],p[0],p[i])){
                        dist+=dis(p[0],p[i]);
                        break;
                    }
                }
            }
        }
        printf("%.2f\n",dist);
    }
    return 0;
}
