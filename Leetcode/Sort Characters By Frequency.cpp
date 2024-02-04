class Solution {
public:
    map<char,int> mp;
    vector<pair<int,char>> v;
    string ans;
    string frequencySort(string s) {
        for(auto &c:s) mp[c]++;
        for(auto &i:mp) v.push_back({i.second,i.first});
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;--i)
            for(int j=0;j<v[i].first;++j)
                ans.push_back(v[i].second);
        return ans;
    }
};
