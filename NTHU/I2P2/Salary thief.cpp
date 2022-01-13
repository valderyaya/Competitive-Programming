//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

const ll mod=1e9+7;
int t,n;
string s;
ll ret,now;
signed main(){Aincrad
    cin>>t;
    while(t--){
        ret=0;
        cin>>n>>s;
        now=s.size();
        REP(i,n){
            --now;
            int x=s[i]-'0';
            ret=x*now%mod;
            if(s.size()<1e6){
                string p=s.substr(i+1);
                s.erase(i+1);
                for(int j=0;j<x&&s.size()<1e6;++j) s+=p;
            }
            now=(x*now)%mod;
        }
        cout<<(ret+n)%mod<<"\n";
    }
    return 0;
}
