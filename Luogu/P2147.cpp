#include<bitset>
#include<unistd.h>
#include<vector>
#include<map>
using namespace std;
#define F first
#define S second
#define pii pair<int,int>
#define em emplace_back

void rd(int &x){
    x=0;char c=getchar_unlocked();
    while(c<'0'||c>'9') c=getchar_unlocked();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar_unlocked();
}
const int z=200005;
int n,m,pa[10005],rk[10005],idx;
pii st[z],v[z];
vector<int> seg[z<<1];
bitset<z> qry;
#define rt(l,r) l+r|l!=r
void mdf(int l,int r,int ql,int qr,int id){
    if(l>r||ql>r||qr<l) return;
    if(ql<=l&&r<=qr) return seg[rt(l,r)].em(id),void();
    int mid=l+r>>1;
    if(ql<=mid) mdf(l,mid,ql,qr,id);
    if(qr>mid) mdf(mid+1,r,ql,qr,id);
}
int fin(int x){
    while(x!=pa[x]) x=pa[x];
    return x;
}
void merge(int x,int y){
    int px=fin(x), py=fin(y);
    if(px==py) return;
    if(rk[px]>rk[py]) swap(px,py);
    st[++idx]={px, rk[px]};
    pa[px] = py;
    rk[py] += rk[px];
}
void back(){
    rk[pa[st[idx].F]]-=st[idx].S;
    pa[st[idx].F]=st[idx].F;
    --idx;
}
void dfs(int l,int r){
    int mid=l+r>>1,sz=idx;
    for(auto &i:seg[rt(l,r)])
        merge(v[i].F,v[i].S);
    if(l==r){
        if(qry[l]) puts(fin(v[l].F)==fin(v[l].S)?"Yes":"No");
    }else{
        dfs(l,mid);
        dfs(mid+1,r);
    }
    while(idx>sz) 
        back();
}
map<pii,int> mp;
int main(){//Rosario
    rd(n),rd(m);
    for(int i=1;i<=n;++i) pa[i]=i,rk[i]=1;
    char s[10];
    for(register int i=1;i<=m;++i){
        scanf("%s",s),rd(v[i].F),rd(v[i].S);
        if(v[i].F>v[i].S) swap(v[i].F,v[i].S);
        if(s[0]=='Q') qry[i]=1;        
        else if(s[0]=='C') mp[{v[i].F,v[i].S}]=i;
        else if(s[0]=='D'){
            mdf(1,m,mp[{v[i].F,v[i].S}],i-1,i);
            mp.erase({v[i].F,v[i].S});
        }
    }
    for(auto &i:mp) mdf(1,m,i.S,m,i.S);
    dfs(1,m);
    return 0;
}
