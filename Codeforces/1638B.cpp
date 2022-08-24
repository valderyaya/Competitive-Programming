#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back

int t,n,a[100005];
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n;
        int last=0,last2=0;
        REP(i,n) {
            cin>>a[i];
            if(a[i]%2==0){
                if(last==-1) continue;
                if(!last) last=a[i];
                else if(last>a[i]){
                    last=-1;
                    continue;
                } 
                last=max(last,a[i]);
            }else{
                if(last2==-1) continue;
                if(!last2) last2=a[i];
                else if(last2>a[i]) {
                    last2=-1;
                    continue;
                }
                last2=max(last2,a[i]);
            }
        }
        if(last!=-1&&last2!=-1) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
