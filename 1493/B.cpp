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

map<int, bool> mp;
map<int, int> mp1;
bool judge(int num)
{
    int num1 = num % 10;
    int num2 = (num / 10) % 10;
    return (mp[num1] && mp[num2]);
}
int mirror_trans(int num)
{
    int num1 = num % 10;
    int num2 = (num / 10) % 10;
    return (mp1[num1] * 10 + mp1[num2]);
}
signed main()
{
    //gearup;
    int t;
    cin >> t;
    mp[0] = mp[1] = mp[2] = mp[5] = mp[8] = true;
    mp1[0] = 0, mp1[1] = 1, mp1[2] = 5, mp1[5] = 2, mp1[8] = 8;
    rep(i, t)
    {
        int h, m;
        string s;
        cin >> h >> m >> s;
        int hh = (s[0] - '0') * 10 + s[1] - '0';
        int mm = (s[3] - '0') * 10 + s[4] - '0';
        // mm is to h, hh is to m
        while (1)
        {
            if (judge(hh) && judge(mm))
            {
                int mirror_hh = mirror_trans(mm);
                int mirror_mm = mirror_trans(hh);
                //cout << mirror_hh << " " << mirror_mm << endl;
                if (mirror_hh < h && mirror_mm < m)
                {
                    //cout << mirror_trans(mirror_mm) << ":" << mirror_trans(mirror_hh) << endl;
                    string HH = to_string(mirror_trans(mirror_mm));
                    if (HH.size() == 1)
                        HH = "0" + HH;
                    string MM = to_string(mirror_trans(mirror_hh));
                    if (MM.size() == 1)
                        MM = "0" + MM;
                    cout << HH << ":" << MM << endl;
                    break;
                }
            }
            mm++;
            if (mm >= m)
            {
                hh++;
                mm = 0;
            }
            if (hh >= h)
            {
                cout << "00:00" << endl;
                break;
            }
        }
    }
}
