class Solution {
public:
    string cal(int x){
        string s="";
        while(x) s.push_back(char('0'+x%10)),x/=10;
        reverse(s.begin(),s.end());
        return s;
    }
    int compress(vector<char>& s) {
        string ret="";
        for(int i=0,j;i<s.size();){
            if(i+1<s.size()&&s[i]==s[i+1]){
                for(j=i+1;j<s.size()&&s[i]==s[j];) ++j;
                ret.push_back(s[i]);
                ret+=cal(j-i);
                i=j;
            }else ret.push_back(s[i++]);
        }
        s.clear();
        for(auto &i:ret) s.push_back(i);
        return (int )ret.size();
    }
    
};
