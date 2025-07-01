

// 二维差分
// 带0的写法，需要各种特判
// src=https://leetcode.cn/problems/maximal-square/?envType=company&envId=huawei&favoriteSlug=huawei-thirty-days
#define ni i+mid-1
#define nj j+mid-1

class Solution {
private:
    int n,m;
    int S[310][310];    //1的个数
    bool check(int mid,vector<vector<char>>& matrix){
        // 找起点 i,j
        for(int i=0;ni<n;++i){
            for(int j=0;nj<m;++j){
                // 起点 i,j 能不能有一个正方形
                if(matrix[i][j]=='0')continue;
                if(matrix[ni][nj]=='0')continue;
                // 0情况特殊处理
                if(!i && !j){
                    if(S[ni][nj] == mid*mid)return true;
                }else if(i &&!j){
                    if(S[ni][nj]-S[i-1][nj] == mid*mid)return true;
                }else if(!i && j){
                    if(S[ni][nj]-S[ni][j-1] == mid*mid)return true;
                }else{
                    if(S[ni][nj]-S[i-1][nj]-S[ni][j-1]+S[i-1][j-1] == mid*mid)return true;
                }
            }
        }
        return false;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(S,0,sizeof(S));
        n=matrix.size();
        m=matrix[0].size();
        if(n*m<=1){
            return matrix[0][0]=='1'?1:0;
        }

        // 边上初始化
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                S[i][j]=(matrix[i][j]=='1'?1:0);
            }
        }
        for(int i=1;i<n;++i){
            S[i][0]+=S[i-1][0];
        }
        for(int j=1;j<m;++j){
            S[0][j]+=S[0][j-1];;
        }
        // 前缀和
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                S[i][j]+=S[i-1][j]+S[i][j-1]-S[i-1][j-1];
            }
        }
        for(int i=1;i<=min(n,m);++i){
            if(!check(i,matrix)){
                return (i-1)*(i-1);
            }
        }
        return min(n,m)*min(n,m);
        // throw logic_error("Logic error occurred");
    }
};