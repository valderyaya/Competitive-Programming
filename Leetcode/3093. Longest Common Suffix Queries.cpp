class Solution {
public:
    static constexpr int maxn = 500001;
    int tr[maxn][26], cnt = 0;
    pair<int,int> words[maxn];

    void upd(pair<int,int>& a, pair<int,int> b){
        a = min(a, b);
    }

    void insert(string &s, int ind){
        int rt = 0;
        upd(words[rt], {s.size(), ind});

        for(int i = s.size() - 1, c; i >= 0; --i){
            c = s[i] - 'a';
            if(!tr[rt][c]){
                tr[rt][c] = ++cnt;
                memset(tr[cnt], 0, sizeof(tr[cnt]));
                words[cnt] = {INT_MAX, INT_MAX};
            }
            rt = tr[rt][c];
            upd(words[rt], {s.size(), ind});
        }
    }
    int query(string &s){
        int rt = 0;
        for(int i = s.size() - 1, c; i >= 0; --i){
            c = s[i] - 'a';
            if(!tr[rt][c])
                return words[rt].second;
            rt = tr[rt][c];
        }
        return words[rt].second;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        words[0] = {INT_MAX, INT_MAX};
        memset(tr[0], 0, sizeof(tr[0]));
        vector<int> ans;
        for(int i = 0; i < wordsContainer.size(); ++i) insert(wordsContainer[i], i);
        for(auto &s : wordsQuery)
            ans.emplace_back(query(s));
        return ans;
    }
};
