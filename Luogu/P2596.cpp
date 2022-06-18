//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=8e4+5;
int fa[z],ch[z][2],id[z],val[z],pri[z],sz[z],cnt,n,m,rt;
int node(int x){
    sz[++cnt]=1;
    pri[cnt]=rand();
    val[cnt]=x;
    return id[x]=cnt;
} 
void up(int x){
    sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}
int merge(int a,int b){
    if(!a||!b) return a+b;
    if(pri[a]<pri[b]){
        ch[a][1]=merge(ch[a][1],b);
        fa[ch[a][1]]=a; up(a); return a;
    }
    ch[b][0]=merge(a,ch[b][0]);
    fa[ch[b][0]]=b; up(b); return b;
}
void split(int p,int &a,int &b,int k,int fA=0,int fb=0){
    if(!p) return a=b=0,void();
    if(sz[ch[p][0]]<k){
        fa[p]=fA, a=p;
        split(ch[p][1],ch[a][1],b,k-sz[ch[a][0]]-1,a,fb);
    }else{
        fa[p]=fb, b=p;
        split(ch[p][0],a,ch[b][0],k,fA,b);
    } up(p);
}
int fin(int x){
    int res=sz[ch[x][0]]+1;
    while(fa[x]){
        if(x==ch[fa[x]][1]) res+=sz[ch[fa[x]][0]]+1;
        x=fa[x];
    }
    return res;
}
int main(){Rosario
    srand(time(0));
    cin>>n>>m;
    for(int x,i=1;i<=n;++i) cin>>x,rt=merge(rt,node(x));
    string s;
    for(int x,y,a,b,c,d;m;--m){
        cin>>s>>x;
        if(s[0]=='T'){
            split(rt,a,c,fin(id[x])-1);
            split(c,b,c,1);
            rt=merge(b,merge(a,c));
        }else if(s[0]=='B'){
            split(rt,a,c,fin(id[x])-1);
            split(c,b,c,1);
            rt=merge(a,merge(c,b));
        }else if(s[0]=='I'){
            cin>>y;
            if(y>0){
                split(rt,a,b,fin(id[x])-1);
                split(b,b,c,1);
                split(c,c,d,1);
                rt=merge(a,merge(c,merge(b,d)));
            }else if(y<0){
                int tmp=fin(id[x]);
                split(rt,a,b,tmp-1);
                split(b,b,c,1);
                split(a,a,d,tmp-2);
                rt=merge(a,merge(b,merge(d,c)));
            }
        }else if(s[0]=='A'){
            cout<<fin(id[x])-1<<"\n";
        }else{
            split(rt,a,b,x-1);
            split(b,b,c,1);
            cout<<val[b]<<"\n";
            rt=merge(a,merge(b,c));
        }
    }
    return 0;
}
