#include<bits/stdc++.h>
using namespace std;

const int z=105,inf=1e9;
struct edge{
    int to,nxt,cst,flow;
}e[100000];
bitset<z> in;
int dis[z],h[z],cur[z],s,t,cnt=1,n,ans;
void add(int u,int v,int c,int f){
    e[++cnt]=edge{v,h[u],c,f};
    h[u]=cnt;
}
bool spfa(int tag){
	queue<int> q;
	for(int i=0;i<=t;i++) cur[i]=h[i],dis[i]=tag?inf:-inf;
	dis[0]=0; q.emplace(s); in[s]=1;
	while(!q.empty()){
		int x=q.front(); q.pop(); in[x]=0;
		for(int i=h[x];i;i=e[i].nxt){
			int v=e[i].to; 
			if(tag){
				if(e[i].flow&&dis[v]>dis[x]+e[i].cst){
					dis[v]=dis[x]+e[i].cst; 
					if(!in[v]) in[v]=1,q.emplace(v);
				}
			}else{
				if(e[i].flow&&dis[v]<dis[x]+e[i].cst){
					dis[v]=dis[x]+e[i].cst; 
					if(!in[v]) in[v]=1,q.emplace(v);
				}
			}
		}
	}
	return dis[t]!=(tag?inf:-inf);
}
int dfs(int x,int flow){
	if(x==t) return flow;
	int sum=0,k; in[x]=1;
	for(int &i=cur[x];i;i=e[i].nxt){
		int v=e[i].to;
		if(!in[v]&&e[i].flow&&dis[v]==dis[x]+e[i].cst){
			k=dfs(v,min(flow,e[i].flow));
			if(k){
				e[i].flow-=k,e[i^1].flow+=k;
				sum+=k; flow-=k; ans+=k*e[i].cst;
			}if(!flow) break;
		}
	}
	in[x]=0;
	return sum;
}
int solve(int tag){
	ans=0;
	while(spfa(tag)) dfs(s,inf);
	return ans;
}
int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
	int x; s=0,t=n<<1|1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>x,add(i,j+n,x,1),add(j+n,i,-x,0);
	for(int i=1;i<=n;i++) add(s,i,0,1),add(i,s,0,0),add(i+n,t,0,1),add(t,i+n,0,0);
	cout<<solve(1)<<"\n";
	for(int i=2;i<=cnt;i+=2) e[i].flow+=e[i^1].flow,e[i^1].flow=0;
	cout<<solve(0)<<"\n";

}
