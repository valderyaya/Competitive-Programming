#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

ll ans=0;
void mer(ll l,ll r,ll a[]){
    ll i=l,m=l+r>>1,j=m+1,t[100001],k=l;
    while(i<=m&&j<=r){
        if(a[i]>a[j]){
            t[k++]=a[j++];ans+=m-i+1;
        }else t[k++]=a[i++];
    }
    while(i<=m)t[k++]=a[i++];
    while(j<=r)t[k++]=a[j++];
    for(i=l;i<=r;i++)a[i]=t[i];
}
void merges(ll l,ll r,ll a[]){
    if(l>=r) return;
    int m=l+r>>1;
    merges(l,m,a),merges(m+1,r,a);
    mer(l,r,a);
}
int main(){
    oi;
    ll n,a[100001],cnt=1;
    while(cin>>n,n){
        ans=0;
        REP(i,n)cin>>a[i];
        merges(0,n-1,a);
        cout<<"Case #"<<cnt++<<": "<<ans<<"\n";
    }
//    system("pause");
    return 0;
}
