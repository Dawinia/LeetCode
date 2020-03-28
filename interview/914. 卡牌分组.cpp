class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int size = deck.size();
        if(size < 2)
            return false;
        sort(deck.begin(), deck.end());
        int temp = deck[0];
        stack<int> s;
        int k = 1;
        for(int i = 1; i < size; ++i) {
            if(deck[i] == temp) {
                ++k;
            }
            else {
                if(!s.empty() && gcd(k, s.top()) == 1) {
                    
                    return false;
                }
                s.push(k);
                k = 1;
                temp = deck[i];
            }
        }
        if(s.empty())
            return k >= 2;
        else
            return gcd(k, s.top()) > 1;
    }
    
    int gcd(int x, int y) {	
	    int z = y;
	    while(x % y != 0) {
		    z = x % y;
		    x = y;
		    y = z;	
	    }
	    return z;
    }
};