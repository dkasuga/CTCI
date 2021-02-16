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

void swapTwoNum(int& a, int& b)
{
    int diff = a - b;
    a = diff;
    b = diff + b; // a
    a = b - diff;
}

void swapTwoNum2(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    swapTwoNum2(a, b);
    cout << a << " " << b << endl;
    return 0;
}
