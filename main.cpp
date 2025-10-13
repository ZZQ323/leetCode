#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        using pii = pair<int, int>;
        // 特殊情况处理
        if (k == 0) return true;
        if (s.empty()) return false;

        // 1. 记录每个字符的首次和末次出现位置（构建最小区间）
        pii intervals[26]; // 0~25对应a~z
        for (int i = 0; i < 26; ++i) {
            intervals[i] = {-1, -1}; // 初始化无效区间
        }
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (intervals[idx].first == -1) {
                intervals[idx].first = i; // 首次出现位置
            }
            intervals[idx].second = i; // 末次出现位置（不断更新）
        }

        // 2. 筛选有效区间（只保留出现过的字符区间）
        vector<pii> validIntervals;
        for (int i = 0; i < 26; ++i) {
            if (intervals[i].first != -1) { // 字符出现过
                validIntervals.push_back(intervals[i]);
            }
        }

        // 如果有效区间总数不足k，直接返回false
        if (validIntervals.size() < k) {
            return false;
        }

        // 3. 按区间结束位置排序（动态规划的前提）
        sort(validIntervals.begin(), validIntervals.end(),
             [](const pii& a, const pii& b) {
                 if (a.second != b.second) return a.second < b.second; // 按结束位置升序
                 return a.first < b.first;
             });

        // 4. 动态规划计算最多不相交区间数
        int n = validIntervals.size();
        vector<int> dp(n, 1); // dp[i]表示前i个区间中最多不相交区间数，初始至少选1个

        for (int i = 0; i < n; ++i) {
            // 找第i个区间之前，最后一个不相交的区间j
            for (int j = i - 1; j >= 0; --j) {
                // 若区间j的结束 < 区间i的开始，说明不相交
                if (validIntervals[j].second < validIntervals[i].first) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    // break; // 因为已排序，j是最大的不相交区间，无需再查更小的j
                }
            }
        }

        // 5. 找到最大的不相交区间数
        int maxCount = *max_element(dp.begin(), dp.end());

        // 判断是否能选出至少k个不相交区间
        return maxCount >= k;
    }
};


int main() {
    Solution solution;
    // 测试用例解析：
    // case1: "abcdbaefab" → 有效区间可选出至少2个不相交 → true
    // printf("case1: %s\n", solution.maxSubstringLength("abcdbaefab", 2) ? "true" : "false");
    // case2: "cjd" → 3个字符各成区间且不相交 → true
    // printf("case2: %s\n", solution.maxSubstringLength("cjd", 3) ? "true" : "false");
    // case3: "cdefdc" → 最多2个不相交区间 → false
    // printf("case3: %s\n", solution.maxSubstringLength("cdefdc", 3) ? "true" : "false");
    // case4: 该字符串的有效区间中，最多不相交区间数<6 → false
    printf("case4: %s\n", solution.maxSubstringLength("ddjlopbgngpoenkqktvuuvpygctyquoeqglszijjiifljfiswiladdfwzislzdd", 6) ? "true" : "false");

    // printf("case5: %s\n", solution.maxSubstringLength("wyafxgsyzfdyciynklf", 10) ? "true" : "false"); // true

    return 0;
}
