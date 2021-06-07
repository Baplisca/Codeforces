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
typedef complex<double> P;
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
        ll n, l, r, s;
        cin >> n >> l >> r >> s;
        int cnt = r - l + 1;
        ll ma = 0, mi = 0;
        rep(i, cnt) ma += n - i;
        rep(i, cnt) mi += i + 1;
        // out(ma);
        // out(mi);
        if (s < mi || s > ma)
            out(-1);
        else
        {
            vl ans(cnt);
            iota(all(ans), 1);
            s -= cnt * (cnt + 1) / 2;
            reverse(all(ans));
            rep(i, cnt)
            {
                while (1)
                {
                    if (s <= 0)
                        break;
                    if (ans[i] >= n - i)
                        break;
                    ans[i]++;
                    s--;
                }
            }
            map<int, int> mp;
            rep(i, cnt)
            {
                mp[ans[i]]++;
            }
            vl res;
            rep1(i, n + 1) if (mp[i] == 0) res.push_back(i);
            int ans_idx = 0, res_idx = 0;
            rep(i, n)
            {
                if (i)
                    cout << " ";
                int I = i + 1;
                if (l <= I && I <= r)
                {
                    cout << ans[ans_idx++];
                }
                else
                    cout << res[res_idx++];
            }
            cout << endl;
        }
    }
}
