//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
 
const int z=505,zz=60005;
int read(){
    int x=0; char c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x;
}
int n,q,id[zz],cur[zz],idx,ans[zz],q1[zz],q2[zz];
struct matrix{
    int x,y,val;
    bool operator<(const matrix &v)const{return val<v.val;}
}m[z*z];
struct qwq{int x1,y1,x2,y2,k;}que[zz];
struct BIT{
    int Bit[z][z]={};
    void add(int x,int y,int v){
        for(;x<=n;x+=lb(x))
            for(int j=y;j<=n;j+=lb(j))
                Bit[x][j]+=v;
    }
    int qry(int x,int y){
        int res=0;
        for(;x;x-=lb(x))
            for(int j=y;j;j-=lb(j))
                res+=Bit[x][j];
        return res;
    }
    int get_(int x1,int y1,int x2,int y2){
        return qry(x2,y2)-qry(x1-1,y2)-qry(x2,y1-1)+qry(x1-1,y1-1);
    }
}bit;
void solve(int l,int r,int ql,int qr){
    if(ql>qr) return;
    if(l==r){
        REP1(i,ql,qr) ans[id[i]]=m[l].val;
        return;
    }
    int mid=l+r>>1,id1=0,id2=0,id3=ql-1;
    REP1(i,l,mid) bit.add(m[i].x,m[i].y,1);
    REP1(i,ql,qr){
        int p=id[i],s;
        s=cur[p]+bit.get_(que[p].x1,que[p].y1,que[p].x2,que[p].y2);
        if(s>=que[p].k) q1[++id1]=p;
        else q2[++id2]=p,cur[p]=s;
    }
    REP1(i,1,id1) id[++id3]=q1[i];
    REP1(i,1,id2) id[++id3]=q2[i];
    REP1(i,l,mid) bit.add(m[i].x,m[i].y,-1);
    solve(l,mid,ql,ql+id1-1); solve(mid+1,r,ql+id1,qr);
}
signed main(){//Rosario
    n=read(),q=read();
    REP1(i,1,n) REP1(j,1,n) m[++idx]=matrix{i,j,read()};
    REP1(i,1,q) id[i]=i,que[i]=qwq{read(),read(),read(),read(),read()};
    sort(m+1,m+idx+1);
    solve(1,idx,1,q);
    REP1(i,1,q) printf("%d\n",ans[i]);
    return 0;
}
