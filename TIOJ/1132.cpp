#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

int n,sum;
pii a[100000];
bool vis[1005][1005];
int main(){Rosario
    while(cin>>n){memset(vis,0,sizeof(vis));
    REP(i,n) cin>>a[i].F>>a[i].S,vis[a[i].F][a[i].S]=1;
    sort(a,a+n);sum=0;
    REP(i,n){
        if(vis[a[i].F+1][a[i].S+2]==0&&vis[a[i].F][a[i].S+1]==0) sum++,vis[a[i].F+1][a[i].S+2]=1;
        if(vis[a[i].F+2][a[i].S+1]==0&&vis[a[i].F+1][a[i].S]==0) sum++,vis[a[i].F+2][a[i].S+1]=1;
    }cout<<sum<<"\n";
    }
//    system("pause");
    return 0;
}
