#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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

struct kmp{
    string s;
    vector<int> f;
    int mx=-1,len=0;
    void build(int x){
        f.resize(s.size());
        int fp=f[0]=-1;
        for(int i=1;i<s.size();i++){
            while(~fp&&s[fp+1]!=s[i]) fp=f[fp];
            if(s[fp+1]==s[i]) fp++;
            f[i]=fp;
            if(fp>mx&&(i+1)%(i-fp)==0) len=max(len,i+1);
        }
        cout<<len/x<<"\n";
    }
}qq;
int n;
int main(){Rosario
    cin>>n>>qq.s;
    qq.build(n);
//    for(int i:qq.f) cout<<i<<' ';
//    system("pause");
    return 0;
}
