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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

ll n,a[50005],b[50005];
int main(){Rosario
    while(cin>>n){
        REP(i,n) cin>>a[i];
        REP(i,n) cin>>b[i];
        sort(a,a+n,less<int>());
        sort(b,b+n,less<int>());
        ll sum=0;
        REP(i,n) sum+=a[i]*b[i];
        cout<<sum<<"\n";
    }
//    system("pause");
    return 0;
}
