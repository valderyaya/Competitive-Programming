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

int a[1000001];
int main(){
    oi;
    int n,sum=0;
    cin>>n;
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            a[j]++;
        }
        sum+=a[i];
    }
    cout<<sum+n;
//    system("pause");
    return 0;
}
