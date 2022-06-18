#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

int n,m;
double s[100005];
struct qq{
    double mx;
    int cnt;
}seg[100005<<2];
int up(int l,int r,int rt,double x){
    if(l==r) return s[l]>x;
    if(x<s[l]) return seg[rt].cnt;
    if(x>=seg[rt].mx) return 0;
    int mid=l+r>>1;
    if(seg[rt<<1].mx<=x) return up(mid+1,r,rt<<1|1,x);
    else return up(l,mid,rt<<1,x)+seg[rt].cnt-seg[rt<<1].cnt;
}
void mod(int l,int r,int rt,int x,int y){
    if(l==r&&l==x) return seg[rt].mx=s[x],seg[rt].cnt=1,void();
    int mid=l+r>>1;
    if(x<=mid) mod(l,mid,rt<<1,x,y);
    else if(x>mid) mod(mid+1,r,rt<<1|1,x,y);
    seg[rt].mx=max(seg[rt<<1].mx,seg[rt<<1|1].mx);
    seg[rt].cnt=seg[rt<<1].cnt+up(mid+1,r,rt<<1|1,seg[rt<<1].mx);
}
int x,y;
int main(){Rosario
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        s[x]=(double)y/x;
        mod(1,n,1,x,y);
        cout<<seg[1].cnt<<"\n";
    }
//    system("pause");
    return 0;
}
