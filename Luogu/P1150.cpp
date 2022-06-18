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
//#define lb(x) (x&-x)

int n,k,sum,re;
int main(){
    //oi;
    int t;
    cin>>n>>k;
    sum=n;re=n;n=0;
    while(re>=k){
        n+=re/k;
        re%=k;re+=n;
        sum+=n;
        n=0;
    }
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
