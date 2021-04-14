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

const int z=1500005;
int p[z],ran[z]={},n,k,cnt=0;
int fin(int x){return p[x]==x?x:p[x]=fin(p[x]);}
void un(int x,int y){
    x=fin(x),y=fin(y);
    if(ran[x]>ran[y]) p[y]=x;
    else{
        p[x]=y;
        if(ran[x]==ran[y]) ran[y]++;
    }
}
int main(){Rosario
    cin>>n>>k;
    REP1(i,1,n*3) p[i]=i;
    int x,y,o;
    while(k--){
        cin>>o>>x>>y;
        if(x>n||y>n) {++cnt;continue;}
        if(o==1){
            if(fin(x)==fin(y+n)||fin(x)==fin(y+n+n)) ++cnt;
            else un(x,y),un(x+n,y+n),un(x+n+n,y+n+n);
        }else{
            if(fin(x)==fin(y)||fin(y)==fin(x+n+n)) ++cnt;
            else un(x+n,y),un(y+n,x+n+n),un(x,y+n+n);
        }
    }cout<<cnt<<"\n";
    return 0;
}
