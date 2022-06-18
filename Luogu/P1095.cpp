//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

int n,m,t,p1=0,p2=0;
int main(){Rosario
    cin>>n>>m>>t;
    REP1(i,1,t){
        p1+=17;
        if(n>=10) p2+=60,n-=10;
        else n+=4;
        if(p2>p1) p1=p2;
        if(p1>=m){
            cout<<"Yes\n"<<i<<"\n";
            return 0;
        }
    }cout<<"No\n"<<p1<<"\n";
    return 0;
}
