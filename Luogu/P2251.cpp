// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int mi[1000000<<2];
void build(int l,int r,int rt){
    if(l==r){cin>>mi[rt];return;}
    int m=(l+r)>>1;
    build(l,m,rt<<1),build(m+1,r,rt<<1|1);
    mi[rt]=min(mi[rt<<1],mi[rt<<1|1]);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr){return mi[rt];}
    int m=l+r>>1;
    if(qr<=m)return query(l,m,ql,qr,rt<<1);
    else if(ql>m) return query(m+1,r,ql,qr,rt<<1|1);
    else return min(query(l,m,ql,qr,rt<<1),query(m+1,r,ql,qr,rt<<1|1));
}
int main(){
    oi;
    int n,m,a,b;
    cin>>n>>m;
    build(0,n-1,1);
    for(a=0,b=m-1;b<n;b++,a++){
        cout<<query(0,n-1,a,b,1)<<"\n";
    }
//    system("pause");
    return 0;
}
