class Solution {
public:
	#define REP(i,n) for(int i=0;i<n;++i)
	#define REP1(i,a,b) for(int i=a;i<=b;++i)
    #define F first
    #define S second
    struct qwq{int x,y,st;};
    vector<pair<int,int>> v;
	queue<qwq> q;
	int n,m,ans=1e9,cnt=0,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},f[70][35][35];
    int shortestPathAllKeys(vector<string>& a) {
       	n=a.size(),m=a[0].size();
		REP(i,n) REP(j,m){
			if(a[i][j]=='@'){
				f[0][i][j]=1;
				q.emplace(qwq{i,j,0});
			}
			if(a[i][j]>='a'&&a[i][j]<='z')++cnt,v.push_back({i,j});
		}
		while(!q.empty()){
			qwq o=q.front(); q.pop();
            //cout<<o.x<<' '<<o.y<<' '<<f[o.st][o.x][o.y]<<endl;
			REP(i,4){
				int x=o.x+dx[i],y=o.y+dy[i];
				if(x<0||x>=n||y<0||y>=m||a[x][y]=='#'||f[o.st][x][y]) continue;
				if(a[x][y]>='a'&&a[x][y]<='z'){
					int st=o.st|(1<<(a[x][y]-'a'));
			 		if(!f[st][x][y]) f[st][x][y]=f[o.st][o.x][o.y]+1,q.emplace(qwq{x,y,st});
				}else if(a[x][y]>='A'&&a[x][y]<='Z'){
					if((o.st>>(a[x][y]-'A')&1)){
						if(!f[o.st][x][y]){
                            f[o.st][x][y]=f[o.st][o.x][o.y]+1;
						    q.emplace(qwq{x,y,o.st});
                        }
                    }
				}else f[o.st][x][y]=f[o.st][o.x][o.y]+1,q.emplace(qwq{x,y,o.st}); 
			}		
		}
        cnt=(1<<cnt)-1;
		for(auto &i:v) ans=min(ans,f[cnt][i.F][i.S]);
		return ans-1;
    }
};
