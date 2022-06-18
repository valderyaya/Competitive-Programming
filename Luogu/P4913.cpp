#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
#define wait system("pause");

int n,mx=0;
pii v[1000005];
void dfs(int x,int dep){
    if(!x) return;
    mx=max(mx,dep);
    dfs(v[x].F,dep+1);
    dfs(v[x].S,dep+1);
}
int main(){Rosario
    cin>>n;
    int x,y;
    REP1(i,1,n) cin>>v[i].F>>v[i].S;
    dfs(1,1);
    cout<<mx<<"\n";
//    wait
    return 0;
}
