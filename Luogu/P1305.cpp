// luogu-judger-enable-o2
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

string a,b;
int n;
int main(){
    oi;
    cin>>n;
    cin>>a;
    while(--n){
        cin>>b;
        auto x=a.find(b[0]);
        a.insert(x+1,b.substr(1,2));
    }
    REP(i,a.size()) if(a[i]!='*') cout<<a[i];
//    system("pause");
    return 0;
}
