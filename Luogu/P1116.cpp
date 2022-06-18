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

int a[10005],b[10005],n,m;
void add(int i){
    for(;i<=n;i+=lb(i)) b[i]++;
}
int get(int i){
    int sum=0;
    for(;i;i-=lb(i)) sum+=b[i];
    return sum;
}
int main(){
    //oi;
    int sum=0;
    cin>>n;
    REP1(i,1,n) cin>>a[i];
    REP1(i,1,n){
        add(a[i]);
        sum+=i-get(a[i]);
    }
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
