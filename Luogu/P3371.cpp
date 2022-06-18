#include<bits/stdc++.h>
using namespace std;

const int maxn=1e4+5,inf=1e9;
vector<pair<int,int>> v[maxn];
int n,m,st,dis[maxn];
bool vis[maxn];
void spfa(){
    for(int i=1;i<=n;++i) dis[i]=inf;
    queue<int> q;
    dis[st]=0; vis[st]=1;
    q.push(st);
    while(!q.empty()){
        int x=q.front(); 
        vis[x]=0; q.pop();
        for(auto &i: v[x]){
            if(dis[i.first]>dis[x]+i.second){
                dis[i.first]=dis[x]+i.second;
                if(!vis[i.first]){
                    q.push(i.first);
                    vis[i.first]=1;
                }
            }
        }
    }
}
int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>st;
    int x,y,c;
    while(m--) cin>>x>>y>>c,v[x].push_back({y,c});
    spfa();
    for(int i=1;i<=n;++i) cout<<(dis[i]==inf?2147483647:dis[i])<<" \n"[i==n];
    return 0;
}
