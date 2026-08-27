class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        int n = s.size();
        int match = 0;

        while (match < n && count[target[match] - 'a'] > 0) {
            count[target[match] - 'a']--;
            match++;
        }

        int start = (match < n ? match : n - 1);

        for (int i = start; i >= 0; i--) {
            if (i < match) {
                count[target[i] - 'a']++;
            }
            int bigg = -1;
            for (int ch = target[i] - 'a' + 1; ch < 26; ch++) {
                if (count[ch] > 0) {
                    bigg = ch;
                    break;
                }
            }

            if (bigg != -1) {
                count[bigg]--;

                string ans = target.substr(0, i);
                ans += char('a' + bigg);

                for (int ch = 0; ch < 26; ch++) {
                    ans.append(count[ch], char('a' + ch));
                }
                return ans;
            }
        }

        return "";
    }
};