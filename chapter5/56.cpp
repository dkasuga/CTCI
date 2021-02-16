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
ある整数AからBに変換するのに必要なbit数を決定する関数を書け
XORをとったときに現れる各bitの１は，その場所のAとBのbitが異なっていることを表す．
なので単にAとBの各桁を比べていけばよい (O(bit数))
が，もっと改善できる
要は，aとbの異なる部分だけ抽出できればよい
c=a^b
c = c&(c-1)で，cの一番下位（右側）にある1を反転する
*/

int bitConversion(int a, int b)
{
    int count = 0;
    for (int c = a ^ b; c != 0; c = c & (c - 1)) {
        count++;
    }
    return count;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << bitConversion(a, b) << endl;
    return 0;
}
