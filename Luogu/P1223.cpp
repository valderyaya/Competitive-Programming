// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

double sum=0;
ll n,a[1001];
int main(){
    oi;
    cin>>n;
    REP(i,n){
        cin>>a[i];
        a[i]*=1003;a[i]+=i+1;
    }
    sort(a,a+n);
    REP(i,n){
        cout<<a[i]%1003<<' ';
        sum+=a[i]/1003*(n-1-i);
    }
    cout<<endl<<fixed<<setprecision(2)<<sum/n;
//    system("pause");
    return 0;
}
