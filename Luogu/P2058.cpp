#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5, day = 86400;
int cnt[maxn], n, ind, ans, k, tme[maxn];
vector<int> v[maxn];
void add(int x){
    if(++cnt[x] == 1) ++ans;
}
void sub(int x){
    if(--cnt[x] == 0) --ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tme[i]>>k;
        v[i].resize(k);
        for(int j=0;j<k;++j){
            cin>>v[i][j];
            add(v[i][j]);
        }
        while(tme[ind] + day <= tme[i]){
            for(auto &j:v[ind]) sub(j);
            ++ind;
        }
        cout << ans <<"\n";
    }

    return 0;
}
