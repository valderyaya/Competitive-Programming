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


int main(){
    oi;
    int n,m,a,sum=0,cnt=1;
    cin>>n>>m;
    while(n--){
        cin>>a;
        if(sum+a>m){
            cnt++;
            sum=a;
        }else{
            sum+=a;
        }
    }
    cout<<cnt<<endl;
//    system("pause");
    return 0;
}
