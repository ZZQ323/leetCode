
// src="https://leetcode.cn/problems/spiral-matrix/?envType=company&envId=huawei&favoriteSlug=huawei-thirty-days"
// 特殊的遍历模式：DFS遍历

class Solution {
private:
    int cnt = 0;
    int m;
    int n;

    vector<int> ans;
    vector<vector<int>> vis;

    bool flag1 = 0;
    void Row(int x,int y,vector<vector<int>>& matrix){
        // 只有两个遍历方向
        if(flag1){
            int i=n-1;
            for(;vis[i][y]&&i>=0;--i);
            if(i<0)return;
            for(;i>=0;--i){
                // 如果访问过就不在访问
                if(vis[i][y]){
                    break;
                }
                ans.push_back(matrix[i][y]);
                vis[i][y]=1;
                ++cnt;
            }
            flag1^=1;
            if(cnt<n*m)Column(i+1,y,matrix);
        }else{
            int i=0;
            for(;vis[i][y]&&i<n;++i);
            if(i==n)return;
            for(;i<n;++i){
                // 如果访问过就不在访问
                if(vis[i][y]){
                    break;
                }
                ans.push_back(matrix[i][y]);
                vis[i][y]=1;
                ++cnt;
            }
            flag1^=1;
            if(cnt<n*m)Column(i-1,y,matrix);
        }
    }
    bool flag2 = 0;
    void Column(int x,int y,vector<vector<int>>& matrix){
        // 只有两个遍历方向
        if(flag2){
            int j=m-1;
            for(;vis[x][j] && j>=0;--j);
            if(j<0)return;
            for(;j>=0;--j){
                // 如果访问过就不在访问
                if(vis[x][j]){
                    break;
                }
                ans.push_back(matrix[x][j]);
                vis[x][j]=1;
                ++cnt;
            }
            flag2^=1;
            if(cnt<n*m)Row(x,j+1,matrix);
        }else{
            int j=0;
            for(;vis[x][j]&&j<m;++j);
            if(j==m)return;
            for(;j<m;++j){
                // 如果访问过就不在访问
                if(vis[x][j]){
                    break;
                }
                ans.push_back(matrix[x][j]);
                vis[x][j]=1;
                ++cnt;
            }
            flag2^=1;
            if(cnt<n*m)Row(x,j-1,matrix);
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        flag1=flag2=0;
        n = matrix.size();
        m = matrix[0].size();
        vis.resize(n);
        for(int i=0;i<n;++i){
            vis[i].resize(m,0);
        }
        ans.clear();
        cnt = 0;
        Column(0,0,matrix);
        return ans;
    }
};