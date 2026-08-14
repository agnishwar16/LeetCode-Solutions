class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(int i=0;i<strs.size();i++){
            vector<int>freq(26,0);

            for(int j=0;j<strs[i].size();j++){
                freq[strs[i][j]-'a']++;
            }

            string key="";

            for(int k=0;k<26;k++){
                key+=to_string(freq[k])+"#";
            }

            mp[key].push_back(strs[i]);
        }
        vector<vector<string>>results;

        for(auto&entry: mp){
            results.push_back(entry.second);
        }
        return results;


    }
};