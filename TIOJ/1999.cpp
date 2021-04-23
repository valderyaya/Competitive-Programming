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

priority_queue<int,vector<int>,greater<int>> q;
int n,m,x,y;
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n){
        cin>>x;
        if(i<=m) q.emplace(x);
        else{
            y=q.top(); q.pop();
            q.emplace(x+y);
        }
    }
    x=0;
    for(;!q.empty();q.pop()) x=q.top();
    cout<<x<<"\n";
    return 0;
}
