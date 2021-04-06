#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll>

int n,a,cnt;
vector<int> v;
int main(){
    //oi;
    while(cin>>n,n){
        REP(i,n){
            cin>>a;v.em(a);
        }
        a=cnt=0;
        REP(i,n){
            for(int j=i+1;j<n;j++){
                cnt++;
                if(__gcd(v[i],v[j])==1) a++;
            }
        }
        if(cnt==0||a==0) cout<<"No estimate for this data set.\n";
        else cout<<fixed<<setprecision(6)<<(double)sqrt(6.*cnt/a)<<"\n";
        v.clear();
    }
//    system("pause");
    return 0;
}
