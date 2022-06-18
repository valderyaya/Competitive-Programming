#include<bits/stdc++.h>
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


int q,p[20005],ran[20005],n,m;
int fin(int x){return p[x]==x?x:p[x]=fin(p[x]);}
inline void un(int a,int b){
    if(ran[a]>ran[b]) p[b]=a;
    else{
        p[b]=a;
        if(ran[a]==ran[b]) ran[b]++;
    }
}
map<string,int> ma;
string s,a,b;
int x,y;
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) p[i]=i,cin>>s,ma[s]=i;
    while(m--){
        cin>>a>>b;
        x=fin(ma[a]),y=fin(ma[b]);
        if(x!=y) un(x,y);
    }
    cin>>q;
    while(q--) cin>>a>>b,cout<<(fin(ma[a])==fin(ma[b])?"Yes":"No")<<".\n";
//    system("pause");
    return 0;
}
