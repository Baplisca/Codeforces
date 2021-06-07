#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long INF = 1LL << 60;
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    UnionFind(int N) : par(N),siz(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++){
             par[i] = i;
             siz[i] = 1;
        }
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        // merge technique（小を大にくっつける）
        if (siz[rx] < siz[ry]) swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    ll size(ll x){
        return siz[root(x)];
    }
};

signed main()
{   
    gearup;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>> p;
        vector<pair<int,int>> res;
        vector<int> a(n);
        int cnt = 0;
        rep(i,n)cin>>a[i];
        auto b = a;
        sort(all(a));
        a.erase(unique(all(a)), a.end());
        vl c(n);
        rep(i,n){
            c[i] = lower_bound(all(a),b[i]) - a.begin();
            p.push_back({c[i],i});
        }
        sort(all(p));
        UnionFind uf(n);
        rep(i,n)rep(j,n){
            if(i == j)continue;
            int type_i = p[i].first;
            int type_j = p[j].first;
            if(!uf.same(i,j) && type_i != type_j){
                uf.unite(i,j);
                res.push_back({p[i].second, p[j].second});
                cnt++;
            }
        }
        if(cnt != n-1)cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            rep(i,n-1) cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
        }
    }
}