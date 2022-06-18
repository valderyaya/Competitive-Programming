#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int n,m,fa[5005],cnt;
struct edge{
    int u,v,w;
    // bool operator<(const edge &tmp)const{
    //     return w<tmp.w;
    // }
}e[200005];
long long ans;
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int main(){Rosario
    cin>>n>>m;
    for(int x,y,z,i=0;i<m;++i){
        cin>>x>>y>>z;
        e[i]=edge{x,y,z};
    }
    for(int i=1;i<=n;++i) fa[i]=i;
    sort(e,e+m,[&](edge x,edge y){return x.w<y.w;});
    cnt=n;
    for(int i=0;i<m;++i){
        int x=getfa(e[i].u), y=getfa(e[i].v);
        if(x!=y){
            --cnt;
            fa[x]=y;
            ans+=e[i].w;
        }
        if(cnt==1) break;
    }
    if(cnt!=1) cout<<"orz\n";
    else cout<<ans<<"\n";
    return 0;
}

// 5  (1,4)  1
// 5  (3,5)  1
// 6  (4,6)  1
// 7  (1,2)  1
// 7  (2,5)  1
// 8  (2,3)  0
// 8  (5,6)  0
// 9  (5,7)  1
// 9  (2,4)  0
// 11 (6,7)  0
// 15 (4,5)  0
