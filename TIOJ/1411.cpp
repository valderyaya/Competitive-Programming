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

const int z=1e6;
int a[z<<1|1],x,s1,s2,n,mx;
int main(){Rosario
    while(cin>>n){
        s1=s2=mx=0;
        memset(a,0,sizeof(a));
        REP1(i,1,n){
            cin>>x;
            s1+=(x>0),s2+=(x<0);
            x=s1-s2+n;
            if(x==n) mx=max(mx,i);
            else if(!a[x]) a[x]=i;
            else mx=max(mx,i-a[x]);
        }cout<<mx<<"\n";
    }
    return 0;
}
