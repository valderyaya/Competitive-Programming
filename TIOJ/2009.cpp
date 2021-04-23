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

ll n,k,m,a[10005],b[10005];
int main(){
    oi;
    cin>>n>>k;
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    bool ck=0;
    m=0;
    REP(i,n-k+1){
        if(a[i]!=b[i]){
            ll p=b[i]-a[i];
            if(p<0) p+=9;
            for(ll j=i,c=0;c<k;j++,c++){
                a[j]+=p;
                if(a[j]>9) a[j]-=9;
            }
            m+=p;
        }
    }
    REP(i,n){
        if(a[i]!=b[i]){
            ck=1;break;
        }
    }
    cout<<(ck?0:m)<<"\n";
//    system("pause");
    return 0;
}
