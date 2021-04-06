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

int n,m,x,now=0;
vector<int> v;
int main(){Rosario
    cin>>n>>m;
    REP(i,n){
        cin>>x;
        while(now<x) v.em(++now);
        auto it=find(ALL(v),x);
        int dis=v.end()-it;
        if(dis>m+1){
            cout<<"no\n";
            return 0;
        }else v.erase(it);
    }cout<<"yes\n";
    return 0;
}
