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

int n,m,g[13]={1,1};
string s="ABCDEFGHIJKL",c;
int main(){Rosario
    REP1(i,2,12) g[i]=g[i-1]*i;
    while(cin>>n>>m,n){
        m=(m-1)%g[n];
        c=s; int p;
        for(int i=n-1;i>=0;--i){
            p=m/g[i];
            cout<<c[p]<<' ';
            for(int j=p;j<i;++j) c[j]=c[j+1];
            m%=g[i];
        }
        cout<<"\n";
    }
    return 0;
}
