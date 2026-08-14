class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>freqs(26,0);
         
        for (int i=0;i<magazine.size();i++){
            freqs[magazine[i]-'a']++;
        }
        for (int j=0;j<ransomNote.size();j++){
            
            freqs[ransomNote[j]-'a']--;
            
            if (freqs[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;

    }
};