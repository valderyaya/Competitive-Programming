#include<bits/stdc++.h>
using namespace std;

int n,m,in[100005],x,y,ans[100005];
queue<int> q;
vector<int> v[100005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>x>>y;
        v[x].push_back(y);
        ++in[y];
    }
    for(int i=1;i<=n;++i)
        if(in[i]==0){
            q.push(i);
            ans[i]=1;
        }
    while(!q.empty()){
        x=q.front();
        q.pop();
        for(auto &i:v[x]){
            ans[i]=max(ans[i],ans[x]+1);
            --in[i];
            if(in[i]==0) q.push(i);
        }
    }
    for(int i=1;i<=n;++i) cout<<ans[i]<<'\n';
}
