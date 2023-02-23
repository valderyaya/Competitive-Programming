//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair9

string s;
const int z=2e5+5;
int n,m,rt,tot,laz[z],ch[z][2],sz[z],pri[z];
char val[z];
int node(char x){
    sz[++tot]=1;
    val[tot]=x;
    pri[tot]=rand();
    return tot;
}
void up(int x){sz[x]=1+sz[ch[x][0]]+sz[ch[x][1]];}
void down(int x){
    if(x&&laz[x]){
        swap(ch[x][0],ch[x][1]);
        if(ch[x][0]) laz[ch[x][0]]^=1;
        if(ch[x][1]) laz[ch[x][1]]^=1;
        laz[x]=0;
    }
}
int merge(int a,int b){
    if(!a||!b) return a|b;
    if(pri[a]<pri[b]){
        down(a);
        ch[a][1]=merge(ch[a][1],b);
        up(a); return a;
    }else {
        down(b);
        ch[b][0]=merge(a,ch[b][0]);
        up(b); return b;
    }
}
void split(int p,int &x,int &y,int k){
    if(!p) return x=y=0,void();
    down(p);
    if(sz[ch[p][0]]+1<=k){
        x=p;
        split(ch[p][1],ch[x][1],y,k-1-sz[ch[p][0]]);
    }else{
        y=p;
        split(ch[p][0],x,ch[y][0],k);
    }
    up(p);
}
void print(int p){
    if(!p) return;
    down(p);
    print(ch[p][0]);
    cout<<val[p];
    print(ch[p][1]);
}
signed main(){StarBurstStream
    srand(time(0));
    cin>>n>>m>>s;
    for(int i=0;i<n;++i) rt=merge(rt,node(s[i]));
    for(int x,y;m--;){
        cin>>x>>y;
        if(x>y) swap(x,y);
        int a=0,b=0,c=0;
        split(rt,a,b,y);
        split(a,a,c,x-1);
        laz[c]^=1;
        rt=merge(a,merge(c,b));
    }
    print(rt);
}
