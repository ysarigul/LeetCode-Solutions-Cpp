class Solution {
public:
    int openLock(vector<string>& deadlocks, string target) {
        
unordered_set<string> deadends(deadlocks.begin(), deadlocks.end());
        
       unordered_set<string> visited;
        
      queue<string> q;
        q.push("0000");
        
        int ans = -1;
        
        while (!q.empty()) {
            ans += 1;
            auto count = q.size();
            for (auto i = 0; i < count; ++i) {
                string s = q.front();
                q.pop();
                if (s == target) {
                    return ans;
                }
                
                if (deadends.find(s) != deadends.end()) {
                    continue;
                }
                
                if (visited.find(s) != visited.end()) {
                    continue;
                }
                
                visited.insert(s);
                find_next(s, q);
            }
        }
        return -1;
    }
private:
    void find_next(string s, std::queue<string>& q) {
        for (int i = 0; i < 4; ++i) {
            char c = s[i];
            
            s[i] = (c - '0' + 1) % 10 + '0';
            q.push(s);
            
            s[i] = (c - '0' - 1 + 10) % 10 + '0';
            q.push(s);
            s[i] = c;
        }
    }
};