class Solution {
public:
    vector<int> v[100001];
    int ans=0,cnt[100001][26]={},tot=0,in[100001]={};
    int largestPathValue(string s, vector<vector<int>>& edges) {
        for(auto &i:edges) v[i.front()].emplace_back(i.back()), ++in[i.back()];
        queue<int> q;
        for(int i=0;i<s.size();++i) if(in[i]==0) q.push(i), cnt[i][s[i]-'a']=1;
        while(!q.empty()){
            int x=q.front(); q.pop();
            ++tot;
            ans=max(ans,*max_element(cnt[x],cnt[x]+26));
            for(auto &i:v[x]){
                for(int j=0;j<26;++j) cnt[i][j]=max(cnt[i][j],cnt[x][j]+(j==s[i]-'a'));
                if(--in[i]==0) q.push(i);
            }
        }
        return tot==s.size()?ans:-1;
    }
};
