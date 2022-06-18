//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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

int n,idx=0,idx2;
pii p[50005],st[50005];
pii operator-(pii a,pii b){return mkp(a.F-b.F,a.S-b.S);}
int dis(pii a,pii b){
    int x=a.F-b.F,y=a.S-b.S;
    return x*x+y*y;
}
int cross(pii a,pii b){return a.F*b.S-a.S*b.F;}
int ori(pii a,pii b,pii c){
    int x=cross(b-a,c-a);
    if(x==0) return 0;
    return x>0?1:-1;
}
bool cmp(pii a,pii b){return a.F==b.F?a.S<b.S:a.F<b.F;}
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>p[i].F>>p[i].S;
    sort(p,p+n,cmp);
    REP(i,n){
        while(idx>1&&ori(st[idx-2],st[idx-1],p[i])<=0) idx--;
        st[idx++]=p[i];
    }idx2=idx;
    for(int i=n-1;i>=0;i--){
        while(idx2-idx>0&&ori(st[idx2-2],st[idx2-1],p[i])<=0) idx2--;
        st[idx2++]=p[i];
    }idx2--;
    int j=2,ans=0;
    REP(i,idx2){
        while(abs(cross(st[i]-st[j],st[i+1]-st[j]))<abs(cross(st[i]-st[j+1],st[i+1]-st[j+1]))){
            j++;
            if(j==idx2) j=0;
        }
        ans=max(ans,dis(st[i],st[j]));
    }cout<<ans<<"\n";
//    system("pause");
    return 0;
}
