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


int n,m,p[150005],ran[150005]={},sum=0;
int fin(int x){return x==p[x]?x:p[x]=fin(p[x]);}
void un(int a,int b){
    a=fin(a),b=fin(b);
    if(ran[a]>ran[b]) p[b]=a;
    else{
        p[a]=b;
        if(ran[a]==ran[b]) ran[b]++;
    }
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n*3) p[i]=i;
    int k,x,y;
    while(m--){
        cin>>k>>x>>y;
        if(x>n||y>n){sum++;continue;}
        if(k&1){
            if(fin(x)==fin(y+n)||fin(x)==fin(y+n+n))sum++;
            else un(x,y),un(x+n,y+n),un(x+n+n,y+n+n);
        }else{
            if(fin(x)==fin(y)||fin(x+n+n)==fin(y))sum++;
            else un(x+n,y),un(x,y+n+n),un(y+n,x+n+n);
        }
    }cout<<sum<<"\n";
//    system("pause");
    return 0;
}
