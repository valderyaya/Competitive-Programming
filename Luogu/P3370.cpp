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
#define wait system("pause");

const int base=127,mod=20190823,mod2=20190847;
int n,cnt=1;
string s;
int hash_(){
    int res=0;
    for(auto &i:s) res=(res*base+i)%mod;
    return res;
}
int _hash(){
    int res=0;
    for(auto &i:s) res=(res*base+i)%mod2;
    return res;
}
pii a[10005];
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>s,a[i]=mkp(hash_(),_hash());
    sort(a,a+n);
    REP1(i,1,n-1) if(a[i].F!=a[i-1].F||a[i].S!=a[i-1].S) ++cnt;
    cout<<cnt;
//    system("pause");
    return 0;
}
