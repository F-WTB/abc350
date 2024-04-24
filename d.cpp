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

int N, M, A, B, cnt[200000];

int main()
{
    cin >> N >> M;
    dsu d(N);
    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B;
        --A, --B;
        ++cnt[A];
        d.merge(A, B);
    }

    ll ans = 0;
    for (auto g : d.groups())
    {
        int k = 0;
        for (int v : g)
            k += cnt[v];
        ans += (ll)g.size() * (g.size() - 1) / 2 - k;
    }
    cout << ans << '\n';
}
