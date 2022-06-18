#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

int n;
priority_queue<int,vector<int>,greater<int>> mn;
priority_queue<int> mx;
int main(){Rosario
    int x;
    cin>>n;
    REP1(i,1,n){
        cin>>x;
        if(!mx.empty()&&x>mx.top()) mn.emplace(x);
        else mx.emplace(x);
        while(mn.size()>=mx.size()) mx.emplace(mn.top()),mn.pop();
        while(mx.size()-mn.size()>1) mn.emplace(mx.top()),mx.pop();
        if(i&1) cout<<mx.top()<<"\n";
    }
//    system("pause");
    return 0;
}
