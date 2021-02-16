//#include <atcoder/all>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

// 581. Shortest Unsorted Continuous Subarray
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

int findUnsortedSubarray(vector<int>& nums)
{
    // ある数が現れたとき
    // その数と入れ替えないといけない一番indexが小さい要素はなにか？
    // これはstackを使って解決できる
    int size = nums.size();
    int min = INF_32, max = -INF_32;
    bool flag = false;
    for (int i = 1; i < size; i++) {
        if (nums[i] < nums[i - 1])
            flag = true;
        if (flag)
            min = std::min(min, nums[i]);
    }

    flag = false;
    for (int i = size - 2; i >= 0; i--) {
        if (nums[i] > nums[i + 1])
            flag = true;
        if (flag)
            max = std::max(max, nums[i]);
    }

    int l, r;
    for (l = 0; l < size; l++) {
        if (min < nums[l])
            break;
    }
    for (r = size - 1; r >= 0; r--) {
        if (max > nums[r])
            break;
    }

    return r - l < 0 ? 0 : r - l + 1;
}

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    cout << findUnsortedSubarray(nums) << endl;
}