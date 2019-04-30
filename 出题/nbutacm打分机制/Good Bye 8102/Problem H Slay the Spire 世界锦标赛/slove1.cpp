#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll a[N];
ll b[N];
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++) b[i]=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        for(int i=0;i<n;i++){
            int p=lower_bound(b,b+n,a[i])-b;
            int pp=upper_bound(b,b+n,a[i]*2)-b;
            cout<<pp-p-1<<" ";
//          if(p<0||p>=n){
//              
//          }
        }
        cout<<endl;
    }
    return 0;
}