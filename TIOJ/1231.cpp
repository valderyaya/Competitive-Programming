//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,a,sum=0,b;
priority_queue<pii> q;
priority_queue<int> p;
int main(){Rosario
    cin>>n;
    while(n--) cin>>a>>b,q.emplace(mkp(b,a));
    cin>>n;
    for(;n;n--){
        while(q.size()&&q.top().F>=n) p.emplace(q.top().S),q.pop();
        if(p.empty()) sum--;
        else sum+=p.top(),p.pop();
    }
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
