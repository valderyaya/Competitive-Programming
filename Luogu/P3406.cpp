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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m,cnt[100005];
ll ans=0,now=0;
int main(){Rosario
    int a,b,c;
    cin>>n>>m>>a;
    REP(i,m-1) cin>>b ,cnt[min(a,b)]++, cnt[max(a,b)]-- ,a=b;
    REP1(i,1,n-1){
        cin>>a>>b>>c;
        now+=cnt[i];
        if(a*now<b*now+c) ans+=a*now;
        else ans+=b*now+c;
    }cout<<ans<<"\n";
    return 0;
}
