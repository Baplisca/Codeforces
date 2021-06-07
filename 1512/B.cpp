#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i < n; ++i)
#define exrep(i, a, b) for (ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<vector<double>> vvd;
typedef vector<vector<string>> vvs;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
ll MOD = 998244353;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

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
template <class T>
void debug(T v)
{
    rep(i, v.size()) cout << v[i] << " ";
    cout << endl;
}
ll pcount(ll x) { return __builtin_popcountll(x); }
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

signed main()
{
    gearup;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vs s(n);
        rep(i, n) cin >> s[i];
        vpii p;
        rep(i, n) rep(j, n) if (s[i][j] == '*') p.push_back({i, j});
        sort(all(p));
        int x1 = p[0].first;
        int x2 = p[1].first;
        int y1 = p[0].second;
        int y2 = p[1].second;
        //int x3, x4, y3, y4;
        if (x1 == x2)
        {
            if (x1 != n - 1)
            {
                s[n - 1][y1] = '*';
                s[n - 1][y2] = '*';
            }
            else
            {
                s[0][y1] = '*';
                s[0][y2] = '*';
            }
        }
        else if (y1 == y2)
        {
            if (y1 != n - 1)
            {
                s[x1][n - 1] = '*';
                s[x2][n - 1] = '*';
            }
            else
            {
                s[x1][0] = '*';
                s[x2][0] = '*';
            }
        }
        else
        {
            s[x1][y2] = '*';
            s[x2][y1] = '*';
        }
        rep(i, n)
        {
            rep(j, n)
            {
                cout << s[i][j];
            }
            cout << endl;
        }
    }
}
