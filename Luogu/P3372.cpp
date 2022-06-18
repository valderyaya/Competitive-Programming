#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x

ll n,m,bit[2][100005],a[100001];
void add(ll i,ll x,ll id){
    for(;i<=n;i+=lb(i))
        bit[id][i]+=x;
}
ll qry(ll r,ll id){
    ll ret=0;
    for(;r;r-=lb(r)) ret+=bit[id][r];
    return ret;
}
int main(){Rosario
    cin>>n>>m>>a[1];
    add(1,a[1],0); add(1,a[1],1);
    REP1(i,2,n) cin>>a[i],add(i,a[i]-a[i-1],0),add(i,i*(a[i]-a[i-1]),1);
    for(ll op,x,y,k;m--;){
        cin>>op>>x>>y;
        if(op==1){
            cin>>k;
            add(x,k,0);
            add(y+1,-k,0);
            add(x,x*k,1);
            add(y+1,-(y+1)*k,1);
        }else cout<<(((y+1)*qry(y,0)-qry(y,1))-(x*qry(x-1,0)-qry(x-1,1)))<<"\n";
    }

}
