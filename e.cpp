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

ll N;
int A, X, Y;

map<ll, bool> b;
map<ll, double> m;
int cnt = 0;
double f(ll N)
{

    if (b[N])
        return m[N];
    ++cnt;
    b[N] = 1;
    m[N] = f(N / A) + X;
    double t = 0;
    for (int i = 2; i < 7; ++i)
        t += f(N / i);
    t /= 5;

    chmin(m[N], t + (double)Y * 6 / 5);
    return m[N];
}

int main()
{
    b[0] = 1;
    cin >> N >> A >> X >> Y;
    cout << setprecision(7) << fixed;
    cout << f(N) << '\n';

    cerr << cnt << '\n';
}
