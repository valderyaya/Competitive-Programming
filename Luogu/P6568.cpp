#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)

int n,a[1000005],k,ans=0,idx,sum=0;
int main(){
    cin>>n>>k;++k;
    REP1(i,1,n) cin>>a[i];
    REP1(i,1,n){
        sum+=a[i];
        if(i>k) sum-=a[i-k];
        if(i>=k) ans=max(ans,sum);
    }
    cout<<ans<<"\n";
    return 0;
}
