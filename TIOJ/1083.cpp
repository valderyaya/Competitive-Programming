//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

string str[50];
void insert(int id,int x){
    if(!x) return;
    insert(id,x/10);
    str[id].pb(x%10+'0');
}
void build(){
    str[1]="1";
    for(int i=2,k;i<43;++i){
        REP(j,str[i-1].size()){
            for(k=j+1;k<str[i-1].size()&&str[i-1][k]==str[i-1][j];++k);
            insert(i,k-j);
            str[i].pb(str[i-1][j]);
            j=k-1;
        }
    }
}
int main(){Rosario
    build();
    int n;
    while(cin>>n,n){
        //cout<<str[n]<<endl;
        cout<<str[n].size()<<" ";
        cout<<fixed<<setprecision(6)<<(double)str[n-1].size()/str[n].size()<<"\n";
    }
    return 0;
}
