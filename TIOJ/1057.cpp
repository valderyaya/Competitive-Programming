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
#define oi ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll>


ll n,m,p,x,a[105];
int main(){
    oi;
    cin>>n>>p>>m;
    REP(i,m) cin>>a[i];
    a[m]=p;
    ll cnt=0,now=0;
    for(int i=0;i<=m;i++){
        if(a[i]-now>n){cout<<"IMPOSSIBLE\n";return 0;}
        else{
            if(a[m]-now<=n){cnt++;break;}
            if(i+1<n&&a[i+1]-now<=n) continue;
            else{
                now=a[i];cnt++;
            }
        }
    }
    cout<<cnt-1<<"\n";
//    system("pause");
    return 0;
}
