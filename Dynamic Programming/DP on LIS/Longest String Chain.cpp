
class Solution {
private:
    bool check(string &s1, string &s2){
        if(s1.size()!=s2.size()+1)return 0;
        int f = 0,s = 0;
        while(f<s1.size()){
            if(s1[f]==s2[s] ){
                f++;
                s++;
            }
            else{
                f++;
            }
        }
        if(f==s1.size() && s==s2.size())return true;

        return false;
    }
    static bool cmp(string &s1, string &s2){
        return s1.length()<s2.length();
    }

public:
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        sort(words.begin(),words.end(), cmp);

        
        int maxi = 1;
        vector<int>dp(n,1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(check(words[i],words[j]) && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                }
            }
            if(dp[i]> maxi){
                maxi = dp[i];
            }   
        }
        return maxi;
    }
};
