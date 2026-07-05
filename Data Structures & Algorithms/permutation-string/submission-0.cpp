class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
            return false;

        unordered_map<char,int> s1Map;
        unordered_map<char,int> windowMap;

        
        for(int i=0;i<s1.size();i++)
        {
            s1Map[s1[i]]++;
            windowMap[s2[i]]++;
        }

        if(s1Map==windowMap)
            return true;

        // Slide window
        for(int right=s1.size(); right<s2.size(); right++)
        {
            windowMap[s2[right]]++;

            char leftChar = s2[right-s1.size()];
            windowMap[leftChar]--;

            if(windowMap[leftChar]==0)
                windowMap.erase(leftChar);

            if(windowMap==s1Map)
                return true;
        }

        return false;
    }
};