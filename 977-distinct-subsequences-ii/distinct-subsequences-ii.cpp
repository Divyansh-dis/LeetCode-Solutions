class Solution {
public:
    int distinctSubseqII(string s) {
        long long endsWith[26] = {0};
        long long total_sum = 0;
        long long mod = 1e9 + 7;
        
        for (char c : s) {
            long long prev = endsWith[c - 'a'];
            long long current = (total_sum + 1) % mod;
            
            total_sum = (total_sum - prev + current + mod) % mod;
            endsWith[c - 'a'] = current;
        }
        
        return total_sum;
    }
};