//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";

const int z=10005;
int n,tot=0,val[z],pri[z],sz[z],rs[z],ls[z];
void up(int x){sz[x]=sz[rs[x]]+sz[ls[x]]+1;}
int merge(int a,int b){
    if(!a||!b) return a+b;
    if(pri[a]<pri[b]){
        rs[a]=merge(rs[a],b);
        up(a); return a;
    }else{
        ls[b]=merge(a,ls[b]);
        up(b); return b;
    }
}
void split(int p,int &a,int &b,int k){
    if(!p) return a=b=0,void();
    if(val[p]<=k) a=p,split(rs[p],rs[a],b,k);
    else b=p,split(ls[p],a,ls[b],k);
    up(p);
}
int node(int x){
    val[++tot]=x;
    pri[tot]=rand();
    sz[tot]=1;
    return tot;
}
void insert(int &x,int k){
    int a,b;
    split(x,a,b,k);
    x=merge(a,merge(node(k),b));
}
int kth(int x,int k){
    while(1){
        if(sz[ls[x]]+1==k) return x;
        if(sz[ls[x]]>=k) x=ls[x];
        else k-=sz[ls[x]]+1,x=rs[x];
    }
}
int main(){Rosario
    srand(time(0));
    int a,b,x,y,z,rt=0;
    insert(rt,-2147483647);
    insert(rt,2147483647);
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a==1){
            split(rt,x,y,b-1);
            cout<<sz[x]<<"\n";
            rt=merge(x,y);
        }else if(a==2) {cout<<val[kth(rt,b+1)]<<"\n";
        }else if(a==3){
            split(rt,x,y,b-1);
            cout<<val[kth(x,sz[x])]<<"\n";
            rt=merge(x,y);
        }else if(a==4){
            split(rt,x,y,b);
            cout<<val[kth(y,1)]<<"\n";
            rt=merge(x,y);
        }else insert(rt,b);
    }
//    system("pause");
    return 0;
}
