#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
// #define lb(x) (x&-x)


int n,m,mi=1e9+5,a[100005],b[100005];
int main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>a[i];
    REP(i,m) cin>>b[i];
    sort(a,a+n),sort(b,b+m);int i=0,j=0;
    while(i<n&&j<m){
        mi=min(mi,abs(a[i]-b[j]));
        if(a[i]<b[j]) i++;
        else j++;
    }cout<<mi<<"\n";
//    system("pause");
    return 0;
}
