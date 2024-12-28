#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<int, int>
typedef long long ll;
#define vi vector<ll>
#define fill(v) for(auto& i: v) cin>>i;
#define has(c, x) {return c.find(x)!=c.end();}
#define pr(v) for(auto i: v) cout<<i<<" "; cout<<endl;
#define pr1(v, i) for(auto j: v) cout<<j[i]<<" "; cout<<endl; 
#define del(s, x) if(s.find(x)!=s.end()) s.erase(s.find(x)) 
#define show(x) cout<<#x<<": "<<x<<" ";
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 300005
#define N_LMT 100001
#define janu main
#define int long long
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }

template <typename Key, typename Mapped, typename Comp = less<Key>>
using ordered_map = tree<Key, Mapped, Comp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename Key, typename Comp = less<Key>>
using ordered_set = tree<Key, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

/***************************************C-H-A-O-S**************************************/
int mex(vector<ll>& numberArray) {  // munda mex
    set<ll> sett;
    for(int i = 0; i < numberArray.size(); i++) 
        sett.insert(numberArray[i]);
    for(int i = 0; i < 1000001; i++)
        if(!sett.count(i)) return i;
    return -1;
}
ll gcd(ll a, ll b){ if(b==0) return a; else return gcd(b,a%b); }

ll binpow(ll a, ll b, ll m ) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res%m;
}
void add_m(ll &a, ll b) {
    a += b;
}

ll mul_m(ll a, ll b, ll m) {
    return (a * 1LL * b) % m;
}

int max_profit(vector<int>& arr, int x, int y, int z) {
    int n = arr.size();

    // Initialize a 4D dp array with -inf
    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1, INT_MIN))));

    // Base case: no elements considered, no subarrays taken
    dp[0][0][0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j1 = 0; j1 <= x; ++j1) {
            for (int j2 = 0; j2 <= y; ++j2) {
                for (int j3 = 0; j3 <= z; ++j3) {
                    // Option 1: Don't pick any subarray ending at i-1
                    dp[i][j1][j2][j3] = dp[i - 1][j1][j2][j3];

                    // Option 2: Pick a 1-sized subarray ending at i-1
                    if (j1 > 0) {
                        dp[i][j1][j2][j3] = max(dp[i][j1][j2][j3], dp[i - 1][j1 - 1][j2][j3] + arr[i - 1]);
                    }

                    // Option 3: Pick a 2-sized subarray ending at i-1
                    if (i >= 2 && j2 > 0) {
                        dp[i][j1][j2][j3] = max(dp[i][j1][j2][j3], dp[i - 2][j1][j2 - 1][j3] + arr[i - 2] + arr[i - 1]);
                    }

                    // Option 4: Pick a 3-sized subarray ending at i-1
                    if (i >= 3 && j3 > 0) {
                        dp[i][j1][j2][j3] = max(dp[i][j1][j2][j3], dp[i - 3][j1][j2][j3 - 1] + arr[i - 3] + arr[i - 2] + arr[i - 1]);
                    }
                }
            }
        }
    }

    int max_profit = 0;
    for (int j1 = 0; j1 <= x; ++j1) {
        for (int j2 = 0; j2 <= y; ++j2) {
            for (int j3 = 0; j3 <= z; ++j3) {
                max_profit = max(max_profit, dp[n][j1][j2][j3]);
            }
        }
    }

    return max_profit;
}

void solve(){

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=1; i<=n; i++){
        depth[i] = 1e9;
        sz[i]=0;
        adj[i].clear();
        parent[i] = 0;
        child_sum[i]=0;
    }
    for(int i=2; i<=n; i++){
        ll x;
        cin>>x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    ll ans = 0;

    dfs(1); 

    deque<int> que;
    que.pb(1);

    while(que.size()){
        auto i = que.front();
        que.pop_front();
        ll sum  = 0, freq = 1e9, chosen = -1;
        if(child_sum[i]<a[i] && (adj[i].size()>1 || i==1)){
            for(auto it: adj[i]){
                if(it!=parent[i]){
                    cout<<depth[it]<<endl;
                    if(freq>sz[it]-1){
                        chosen = it;
                        freq = sz[it]-1;
                        sum = child_sum[it];
                    }
                    else if(freq==sz[it]-1){
                        if(sum<child_sum[it]){
                            chosen = it;
                        }
                        sum = max(sum, child_sum[it]);
                    }
                }
            }
            // cout<<i<<endl;
            if(freq==1e9){
                freq=0;
            }
            ans+= freq*(a[i]) - sum + (a[i] - child_sum[i]);
        }
        for(auto it: adj[i]){
            if(it!=parent[i] && it!=chosen){
                que.pb(it);
            }
        }
    }
    cout<<ans<<endl;
}


signed janu(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    cin>>t;
    while (t--){
        solve();
    }
}


void solve() {

    int n, d, k;
    cin>>n>>d>>k;

    vector<ll> a(n+2, 0);

    for(int i=0; i<k; i++){
        ll l, r;
        cin>>l>>r;
        a[l]++;
        a[r+1]--;
    }

    for(int i=0; i<=n; i++){
        a[i+1] = a[i+1] + a[i];
    }
    

}


// void solve() 
// {
//     int n, m; cin >> n >> m;
    
//     vector <int> cnt(m + 2, 0);
//     vector <int> dp(m + 1, -1e9);
//     dp[0] = 0;
    
//     auto update = [&](){
//         for (int i = 1; i <= m; i++){
//             cnt[i] += cnt[i - 1];
//         }  
        
//         for (int i = 0; i <= m; i++){
//             dp[i] += cnt[i];
//         }
        
//         auto ndp = dp;
//         for (int i = 1; i <= m; i++){
//             ndp[i] = max(ndp[i], dp[i - 1]);
//         }
        
//         dp = ndp;
        
//         for (auto &x : cnt){
//             x = 0;
//         }
//     };
    
//     int curr = 0;
//     for (int i = 1; i <= n; i++){
//         int x; cin >> x;
        
//         if (x == 0){
//             update();
//             curr++;
//         } else if (x > 0){
//             cnt[x]++;
//         } else {
//             x = -x;
//             if (x <= curr){
//                 cnt[0]++;
//                 cnt[curr - x + 1]--;
//             }
//         }
//         for(auto it: cnt) cout<<it<<" ";
//         endl();
//         for(auto it: dp){
//             cout<<it<<" "; 
//         }
//         endl();
//         endl();
//     }
    
//     update();
//         for(auto it: dp){
//             cout<<it<<" "; 
//         }
//         endl();
//     int ans = *max_element(dp.begin(), dp.end());
//     cout << ans << "\n";
// }