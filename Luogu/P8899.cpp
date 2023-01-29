#include<bits/stdc++.h>
using namespace std;

int t, n, m, tag[2];
bool a[101][101], res[101], vis[101], flag[2];
string s;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<m;++i){
            cin>>s;
            for(int j=0;j<n;++j) 
                a[i][j] = s[j]-'0';
            cin>>res[i];
            vis[i]=0;
        }
        for(int k=0;k<n;++k){
            for(int j=0;j<n;++j){
                tag[0] = tag[1] = -1;
                flag[0] = flag[1] = 0;
                for(int i=0;i<m;++i){
                    if(vis[i]) continue;
                    if(tag[a[i][j]] == -1)
                        tag[a[i][j]] = res[i];
                    else if(tag[a[i][j]] != res[i])
                        flag[a[i][j]] = 1;
                }
                for(int i=0;i<m;++i)
                    if(flag[a[i][j]]==0) vis[i] = 1;
            }
        }
        bool chk=0;
        for(int i=0;i<m;++i)
            if(!vis[i]) chk = 1;
        cout<<(chk ? "LIE" : "OK")<<"\n";
    }
}
