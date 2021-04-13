//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int inf=2147483647;
int n,x,y,ans=1;
queue<int> q;
int main(){Rosario
    cin>>n;y=-1;
    while(n--) cin>>x,q.emplace(x);
    q.emplace(inf);
    while(1){
        x=q.front(); q.pop();
        if(q.empty()) break;
        if(x==inf){
            q.emplace(x);
            ++ans;
            y=q.front(); q.pop();
        }else if(x>y) y=x;
        else q.emplace(x);
    }cout<<ans<<"\n";
    return 0;
}
