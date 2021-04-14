#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,m,in[1005];
queue<int> q;
vector<int> v[1005];
int main(){Rosario
    while(cin>>n>>m){int a,b;
        while(q.size()) q.pop();
        REP1(i,1,n) v[i].clear(),in[i]=0;
        REP(i,m) cin>>a>>b,v[a].em(b),in[b]++;
        b=1;
        REP(i,n){
            cin>>a;
            if(in[a]) b=0;
            for(int j:v[a]) in[j]--; 
        }
        cout<<(b?"YES":"NO")<<"\n";
    }
//    system("pause");
    return 0;
}
