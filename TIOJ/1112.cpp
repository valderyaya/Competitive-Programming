//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

int t,n;
string s[101];
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n;int mx=0;
        REP(i,n) cin>>s[i];
        REP(i,n) REP(j,n){
            if(s[i][j]=='N'){
                int len;
                for(len=i;len<n&&s[len][j]=='N';len++);
                len-=i;
                for(int k=i,l=j,p=0;p<len&&k<n&&l<n;l++,k++,p++){
                    if(s[k][l]!='N') break;
                    for(int cnt=0,o=k;o>=0;o--,cnt++){
                        if(s[o][l]!='N') break;
                        if(cnt==p) mx=max(mx,cnt-2);
                    }
                }
            }
        }
        cout<<mx<<"\n";
    }
    return 0;
}
