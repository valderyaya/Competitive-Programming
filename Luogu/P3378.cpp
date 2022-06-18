// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>

priority_queue<int,vector<int>,greater<int> > q;
int main(){
    oi;
    int n,m,x;
    cin>>n;
    while(n--){
        cin>>x;
        if(x==1){cin>>m;q.emplace(m);}
        else if(x==3) q.pop();
        else cout<<q.top()<<"\n";
    }
//    system("pause");
    return 0;
}
