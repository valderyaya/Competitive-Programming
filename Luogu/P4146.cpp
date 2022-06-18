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
//#define lb(x) (x&-x)


const int z=5e4+5;
int ch[z][2],laz[z],pri[z],mx[z],rev[z],n,m,cnt,sz[z],rt,val[z];
int node(int x){
    mx[++cnt]=x;
    sz[cnt]=1;
    val[cnt]=x;
    pri[cnt]=rand();
    return cnt;
}
void down(int x){
    if(laz[x]){
        if(ch[x][0]) laz[ch[x][0]]+=laz[x],mx[ch[x][0]]+=laz[x],val[ch[x][0]]+=laz[x];
        if(ch[x][1]) laz[ch[x][1]]+=laz[x],mx[ch[x][1]]+=laz[x],val[ch[x][1]]+=laz[x];
        laz[x]=0;
    }
    if(rev[x]) {
        if(ch[x][0]) rev[ch[x][0]]^=1;
        if(ch[x][1]) rev[ch[x][1]]^=1;
        swap(ch[x][0],ch[x][1]),rev[x]=0;
    }
}
void up(int x){
    sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
    mx[x]=val[x];
    if(ch[x][0]) mx[x]=max(mx[x],mx[ch[x][0]]);
    if(ch[x][1]) mx[x]=max(mx[x],mx[ch[x][1]]);
}
int merge(int a,int b){
    if(!a||!b) return a|b;
    if(pri[a]<pri[b]){
        down(a);
        ch[a][1]=merge(ch[a][1],b);
        return up(a),a;
    }else{
        down(b);
        ch[b][0]=merge(a,ch[b][0]);
        return up(b),b;
    }
}
void split(int p,int &a,int &b,int k){
    if(!p) return a=b=0,void();
    down(p);
    if(sz[ch[p][0]]+1<=k){
        a=p;
        split(ch[p][1],ch[a][1],b,k-sz[ch[p][0]]-1);
    }else{
        b=p;
        split(ch[p][0],a,ch[b][0],k);
    }
    up(p);
}
signed main(){Rosario
    srand(time(0));
    cin>>n>>m;
    int a,b,c;
    REP(i,n) rt=merge(rt,node(0));
    for(int l,r,v,op;m;--m){
        cin>>op>>l>>r;
        split(rt,a,b,r);
        split(a,a,c,l-1);
        if(op==1) cin>>v,mx[c]+=v,laz[c]+=v,val[c]+=v;
        else if(op==2) rev[c]^=1;
        else cout<<mx[c]<<"\n";
        rt=merge(a,merge(c,b));
    }
    return 0;
}

/*
0 0 0 0
2 2 2 0
2 1 1 -1
1 1 2 -1
*/
