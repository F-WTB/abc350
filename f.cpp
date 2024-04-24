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

string S, T;
int N, bady[500000];

void make_bady()
{
    stack<int> st;
    for (int i = 0; i < N; ++i)
    {
        if (S[i] == '(')
            st.push(i);
        if (S[i] == ')')
        {
            int j = st.top();
            st.pop();
            bady[j] = i;
            bady[i] = j;
        }
    }
}

char f(char c, int d)
{
    if (d == 1)
        return c;
    return c + (c < 'a' ? 1 : -1) * ('a' - 'A');
}

int main()
{
    cin >> S;
    N = S.size();
    make_bady();

    for (int i = 0, d = 1; i < N; i += d)
    {
        if (S[i] == '(' || S[i] == ')')
        {
            d *= -1;
            i = bady[i];
        }
        else
            T += f(S[i], d);
    }

    cout << T << '\n';
}
