#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

set<pii> s;
int n,m,q,a,b,c;
int main(){
    oi;
    cin>>n>>m>>q;
    while(m--){
        cin>>a>>b;
        if(a>b) swap(a,b);
        s.insert(mkp(a,b));
    }
    while(q--){
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(s.find({a,b})==s.end()) cout<<"no\n";
        else cout<<"yes\n";
    }
//    system("pause");
    return 0;
}
