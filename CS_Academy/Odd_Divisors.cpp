#include <iostream>

using namespace std;

#define int long long 
int p(int x){return x*x;}
int cnt(int x){
    if(!x) return 0;
    if(x%2) return p((x+1)/2)+cnt(x/2);
    return p(x/2)+cnt(x/2);
}
 main() {
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<cnt(b)-cnt(a-1)<<"\n";
    }
    return 0;
}
