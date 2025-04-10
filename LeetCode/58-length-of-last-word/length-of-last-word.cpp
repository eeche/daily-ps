class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream ss(s);
        string word, lastword;

        while (ss >> word) {
            lastword = word;
        }
        return lastword.size();
    }
};