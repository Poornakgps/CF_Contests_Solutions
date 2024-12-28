class Solution {
public:
    int makeStringGood(string s) {
        map<int, int> freq;
        int mx = 0;
        for(auto c: s) freq[c-'a']++, mx = max(mx, freq[c-'a']);

        int ans = 1e9;

        for(int target=0; target<=mx; target++){
            vector<int> dp(27, 0);

            for(int j=25; j>=0; j--){
                // remove all
                dp[j] = dp[j+1] + freq[j];

                // insert or remove
                dp[j] = min(dp[j], dp[j+1] + abs(target - freq[j]));

                // move char to next
                int movenxt = (target>freq[j] ? freq[j] : freq[j] - target);

                if(j+1<26 && freq[j+1]<target){
                    dp[j] = min(dp[j], movenxt + max(0, target - freq[j+1] - movenxt) + dp[j+2] );
                }
            }
            ans= min(ans,dp[0]);
        }
        return ans;
    }
};