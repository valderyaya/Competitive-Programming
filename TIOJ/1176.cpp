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

int n,x;
stack<int,vector<int>> s;
vector<int> ans,h;
int main(){
    oi;
    cin>>n;
    REP(i,n){cin>>x;h.em(x);}
    reverse(ALL(h));
    REP(i,n){
        while(s.size()&&h[i]>h[s.top()]) s.pop();
        ans.em(s.size()?i-s.top():i);
        s.push(i);
    }
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<"\n";
//    system("pause");
    return 0;
}
