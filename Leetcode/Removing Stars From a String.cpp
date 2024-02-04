class Solution {
public:
    string removeStars(string s) {
        string res="";
        for(auto &i:s)
            if(i=='*') res.pop_back();
            else res.push_back(i);
        return res;
    }
};
