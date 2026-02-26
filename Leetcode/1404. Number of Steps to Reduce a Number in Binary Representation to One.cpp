class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        while(s != "1"){
            if(s.back() == '1'){
                ++cnt;
                while(s.size() && s.back() == '1'){
                    ++cnt;
                    s.pop_back();
                }
                if(s.size()) s.back() = '1';
                else s = "1";
            }else{
                ++cnt;
                s.pop_back();
            }
        }
        return cnt;
    }
};
