#include<bits/stdc++.h>
using namespace std;

int n;
bitset<101> adj[101];

int main(){
    cin >> n;
    bool x;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            cin >> x;
            adj[i][j] = x;
        }
    for(int j = 1; j <= n; ++j)
        for(int i = 1; i <= n; ++i)
            if(adj[i][j]) 
                adj[i] |= adj[j];
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cout << adj[i][j] << " \n"[j == n];
}
