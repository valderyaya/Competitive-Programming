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

int n;
int cal(string x){
    int res=0;
    for(auto &i:x) res+=i-'0';
    return res;
}
struct qq{
    string x;
    int id,c;
    bool operator<(const qq &a){return c==a.c?id<a.id:c<a.c;}
}q[100005];
int main(){Rosario
    while(cin>>n){string x;
        REP(i,n) cin>>x,q[i]=qq{x,i,cal(x)};
        sort(q,q+n);
        REP(i,n) cout<<q[i].x<<" \n"[i==n-1];
    }
    return 0;
}
