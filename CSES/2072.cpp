#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 
string s;
const int z=2e5+5;
int n,m,rt,tot,ch[z][2],sz[z],pri[z],val[z];
int node(int x){
    sz[++tot]=1;
    val[tot]=x;
    pri[tot]=rand();
    return tot;
}
void up(int x){sz[x]=1+sz[ch[x][0]]+sz[ch[x][1]];}
int merge(int a,int b){
    if(!a||!b) return a|b;
    if(pri[a]<pri[b]){
        ch[a][1]=merge(ch[a][1],b);
        up(a); return a;
    }else {
        ch[b][0]=merge(a,ch[b][0]);
        up(b); return b;
    }
}
void split(int p,int &x,int &y,int k){
    if(!p) return x=y=0,void();
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
    print(ch[p][0]);
    cout<<s[val[p]];
    print(ch[p][1]);
}
signed main(){io
    srand(time(0));
    cin>>n>>m>>s;
    for(int i=0;i<n;++i) rt=merge(rt,node(i));
    for(int x,y;m--;){
        cin>>x>>y;
        if(x>y) swap(x,y);
        int a=0,b=0,c=0;
        split(rt,a,b,y);
        split(a,a,c,x-1);
        rt=merge(a,merge(b,c));
    }
    print(rt);
}
