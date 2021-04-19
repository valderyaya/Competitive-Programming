//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

const int z=130005;
int tot,rev[z],pri[z],ch[z][2],sz[z],val[z];
int node(int x){
    pri[++tot]=rand();
    val[tot]=x;
    return sz[tot]=1,tot;
}
void up(int x){sz[x]=1+sz[ch[x][0]]+sz[ch[x][1]];}
void down(int x){
    if(!x||!rev[x]) return;
    swap(ch[x][0],ch[x][1]);
    rev[x]=0;
    if(ch[x][0]) rev[ch[x][0]]^=1;
    if(ch[x][1]) rev[ch[x][1]]^=1;
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
void split(int &a,int &b,int p,int k){
    if(!p) return a=b=0,void();
    down(p);
    if(sz[ch[p][0]]+1<=k) a=p,split(ch[a][1],b,ch[p][1],k-sz[ch[p][0]]-1);
    else b=p,split(a,ch[b][0],ch[p][0],k);
    up(p);
}
void print(int x){
    if(!x) return;
    down(x);
    print(ch[x][0]);
    cout<<val[x]<<' ';
    print(ch[x][1]);
}
int main(){Rosario
    srand(time(0));
    string s;
    int a,b,c,d,n,m,t1,t2,t3,t4,t5,rt=0;
    cin>>n>>m;
    REP1(i,1,n) rt=merge(rt,node(i));
    while(m--){
        cin>>s>>a>>b;
        if(s[0]=='R'){
            split(t1,t2,rt,a-1);
            split(t2,t3,t2,b-a+1);
            rev[t2]^=1;
            rt=merge(merge(t1,t2),t3);
        }else{
            cin>>c>>d;
            split(t1,t2,rt,a-1);
            split(t2,t3,t2,b-a+1);
            split(t3,t4,t3,c-b-1);
            split(t4,t5,t4,d-c+1);
            rt=merge(merge(t1,t4),merge(merge(t3,t2),t5));
        }
    }
    print(rt);
    return 0;
}
