//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

double ma=0;
ll sum=0,n,a[300005];
int main(){
    oi;
    cin>>n;
    REP(i,n) cin>>a[i];
    sort(a,a+n,greater<ll>());
    REP(i,n){
        sum+=a[i];
        ma=max(ma,(double)sum*sum/(i+1.));
    }
    cout<<fixed<<setprecision(8)<<ma<<"\n";
//    system("pause");
    return 0;
}
