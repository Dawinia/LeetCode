class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int size = pushed.size();
        int pos = 0;
        for(auto e: pushed) {
            s.push(e);
            while(!s.empty()) {
                if(s.top() == popped[pos]) {
                    s.pop();
                    ++pos;
                }
                else
                    break;
            }
        }
        return s.empty();
    }
};