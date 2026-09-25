class Solution {
public:

    bool dfs(int node, vector<int> &vis,
             vector<vector<int>> &adj,
             stack<int> &st,
             vector<int> &pathvis){

        vis[node]=1;
        pathvis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj,st,pathvis))
                    return true;
            }
            else if(pathvis[it]){
                return true;
            }
        }

        pathvis[node]=0;
        st.push(node);

        return false;
    }

    string foreignDictionary(vector<string>& words) {

        vector<vector<int>> adj(26);
        vector<int> vis(26,0);
        vector<int> pathvis(26,0);
        vector<int> exists(26,0);

        stack<int> st;

        string s="";

        // mark existing chars
        for(auto word:words){
            for(auto ch:word){
                exists[ch-'a']=1;
            }
        }

        // build graph
        for(int i=0;i<words.size()-1;i++){

            // invalid prefix case
            if(words[i].size() > words[i+1].size() &&
               words[i].substr(0,words[i+1].size()) == words[i+1]){
                return "";
            }

            for(int j=0;
                j<min(words[i].size(),words[i+1].size());
                j++){

                if(words[i][j]!=words[i+1][j]){

                    adj[words[i][j]-'a']
                        .push_back(words[i+1][j]-'a');

                    break;
                }
            }
        }

        // topo sort + cycle detection
        for(int i=0;i<26;i++){

            if(exists[i] && !vis[i]){

                if(dfs(i,vis,adj,st,pathvis)){
                    return "";
                }
            }
        }

        // build answer
        while(!st.empty()){

            s += st.top() + 'a';
            st.pop();
        }

        return s;
    }
};