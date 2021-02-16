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

/*
ある整数があり，その中の1bitだけ0から1に反転することができる．このような操作を行うとき，1の並びが最も長いときの長さを求めるコードをかけ

- brute Force
- 0と1の並びの長さを要素とした配列に変換して
似たような問題をAtCoderで見た記憶がある
11011101111
2, 1, 3, 1, 4
両端は1の集合から始まるように
1, 0, 1, 0, 1


(1の並びA) (0の並びB) (1の並びC)
というグループに注目する
- A+1, C+1, A+1+C(if B==1)がそれぞれ候補なのでそれをmaxにとる
- 0始まり，2始まり，4始まり
    - この3連続が取れるまで
    - i+2 < lengthまで
*/

vector<int> getAlternatingSequences(int n)
{
    // まずbitの列に変換する
    vector<int> bit;
    while (n > 0) {
        if (n & 1)
            bit.push_back(1);
        else {
            bit.push_back(0);
        }
        n >>= 1;
    }

    vector<int> seq;
    int i = 0;
    int bit_size = bit.size();

    while (i < bit_size) {
        // 1が続くパート
        int cnt_one = 0;
        while (i < bit_size && bit[i] == 1) {
            cnt_one++;
            i++;
        }
        seq.push_back(cnt_one);

        if (i == bit_size)
            break;
        // 0が続くパート
        int cnt_zero = 0;
        while (i < bit_size && bit[i] == 0) {
            cnt_zero++;
            i++;
        }
        seq.push_back(cnt_zero);
    }

    if (bit.back() == 0)
        seq.push_back(0);
    return seq;
}

int longestBitSequence(const vector<int>& seq)
{
    int max_length = 0;
    int size = seq.size();
    for (int i = 0; i + 2 < size; i += 2) {
        if (seq[i + 1] == 1) {
            max_length = max(max_length, seq[i] + seq[i + 2] + 1);
        } else {
            max_length = max(max_length, seq[i] + 1);
            max_length = max(max_length, seq[i + 2] + 1);
        }
    }

    return max_length;
}

int main()
{
    int n;
    cin >> n;
    vector<int> seq = getAlternatingSequences(n);
    cout << longestBitSequence(seq) << endl;
    return 0;
}
