class Solution {
public:

    string encode(vector<string>& strs) {
        string k="";
        for(auto it:strs){
            k+=it;
            k+='`';
        }
        return k;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int l=0,r=0;
        while(r<s.size()){
            if(s[r]=='`'){
                string h = s.substr(l,r-l);
                ans.push_back(h);
                l=r+1;
            }
            r++;
        }
        string h = s.substr(l,r-l+1);
        if(!h.empty()){
            ans.push_back(h);
        }
        
        return ans;
    }
};
