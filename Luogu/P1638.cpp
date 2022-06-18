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
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

int n,m,a[2005]={},cnt=0,num[1000005],mx=1e9,l,r;
void add(int x){
    if(a[x]==0) cnt++;
    a[x]++;
}
void erase(int x){a[x]--;}
vector<int> v;
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n){
        cin>>num[i];
        v.em(i);add(num[i]);
        while(!v.empty()&&a[num[v.front()]]>1) erase(num[v.front()]),v.erase(v.begin());
        if(cnt==m){
            int x=v.back()-v.front();
            if(x<mx) l=v.front(),r=v.back(),mx=x;
        }
    }cout<<l<<' '<<r<<"\n";
//    system("pause");
    return 0;
}
