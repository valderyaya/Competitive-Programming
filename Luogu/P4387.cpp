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
#define wait system("pause");


int t,n,a[100005],b[100005];
stack<int> st;
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n;
        REP(i,n) cin>>a[i];
        REP(i,n) cin>>b[i];
        int i=0,j=0;
        while(!st.empty()) st.pop();
        for(;i<n;i++){
            st.emplace(a[i]);
            while(st.size()&&st.top()==b[j]) st.pop(),j++; 
        }
        cout<<(j==n?"Yes\n":"No\n");
    }
//    system("pause");
    return 0;
}
