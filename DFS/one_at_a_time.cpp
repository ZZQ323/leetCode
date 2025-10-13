
// https://leetcode.cn/problems/generate-parentheses/?envType=company&envId=huawei&favoriteSlug=huawei-thirty-days

// sol 错误 ： 写带回溯的递归，但是还需要分工合作
// 分工合作本质上是用分治算法，分而治之；
// 回溯是一条路走到黑；

void DFS(int l,int r)
{
    if(strlen(str)==ln && check()){
        se.insert(string(str));
        return ;
    }
    if(l>r)return ;
    for(int gap=1;gap<r-l+1;gap+=2){
        // 从左到右
        str[l]='(';
        str[l+gap]=')';
        DFS(l+1,l+gap-1);
        DFS(l+gap+1,r);
        str[l]=0;
        str[l+gap]=0;
        // 对称性
        str[r-gap]='(';
        str[r]=')';
        DFS(l,r-gap-1);
        DFS(r-gap+1,r-1);
        str[r-gap]=0;
        str[r]=0;
    }
}


//  sol2：一次只加一个括号，根据统计量来辅助简单决策，朴素的递归
void gen(int open,int close,string cur)
{
    if(cur.length()==ln){
        se.insert(cur);
        return;
    }
    if(open<ln/2)gen(open+1,close,cur+'(');
    if(close<open)gen(open,close+1,cur+')');
}

// sol3：找到更小的且同样的问题，然后向上合并答案




