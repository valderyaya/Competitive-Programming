#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 
int n,x,a[200005],ans=1;
int main(){Rosario
    cin>>n;
    for(int i=0;i<n;++i) cin>>x,a[x]=i;
    for(int i=1;i<n;++i) if(a[i]>a[i+1]) ++ans;
    //for(int i=1;i<=n;++i) cout<<a[i]<<endl;
    cout<<ans<<"\n";
    return 0;
}
