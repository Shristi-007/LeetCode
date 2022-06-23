class Solution {
public:
 #define ll long long int
unordered_map<ll, ll> dp;
ll solve(string &s, int n)
{
    if (n == 0 || n == -1)
        return 1;
    if (n < 0)
        return 0;
    if (dp.find(n) != dp.end())
        return dp[n];
    ll x = 0;
    if (s[n] != '0')
        x = solve(s, n - 1);
    ll y = 0;
    ll d = (s[n - 1] - '0') * 10 + (s[n] - '0');
    if ((d > 9) && (d <= 26))
    {
        y = solve(s, n - 2);
    }

    return dp[n] = x + y;
}

    int numDecodings(string s) {
        int n,ans=0;
        n=s.length();
        if(s[0]=='0')
            return 0;
        ans=solve(s,n-1);
        return ans;
        
    }
};