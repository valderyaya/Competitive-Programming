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


int n,m,p[2005],ran[2005],cnt;
int fin(int x){return x==p[x]?x:p[x]=fin(p[x]);}
void un(int a,int b){
    a=fin(a),b=fin(b);
    if(ran[a]>ran[b]) p[b]=a;
    else{
        p[a]=b;
        if(ran[a]==ran[b]) ran[b]++;
    }
}
set<int> s;
char c;
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n+n) p[i]=i;
    int a,b;
    REP(i,m){
        cin>>c>>a>>b;
        if(c=='F') un(a,b);
        else un(a,b+n),un(a+n,b);
    }
    REP1(i,1,n) s.insert(fin(i));//if(fin(i)==i) cnt++;
    cout<<s.size()<<"\n";//cout<<cnt<<"\n";
//    system("pause");
    return 0;
}
