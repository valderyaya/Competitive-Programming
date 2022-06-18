#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
#define endl "\n"

map<string,int> mp;
string s,goal;
int a[3][3],dx[4]={1,0,0,-1},dy[4]={0,1,-1,0};
queue<string> q;
signed main(){valder
    for(int i=0,x;i<9;++i) cin>>x,s.push_back(char(x+'0'));
    for(int i=0,x;i<9;++i) cin>>x,goal.push_back(char(x+'0'));
    if(s==goal) return cout<<0,0;
    mp[s]=0;
    q.emplace(s);
    while(!q.empty()){
        s=q.front(); q.pop();
        if(s==goal) break;
        // cout<<s<<endl;
        int x,y,xx,yy;
        for(int i=0,k=0;i<3;++i)
            for(int j=0;j<3;++j,++k){
                a[i][j]=s[k]-'0';
                if(s[k]=='0') x=i,y=j;
        }
        // for(int i=0;i<3;++i)
        //     for(int j=0;j<3;++j) cout<<a[i][j]<<" \n"[j==2];
        for(int i=0;i<4;++i){
            xx=x+dx[i],yy=y+dy[i];
            if(xx<0||xx>2||yy<0||yy>2) continue;
            swap(a[x][y],a[xx][yy]);
            string tmp="";
            for(int j=0;j<3;++j)
                for(int k=0;k<3;++k)
                    tmp.push_back(char(a[j][k]+'0'));
            if(!mp.count(tmp)) mp[tmp]=mp[s]+1, q.emplace(tmp);
            swap(a[x][y],a[xx][yy]);
        }
    }
    cout<<mp[goal]<<"\n";
}
