class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i=0;i<strs.size();i++){
            s += strs[i] +"`";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> a;
        int n = s.size();
        int l = 0;
        int r = 0;
        while(r<n){
            if(s[r]=='`'){
                string temp(s.begin() + l, s.begin() + r);
                a.push_back(temp);
                l = r+1;
            }
            r++;
        }
        string temp(s.begin() + l, s.begin() + r);
        if(!temp.empty()){
            a.push_back(temp);
        }
        
        return a;
    }
};
