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
#define int long long
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

pii operator-(pii a,pii b){return mkp(a.F-b.F,a.S-b.S);}
int cross(pii a,pii b){return a.F*b.S-a.S*b.F;}
int ori(pii a,pii b,pii c){
    int x=cross(b-a,c-a);
    if(x==0) return 0;
    return x>0?1:-1;
}
bool cmp(pii a,pii b){return a.F==b.F?a.S<b.S:a.F<b.F;}
pii p[100005],st[100005];
int n,idx=0,idx2;
main(){Rosario
    cin>>n;
    REP(i,n) cin>>p[i].F>>p[i].S;
    sort(p,p+n);
    REP(i,n){
        while(idx>1&&ori(st[idx-2],st[idx-1],p[i])<=0) idx--;
        st[idx++]=p[i];
    }idx2=idx;
    for(int i=n-1;i>=0;i--){
        while(idx2-idx>0&&ori(st[idx2-2],st[idx2-1],p[i])<=0) idx2--;
        st[idx2++]=p[i];
    }idx2--;
    cout<<idx2<<"\n";
//    system("pause");
//    return 0;
}
