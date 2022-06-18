//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
#define line cout<<"-------------------------------\n";

struct qq{
    int a,b,c;
    bool operator<(const qq &x)const{
        return c>x.c;
    }
}q[100005];
int n,m,k,pa[100005],ran[100005];
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
void un(int a,int b){
    k--;
    if(ran[a]>ran[b]) pa[b]=a;
    else{
        pa[a]=b;
        if(ran[a]==ran[b]) ran[b]++;
    }
}
int main(){Rosario
    cin>>n>>m>>k;
    REP1(i,1,n) pa[i]=i;
    for(int i=0;i<m;i++) cin>>q[i].a>>q[i].b>>q[i].c;
    int a,b,sum=0;sort(q,q+m);
    REP(i,m){
        if(k==0) break;
        a=fin(q[i].a),b=fin(q[i].b);
        if(a!=b) un(a,b),sum+=q[i].c;
    }
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
