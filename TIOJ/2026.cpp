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
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

int n,x,q;
priority_queue<int> mx;
priority_queue<int,vector<int>,greater<int>> mn;
int main(){Rosario
    cin>>q>>n>>x;
    mx.emplace(x);
    while(--q){
        cin>>n;
        if(n==1){
            cin>>x;
            if(x>=mx.top()) mn.emplace(x);
            else mx.emplace(x);
            if(mx.size()>mn.size()&&mx.size()-mn.size()>1) mn.emplace(mx.top()),mx.pop();
            if(mn.size()>mx.size()) mx.emplace(mn.top()),mn.pop();
        }else cout<<mx.top()<<"\n";
    }
//    system("pause");
    return 0;
}
