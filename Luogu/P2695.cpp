//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";

int n,m,a[20005],b[20005],sum=0;
int main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>a[i];
    REP(i,m) cin>>b[i];
    if(n>m){cout<<"you died!\n";return 0;}
    sort(a,a+n);sort(b,b+m);
    int i=0,j=0;
    for(;i<n;++i){
        while(a[i]>b[j]&&j<m) j++;
        if(j==m) break;
        sum+=b[j++];
    }
    if(i==n) cout<<sum<<"\n";
    else cout<<"you died!\n";
//    system("pause");
    return 0;
}
