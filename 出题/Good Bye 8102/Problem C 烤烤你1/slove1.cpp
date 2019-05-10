#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n%2) printf("2\n");
        else printf("-2\n");
    }
    return 0;
}