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

int sum,s,t,n,c,tmp;
int main(){Rosario
    cin>>s>>t>>n;
    REP(i,n) cin>>tmp,c+=tmp;
    tmp=t/5;
    sum=-s*t*3/10;
    if(c<tmp) sum+=c*s*7/10;
    else{
        sum+=tmp*s*7/10;
        if(c<t*4/10) sum+=(c-tmp)*s*8/10;
        else{
            sum+=(t*4/10-tmp)*s*8/10;
            tmp=t*4/10;
            if(c<t*6/10) sum+=(c-tmp)*s*9/10;
            else{
                sum+=(t*6/10-tmp)*s*9/10;
                tmp=t*6/10;
                if(c>tmp) sum+=(c-tmp)*s;
            }
        }
    }
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
