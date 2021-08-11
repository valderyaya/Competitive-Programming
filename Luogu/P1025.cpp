//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,k,cnt=0;
void dfs(int now,int sum,int idx){
    if(idx==k){
        if(sum==n) ++cnt;
        return ;
    }
    for(int i=now;sum+i*(k-idx)<=n;++i) dfs(i,sum+i,idx+1);
}
int main(){Rosario
    cin>>n>>k;
    dfs(1,0,0);
    cout<<cnt<<"\n";
    return 0;
}
