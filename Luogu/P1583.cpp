#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

struct as{ll id,w;}q[200005];
ll n,m,a[15];
bool cmp(as x,as y){return x.w==y.w?x.id<y.id:x.w>y.w;}
int main(){
    oi;
    cin>>n>>m;
    REP1(i,1,10) cin>>a[i];
    REP1(i,1,n){
        cin>>q[i].w;
        q[i].id=i;
    }
    sort(q+1,q+1+n,cmp);
    REP1(i,1,n) q[i].w+=a[(i-1)%10+1];
    sort(q+1,q+1+n,cmp);
    REP1(i,1,m) cout<<q[i].id<<' ';
//    system("pause");
    return 0;
}
