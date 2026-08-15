class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.size(); i++) {

            // Check s -> t mapping
            if (sToT.find(s[i]) != sToT.end() &&
                sToT[s[i]] != t[i]) {
                return false;
            }

            // Check t -> s mapping
            if (tToS.find(t[i]) != tToS.end() &&
                tToS[t[i]] != s[i]) {
                return false;
            }

            // Create the mapping
            sToT[s[i]] = t[i];
            tToS[t[i]] = s[i];
        }

        return true;
    }
};