#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int MAXN=1e5+1,MAXM=MAXN*60;
int fa[MAXN],n,cnt,m,rt[MAXN],ls[MAXM],rs[MAXM],sum[MAXM],id[MAXM];
vector<int> v[MAXN];

int fin(int x){return x==fa[x]?x:fa[x]=fin(fa[x]);}

void up(int x){sum[x]=sum[ls[x]]+sum[rs[x]];}

void modify(int &rt,int l,int r,int x,int idx){
    if(!rt) rt=++cnt;
    if(l==r) return sum[rt]++,id[rt]=idx,void();
    int mid=l+r>>1;
    if(x<=mid) modify(ls[rt],l,mid,x,idx);
    else modify(rs[rt],mid+1,r,x,idx);
    up(rt);
}

int merge(int l,int r,int x,int y){
    if(!x||!y) return x|y;
    int mid=l+r>>1;
    if(l==r) return sum[x]+=sum[y],id[x]=id[y],x;
    ls[x]=merge(l,mid,ls[x],ls[y]);
    rs[x]=merge(mid+1,r,rs[x],rs[y]);
    up(x);
    return x;
}

int query(int l,int r,int x,int rt){
    if(sum[rt]<x) return -1;
    if(l==r) return id[rt];
    int mid=l+r>>1;
    if(sum[ls[rt]]>=x) return query(l,mid,x,ls[rt]);
    else return query(mid+1,r,x-sum[ls[rt]],rs[rt]);
}

int main(){Rosario
    cin>>n>>m;
    int x,y;
    char ch;
    for(int i=1;i<=n;++i){
        cin>>x; fa[i]=i;
        modify(rt[i],1,n,x,i);
    }
    while(m--){
        cin>>x>>y;
        x=fin(x),y=fin(y);
        fa[y]=x; rt[x]=merge(1,n,rt[x],rt[y]);
    }
    cin>>m;
    while(m--){
        cin>>ch>>x>>y;
        if(ch=='Q') cout<<query(1,n,y,rt[fin(x)])<<"\n";
        else{
            x=fin(x),y=fin(y);
            fa[y]=x; rt[x]=merge(1,n,rt[x],rt[y]);
        }
    }
    return 0;
}
