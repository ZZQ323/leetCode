/*
 *src=
 *https://leetcode.cn/problems/minimum-window-substring/?envType=company&envId=huawei&favoriteSlug=huawei-thirty-days
 *
 * 滑动窗口：最小区间覆盖
*/
const int N = 1e5+100;
class Solution {
private:
    int dp[N][52];
    int cnt[52];
    inline int toNumber(char c){
        return islower(c)?c-'a':c-'A'+26;
    }
    inline bool check(int l,int r){
        for(int i=0;i<52;++i){
            if(!l){if(dp[r][i]<cnt[i])return false;}
            else{if(dp[r][i]-dp[l-1][i]<cnt[i])return false;}
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        if(s.length()<t.length())return string("");
        for(int i = 0;i<t.length();++i){
            ++cnt[toNumber(t[i])];
        }
        for(int i = 0;i<s.length();++i){
            if(!i){
                dp[i][toNumber(s[i])]=1;
                continue;
            }
            for(int j=0;j<52;++j){
                dp[i][j]=dp[i-1][j];
            }
            ++dp[i][toNumber(s[i])];
        }

        int l = 0;
        int len = 0x3fffffff;
        string ans = "";
        for(int i=0;i<s.length();++i){
            if(check(l,i)){
                while(l<=i && check(l,i))++l;
                if(i-(l-1)+1<len){
                    len = i-(l-1)+1;
                    ans=s.substr(l-1,len);
                }   
            }
        }
        return ans;
        // throw logic_error("Logic error occurred");
    }
};









