#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

const int z=100005;
struct line{
    int l,r,c;
    bool operator<(const line &x){return l<x.l;}    
}a[z];
int df[z]={},n,k,m,L[z]={},R[z]={},o[z]={},f[z]={},b[z]={};
int main(){Rosario
    cin>>n>>k>>m;
    REP1(i,1,m){
        cin>>a[i].l>>a[i].r>>a[i].c;
        if(!a[i].c) ++df[a[i].l],--df[a[i].r+1];
    } 
    int now=0,cnt=0;
    REP1(i,1,n){
        now+=df[i];
        if(now==0) L[i]=R[i]=++cnt,o[cnt]=i; 
    }
    if(cnt==k){
        REP1(i,1,cnt) cout<<o[i]<<"\n";
        return 0;
    } 
    L[n+1]=n+1;
    REP1(i,1,n) if(!R[i]) R[i]=R[i-1];
    for(int i=n;i;--i) if(!L[i]) L[i]=L[i+1];
    cnt=0;
    REP1(i,1,m){
        if(!a[i].c) continue;
        int l=L[a[i].l],r=R[a[i].r];
        if(l<=r) a[++cnt].l=l,a[cnt].r=r;
    }
    sort(a+1,a+1+cnt);
    int top=0;
    REP1(i,1,cnt){
        while(top && a[i].l>=L[top] && a[i].r<=R[top]) --top;
        L[++top]=a[i].l , R[top]=a[i].r;
    }
    int l=n+1,r=0,x,y;
    REP1(i,1,top)
        if(L[i]>r) f[i]=f[i-1]+1,r=R[i];
        else f[i]=f[i-1];
    for(int i=top;i;--i)
        if(R[i]<l) b[i]=b[i+1]+1,l=L[i];
        else b[i]=b[i+1];
    bool ck=1;
    //REP1(i,1,top) cout<<f[i]<<' '<<b[i]<<endl;
    REP1(i,1,top){
        if(f[i]==f[i-1]) continue;
        if(L[i]==R[i]){
            cout<<o[R[i]]<<"\n";
            ck=0; continue;
        }
        l=1,r=i-1,x=0,y=top+1;
        while(l<=r){
            int mid=l+r>>1;
            if(R[mid]<R[i]-1) x=mid,l=mid+1;
            else r=mid-1;
        }l=i+1, r=top;
        while(l<=r){
            int mid=l+r>>1;
            if(L[mid]>R[i]-1) y=mid,r=mid-1;
            else l=mid+1;
        }
        //cout<<x<<' '<<y<<endl;
        if(f[x]+b[y]+1>k){
            cout<<o[R[i]]<<"\n";
            ck=0;
        }
    }
    if(ck) cout<<"-1\n";
    return 0;
}
