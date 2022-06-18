#include<bits/stdc++.h>
using namespace std;
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define Alicization ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int z=5e5+50;
int n,m,pri[z],lc[z],rc[z],sum[z],val[z],sz[z],mx[z],lmx[z],rmx[z],st[z],top,tot,rt;
bool cov[z],fp[z];
int node(int v){
    int id=top?st[top--]:++tot;
    lc[id]=rc[id]=cov[id]=fp[id]=0;
    pri[id]=rand(), sz[id]=1;
    val[id]=sum[id]=mx[id]=v;
    lmx[id]=rmx[id]=max(0,v);
    return id;
}
void cover(int p,int v){
    val[p]=v; cov[p]=1;
    sum[p]=sz[p]*v;
    lmx[p]=rmx[p]=max(0,sum[p]);
    mx[p]=max(sum[p],v);
}
void rev(int p){
    swap(lc[p],rc[p]);
    swap(lmx[p],rmx[p]);
    fp[p]^=1;
}
void down(int p){
    if(!p) return;
    if(cov[p]){
        cov[p]=0;
        cover(lc[p],val[p]);
        cover(rc[p],val[p]);
    }
    if(fp[p]){
        fp[p]=0;
        rev(lc[p]);
        rev(rc[p]);
    }
}
void up(int p){
    sz[p]=sz[lc[p]]+sz[rc[p]]+1;
    sum[p]=sum[lc[p]]+sum[rc[p]]+val[p];
    lmx[p]=max(lmx[lc[p]],sum[lc[p]]+val[p]+lmx[rc[p]]);
    rmx[p]=max(rmx[rc[p]],sum[rc[p]]+val[p]+rmx[lc[p]]);
    mx[p]=rmx[lc[p]]+val[p]+lmx[rc[p]];
    if(lc[p]) mx[p]=max(mx[p],mx[lc[p]]);
    if(rc[p]) mx[p]=max(mx[p],mx[rc[p]]);
}
int merge(int a,int b){
    if(!a||!b) return a|b;
    if(pri[a]<pri[b]){
        down(a);
        rc[a]=merge(rc[a],b);
        up(a);
        return a;
    }else{
        down(b);
        lc[b]=merge(a,lc[b]);
        up(b);
        return b;
    }
}
void split(int p,int &a,int &b,int k){
    if(!p) return a=b=0,void();
    down(p);
    if(sz[lc[p]]<k){
        a=p;
        split(rc[p],rc[a],b,k-sz[lc[p]]-1);
    }else{
        b=p;
        split(lc[p],a,lc[b],k);
    }
    up(p);
}
void clean(int p){
    if(!p) return;
    st[++top]=p;
    clean(lc[p]);
    clean(rc[p]);
}
void del(int pos,int len){
    int a=0,b=0,c=0;
    split(rt,a,b,pos-1);
    split(b,b,c,len);
    rt=merge(a,c);
    clean(b);
}
void reverse(int pos,int len){
    int a=0,b=0,c=0;
    split(rt,a,b,pos-1);
    split(b,b,c,len);
    rev(b);
    rt=merge(a,merge(b,c));
}
void SUM(int pos,int len){
    int a=0,b=0,c=0;
    split(rt,a,b,pos-1);
    split(b,b,c,len);
    cout<<sum[b]<<"\n";
    rt=merge(a,merge(b,c));
}
void maxsum(int pos,int len){
    int a=0,b=0,c=0;
    split(rt,a,b,pos-1);
    split(b,b,c,len);
    cout<<mx[b]<<"\n";
    rt=merge(a,merge(b,c));
}
void ins(int pos,int len){
    int a=0,b=0,p=0,x;
    while(len--) cin>>x,p=merge(p,node(x));
    split(rt,a,b,pos);
    rt=merge(a,merge(p,b));
}
void same_(int pos,int len){
    int a=0,b=0,c=0,x;
    cin>>x;
    split(rt,a,b,pos-1);
    split(b,b,c,len);
    cover(b,x);
    rt=merge(a,merge(b,c));
}
signed main(){Alicization
    srand(time(0));
    cin>>n>>m;
    for(int x;n--;) cin>>x,rt=merge(rt,node(x));
    string s;
    for(int pos,len;m--;){
        cin>>s;
        if(s[0]=='I') cin>>pos>>len,ins(pos,len);
        else if(s[0]=='D') cin>>pos>>len,del(pos,len);
        else if(s[0]=='R') cin>>pos>>len,reverse(pos,len);
        else if(s[0]=='G') cin>>pos>>len,SUM(pos,len);
        else if(s[2]=='K') cin>>pos>>len,same_(pos,len);
        else cout<<mx[rt]<<"\n";
    }
    return 0;
}
