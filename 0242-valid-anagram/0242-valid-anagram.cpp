class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size()){
            return false;
        }
        unordered_map<char,int>freqs;

        for (int i=0;i<s.size();i++){
            freqs[s[i]]++;
        }
        for (int j=0;j<t.size();j++){

            if(freqs[t[j]]<=0){
                return false;
            }
            freqs[t[j]]--;
        }
        return true;
    }
};