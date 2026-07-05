class Solution {
public:
    string minWindow(string s, string t) {

        if (t.length() > s.length())
            return "";

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c : t)
            need[c]++;

        int have = 0;
        int needCount = need.size();

        int left = 0;
        int resLen = INT_MAX;
        int resStart = 0;

        for (int right = 0; right < s.length(); right++) {

            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c])
                have++;

            while (have == needCount) {

                if (right - left + 1 < resLen) {
                    resLen = right - left + 1;
                    resStart = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {
                    have--;
                }

                left++;
            }
        }

        if (resLen == INT_MAX)
            return "";

        return s.substr(resStart, resLen);
    }
};