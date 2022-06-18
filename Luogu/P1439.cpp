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
#define lb(x) (x&-x)

vector<int> v;
int n,a[100005],b[100005],c[100005];
int main(){
    oi;
    cin>>n;
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    REP(i,n) c[a[i]]=i;
    v.em(c[b[0]]);
    for(int i=1;i<n;i++){
        if(v.back()<c[b[i]]) v.em(c[b[i]]);
        else v[lower_bound(ALL(v),c[b[i]])-v.begin()]=c[b[i]];
    }
    cout<<v.size()<<"\n";
//    system("pause");
    return 0;
}
