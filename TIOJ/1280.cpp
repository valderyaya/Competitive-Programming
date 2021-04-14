//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

pii operator-(pii a,pii b){return mkp(a.F-b.F,a.S-b.S);}
int dot(pii a,pii b){return a.F*b.F+a.S*b.S;}
int cross(pii a,pii b){return a.F*b.S-a.S*b.F;}
int ori(pii a,pii b,pii c){
    int x=cross(b-a,c-a);
    if(x==0) return 0;
    return x>0?1:-1;
}
bool cmp(pii a,pii b){return a.F==b.F?a.S<b.S:a.F<b.F;}
int idx=0,n,idx2;
ll sum=0;
pii a[10005],p[10005];
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i].F>>a[i].S;
    sort(a,a+n,cmp);
    REP(i,n){
        while(idx>1&&ori(p[idx-2],p[idx-1],a[i])<=0) idx--;
        p[idx++]=a[i];
    }idx2=idx;
    for(int i=n-1;i>=0;--i){
        while(idx2>idx&&ori(p[idx2-2],p[idx2-1],a[i])<=0) idx2--;
        p[idx2++]=a[i];
    }idx2--;
    REP(i,idx2) sum+=cross(p[i],p[i+1]);
    cout<<(abs(sum)+1)/2<<"\n";
    return 0;
}
