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

int n,mx[100000<<2],a,b;
void build(int l,int r,int rt){
    if(l==r){cin>>mx[rt];mx[rt]++;return;}
    int m=l+r>>1;
    build(l,m,rt<<1),build(m+1,r,rt<<1|1);
    mx[rt]=min(mx[rt<<1],mx[rt<<1|1]);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return mx[rt];
    int m=l+r>>1;
    if(qr<=m) return query(l,m,ql,qr,rt<<1);
    else if(ql>m) return query(m+1,r,ql,qr,rt<<1|1);
    else return min(query(l,m,ql,qr,rt<<1),query(m+1,r,ql,qr,rt<<1|1));
}
int main(){
    //oi;
    cin>>n;
    build(0,n-1,1);
    REP(i,n){
        cin>>a>>b;
        cout<<query(0,n-1,a-1,b-1,1)<<"\n";
    }
//    system("pause");
    return 0;
}

