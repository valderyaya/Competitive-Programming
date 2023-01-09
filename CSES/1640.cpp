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
 
int n,m,a[200005];
map<int,vector<int>> mp;
int qry(int x,int j){
    for(auto &i:mp[x]) if(i!=j) return i;
    return -1;
}
int main(){Rosario
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>a[i],mp[a[i]].em(i+1);
    for(int x,i=0,j;i<n;++i){
        x=m-a[i];
        if(x>0&&mp.count(x)){
            j=qry(x,i+1);
            if(j!=-1) return cout<<i+1<<' '<<j<<"\n",0;
        }
    }
    cout<<"IMPOSSIBLE\n";
}
