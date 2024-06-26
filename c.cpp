#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x)
{
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
struct fast
{
    fast()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;
int N, A[200000], B[200000];
vector<pr> ans;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        --A[i];
        B[A[i]] = i;
    }

    for (int i = 0; i < N; ++i)
        if (A[i] != i)
        {
            int j = B[i];
            ans.emplace_back(i, j);
            swap(A[i], A[j]);
            B[A[i]] = i;
            B[A[j]] = j;
        }

    int K = ans.size();
    cout << K << '\n';
    for (pr &p : ans)
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}
