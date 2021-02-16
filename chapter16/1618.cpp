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

string buildFromPattern(string pattern, string main, string alt)
{
    string sb = "";
    char first = pattern[0];
    for (char c : pattern) {
        if (c == first) {
            sb += main;
        } else {
            sb += alt;
        }
    }
    return sb;
}

// O(N^4)
bool doesMatch1(string pattern, string value)
{
    if (pattern.size() == 0)
        return value.size() == 0;

    int size = value.size();
    for (int mainsize = 0; mainsize < size; mainsize++) {
        string main = value.substr(0, mainsize);
        for (int altStart = mainsize; altStart <= size; altStart++) {
            for (int altEnd = altStart; altEnd <= size; altEnd++) {
                string alt = value.substr(altStart, altEnd - altStart);
                string cand = buildFromPattern(pattern, main, alt);
                if (cand == value) {
                    return true;
                }
            }
        }
    }

    return false;
}

int countOf(string pattern, char c)
{
    int count = 0;
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == c){
            count++;
        }
    }
    return count;
}

bool doesMatch2(string pattern, string value)
{
    if (pattern.size() == 0)
        return value.size() == 0;

    char mainChar = pattern[0];
    char altChar = mainChar == 'a' ? 'b' : 'a';
    int size = value.size();

    int countOfMain = countOf(pattern, mainChar);
    int countOfAlt = (int)pattern.size() - countOfMain;
    int firstAlt = (int)pattern.size();

    for (int i = 0; i < (int)pattern.size(); i++) {
        if (pattern[i] == altChar) {
            firstAlt = i;
            break;
        }
    }
    int maxMainSize = size / countOfMain;

    for (int mainSize = 0; mainSize <= maxMainSize; mainSize++) {
        int remainingLength = size - mainSize * countOfMain;
        string first = value.substr(0, mainSize);
        if (countOfAlt == 0 || remainingLength % countOfAlt == 0) {
            int altIndex = firstAlt * mainSize;
            int altSize = countOfAlt == 0 ? 0 : remainingLength / countOfAlt;
            string second = countOfAlt == 0 ? "" : value.substr(altIndex, altSize);
            string cand = buildFromPattern(pattern, first, second);
            if(cand == value){
                return true;
            }
        }
    }

    return false;
}

// 指定されたオフセットから始まりsize文字分，2つの部分文字列が等しいかどうかをチェックする
bool isEqual(string s1, int offset1, int offset2, int size){
    for(int i=0;i<size;i++){
        if(s1[offset1+i] != s1[offset2+i]) return false;
    }
    return true;
}
// patternとvalueを走査する
// pattern内の各文字でそれがmainかaltか調べる
// その後valueの次の文字セットが，それらの文字の元のセット（main or alt）と一致するかどうかを調べる
bool matches(string pattern, string value, int mainSize, int altSize, int firstAlt){
    int stringIndex = mainSize;
    for(int i=1;i<pattern.size();i++){
        int size = pattern[i] == pattern[0] ? mainSize : altSize;
        int offset = pattern[i] == pattern[0] ? 0 : firstAlt;
        if(!isEqual(value, offset, stringIndex, size)){
            return false;
        }
        stringIndex += size;
    }
    return true;
}

bool doesMatch3(string pattern, string value)
{
    if (pattern.size() == 0)
        return value.size() == 0;

    char mainChar = pattern[0];
    char altChar = mainChar == 'a' ? 'b' : 'a';
    int size = value.size();

    int countOfMain = countOf(pattern, mainChar);
    int countOfAlt = (int)pattern.size() - countOfMain;
    int firstAlt = (int)pattern.size();

    for (int i = 0; i < (int)pattern.size(); i++) {
        if (pattern[i] == altChar) {
            firstAlt = i;
            break;
        }
    }
    int maxMainSize = size / countOfMain;

    for (int mainSize = 0; mainSize <= maxMainSize; mainSize++) {
        int remainingLength = size - mainSize * countOfMain;
        string first = value.substr(0, mainSize);
        if (countOfAlt == 0 || remainingLength % countOfAlt == 0) {
            int altIndex = firstAlt * mainSize;
            int altSize = countOfAlt == 0 ? 0 : remainingLength / countOfAlt;
            if(matches(pattern, value, mainSize, altSize, altIndex)){
                return true;
            }
        }
    }

    return false;
}
int main()
{
    string pattern, value;
    cin >> pattern >> value;
    if (doesMatch3(pattern, value)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}