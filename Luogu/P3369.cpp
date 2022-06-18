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

const int z=1e5+5;
int val[z],ch[z][2],n,cnt=0,pri[z],sz[z],rt=0;
int node(int x){
    sz[++cnt]=1;
    val[cnt]=x;
    pri[cnt]=rand();
    return cnt;
}
void up(int x){
    sz[x]=1+sz[ch[x][0]]+sz[ch[x][1]];
    
}
int merge(int a,int b){
    if(!a||!b) return a|b;
    if(pri[a]<pri[b]){
        ch[a][1]=merge(ch[a][1],b);
        up(a);
        return a;
    }else{
        ch[b][0]=merge(a,ch[b][0]);
        up(b);
        return b;
    }
}
void split(int p,int &a,int &b,int k){
    if(!p) return a=b=0,void();
    if(val[p]<k){
        a=p;
        split(ch[p][1],ch[a][1],b,k);
    }else{
        b=p;
        split(ch[p][0],a,ch[b][0],k);
    }
    up(p);
}
// void split2(int p,int &a,int &b,int k){
//     if(!p) return a=b=0,void();
//     if(sz[ch[p][0]]+1<=k) a=p,split2(ch[p][1],ch[a][1],b,k);
//     else b=p,split2(ch[p][0],a,ch[b][0],k);
//     up(p);
// }
void erase(int k){
    int a,b,c;
    split(rt,a,b,k);
    split(b,b,c,k+1);
    b=merge(ch[b][0],ch[b][1]);
    rt=merge(a,merge(b,c));
}
int kth(int p,int k){
    if(sz[ch[p][0]]+1==k) return val[p];
    if(sz[ch[p][0]]+1>k) return kth(ch[p][0],k);
    else return kth(ch[p][1],k-sz[ch[p][0]]-1);
}
int rk(int k){
    int a,b,c;
    split(rt,a,b,k);
    c=sz[a]+1;
    rt=merge(a,b);
    return c;
}
int pre(int k){
    int a,b,c;
    split(rt,a,b,k);
    c=kth(a,sz[a]);
    rt=merge(a,b);
    return c;
}
int nxt(int k){
    int a,b,c;
    split(rt,a,b,k+1);
    c=kth(b,1);
    rt=merge(a,b);
    return c;
}
void insert(int k){
    int a,b;
    split(rt,a,b,k);
    rt=merge(a,merge(node(k),b));
}
int main(){Rosario
    srand(time(0));
    int opt,x;
    cin>>n;
    while(n--){
        cin>>opt>>x;
        if(opt==1) insert(x);
        else if(opt==2) erase(x);
        else if(opt==3) cout<<rk(x)<<"\n";
        else if(opt==4) cout<<kth(rt,x)<<"\n";
        else if(opt==5) cout<<pre(x)<<"\n";
        else if(opt==6) cout<<nxt(x)<<"\n";
    }
    return 0;
}
