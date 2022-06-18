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

const int z=1e5+2;
int rev[z],val[z],tot=0,pri[z],sz[z],ch[2][z],n,m;
int node(int x){
    pri[++tot]=rand();
    val[tot]=x;
    return sz[tot]=1,tot;
}
void up(int x){
    sz[x]=1+sz[ch[0][x]]+sz[ch[1][x]];
}
void down(int x){
    if(!x || !rev[x]) return;
    swap(ch[0][x],ch[1][x]);
    rev[x]=0;
    if(ch[0][x]) rev[ch[0][x]]^=1;
    if(ch[1][x]) rev[ch[1][x]]^=1;
}
int merge(int a,int b){
    if(!a || !b) return a|b;
    if(pri[a]<pri[b]){
        down(a);
        ch[1][a]=merge(ch[1][a],b);
        return up(a),a;
    }else{
        down(b);
        ch[0][b]=merge(a,ch[0][b]);
        return up(b),b;
    }
}
void split(int &a,int &b,int p,int k){
    if(!p) return a=b=0,void();
    down(p);
    if(sz[ch[0][p]]+1<=k){
        a=p;
        split(ch[1][a],b,ch[1][p],k-sz[ch[0][p]]-1);
    }else{
        b=p;
        split(a,ch[0][b],ch[0][p],k);
    }up(p);
}
void print(int x){
    if(!x) return ;
    down(x);
    print(ch[0][x]);
    cout<<val[x]<<' ';
    print(ch[1][x]);
}
int main(){Rosario
    srand(time(0));
    cin>>n>>m;
    int a,b,c,l,r,rt=0;
    REP1(i,1,n) rt=merge(rt,node(i));
    while(m--){
        cin>>l>>r;
        split(a,b,rt,l-1);
        split(b,c,b,r-l+1);
        rev[b]^=1;
        rt=merge(a,merge(b,c));
    }
    print(rt);
    return 0;
}
