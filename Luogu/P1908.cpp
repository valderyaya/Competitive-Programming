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

ll ans=0;
void mer(int l,int r,int a[]){
    int i=l,m=l+r>>1,j=m+1,t[500001],k=l;
    while(i<=m&&j<=r){
        if(a[i]>a[j]){
            t[k++]=a[j++];ans+=m-i+1;
        }else t[k++]=a[i++];
    }
    while(i<=m)t[k++]=a[i++];
    while(j<=r)t[k++]=a[j++];
    for(i=l;i<=r;i++) a[i]=t[i];
}
void merges(int l,int r,int a[]){
    if(l>=r)return;
    int m=l+r>>1;
    merges(l,m,a),merges(m+1,r,a);
    mer(l,r,a);
}
int main(){
    oi;
    static int a[500001];
    int n;
    cin>>n;
    REP(i,n)cin>>a[i];
    merges(0,n-1,a);
//    REP(i,n) cout<<a[i]<<' ';
    cout<<ans;
//    system("pause");
    return 0;
}
