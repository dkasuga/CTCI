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
2つの線分（始点と終点がある線）が与えられたとき，交点が存在する場合は計算しろ
a0*x+b0*y+c0=0
a1*x+b1*y+c1=0

(a0 b0
 a1 b1)
 (x, y) = (c0, c1)
a0*b1-b0*a1 != 0
もしこれが等しい場合は，直線として一致しており（y切片も一致）かつ範囲が重なっている必要がある
逆行列を求めて，右のベクトルにかける
これで出てきたxの値が，もとの線分の範囲に存在するかを調べる
*/
int main()
{
    return 0;
}
