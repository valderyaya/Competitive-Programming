//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int t,n;
bitset<100000005> np;
vector<int> is;
inline bool ck(int x){
    int m=0,c=1;
    for(int i=x;i;i/=10) m=m*10+i%10;
    if(m==x) return 0;
    return !np[m];
}
int main(){Rosario
    np[0]=np[1]=1;
    for(int i=2;i*i<=100000000;i++){
        if(!np[i]){
            for(int j=i*i;j<=100000000;j+=i) np[j]=1;
        }
    }
    REP(i,100000000) if(!np[i]&&ck(i)) is.em(i);
    cin>>t;
    while(t--) cin>>n,cout<<is[n-1]<<"\n";
//    system("pause");
    return 0;
}
