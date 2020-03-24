class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size(), size2 = s2.size();
        if(size1 > size2)
            return false;
        int s1m[26] = {0};
        int s2m[26] = {0};
        for(int i = 0; i < size1; ++i) {
            ++s1m[s1[i] - 'a'];
            ++s2m[s2[i] - 'a'];
        }
        for(int i = size1; i < size2; ++i) {
            if(matchs(s1m, s2m))
                return true;
            --s2m[s2[i - size1] - 'a'];
            ++s2m[s2[i] - 'a'];
        }
        return matchs(s1m, s2m);
    }
    
    bool matchs(int* s1m, int* s2m) {
        for(int i = 0; i < 26; ++i) {
            if(*(s1m + i) != *(s2m + i))
                return false;
        }
        return true;
    }
};