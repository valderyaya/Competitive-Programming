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
 
int n;
void dfs(int a,int b,int c,int d){
    if(d==1) return cout<<a<<' '<<c<<"\n",void();
    else{
        dfs(a,c,b,d-1);
        cout<<a<<' '<<c<<"\n";
        dfs(b,a,c,d-1);
    }
}
signed main(){Aincrad
    cin>>n;
    cout<<(1<<n)-1<<"\n";
    dfs(1,2,3,n);
    return 0;
}
