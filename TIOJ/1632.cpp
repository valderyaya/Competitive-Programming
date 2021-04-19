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
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)


int n,m,a[200005];
ll k;
bool ck(int x){
    ll c=0;
    for(int i=1,j=1;i<=n&&c<k;i++){
        for(;j<i;j++){
            if(a[i]-a[j]<=x){
                c+=i-j;
                break;
            }
        }
    }
    return c>=k;
}
int main(){Rosario
    cin>>n>>k;
    REP1(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    ll l=0,r=a[n]-a[1];
    while(l<r){
        m=(l+r)>>1;
        if(ck(m)) r=m;
        else l=m+1;
    }
    cout<<l<<"\n";
//    system("pause");
    return 0;
}
