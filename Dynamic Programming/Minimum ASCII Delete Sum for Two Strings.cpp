class Solution {
public:
int solve(int i,int j,string &s1,string &s2, vector<vector<int>>&dp){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=s1[i]+solve(i-1,j-1,s1,s2,dp);

        return dp[i][j]= max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
        
}
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        int sum1=0,sum2=0;
        for(auto it:s1) sum1+=it;
        for(auto it:s2) sum2+=it;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return (sum1+sum2)-2*solve(m-1,n-1,s1,s2,dp);
    }
};