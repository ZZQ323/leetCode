
/*src = 
 *https://leetcode.cn/problems/find-the-winner-of-the-circular-game/?envType=company&envId=huawei&favoriteSlug=huawei-thirty-days
 *
 *   
*/

class Solution {
private:
    list<int> vis;
public:
    int findTheWinner(int n, int k) {
        // 初始化
        vis.clear();
        for (int i = 1; i <= n; ++i) {
            vis.push_back(i);
        }
        // 特判
        if(n==1)return k;
        int cnt = n;
        // 约瑟夫抽杀
        list<int>::iterator it=vis.begin();
        while(cnt){
            --cnt;
            for(int i = 1;i<k;++it,it=(it==vis.end()?vis.begin():it),++i);
            it = vis.erase(it);  // it 现在指向被删除元素的下一个元素
            it=(it==vis.end()?vis.begin():it);
            if(cnt==1){
                return *it;
            }
        }
        throw logic_error("Logic error occurred");
    }
};