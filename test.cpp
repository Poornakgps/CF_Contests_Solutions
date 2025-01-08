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
typedef long long ll;
#define pii pair<ll, ll>
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
#define testcase_(i, val) cout<<"Case #"<<i<< ": "<< val<<endl;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 300005
#define N_LMT 200200
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }

template <typename Key, typename Mapped, typename Comp = less<Key>>
using ordered_map = tree<Key, Mapped, Comp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename Key, typename Comp = less<Key>>
using ordered_set = tree<Key, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

void debug(vi v){
    for(auto it: v){
        cerr<<it<<" ";
    }
    cerr<<endl;
}
void print(vi v){
    for(auto it: v){
        cerr<<it<<" ";
    }
    cerr<<endl;
}
ll gcd(ll a, ll b){ if(b==0) return a; else return gcd(b,a%b); }

int mex(vector<ll>& numberArray) {  // munda mex
    set<ll> sett;
    for(int i = 0; i < numberArray.size(); i++) 
        sett.insert(numberArray[i]);
    for(int i = 0; i < 1000001; i++)
        if(!sett.count(i)) return i;
    return -1;
}

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
ll fac[2000001];

ll inv(ll a){ return binpow(a,mod_10-2,mod_10); }
 
ll ncr(ll n, ll r){
    if(n<r || r<0){
        return 0;
    }
    if(r==0){
        return 1;
    }
    ll ans = 1;
    ans = (ans*fac[n])%mod_10;
    ans = (ans*inv(fac[r]))%mod_10;
    ans = (ans*inv(fac[n - r]))%mod_10;
    return ans%mod_10;
} 

<<<<<<< HEAD

void solve() {
=======
void solve() {

    ll l, r; cin >> l >> r;
    if(r-l == 2){
        cout<<l <<" "<<l + 1<<" "<<r<<endl;
        return;
    }

    ll a = 0, b = 0, c = 0;
    map<ll,ll> vis;
    // a
    a = r;
    for(ll bit=29; bit>=0; bit--){
        if(((r>>bit)&1)){
            vis[bit] = 1;
        }
    }
    // b
    bool fk = false;
    for(ll bit=29; bit>=0; bit--){
        if(((r>>bit)&1) && ((l>>bit)&1) && !fk){
            b+=pow(2, bit);
        }
        else{
            if(((r>>bit)&1) && !((l>>bit)&1)){
                b+=pow(2, bit)-1;
                break;
            }
        }
    }
>>>>>>> ab6752b (added files)

    c = 0;
    // change = false;
    for(ll bit=29; bit>=0; bit--){
        if(((a>>bit)&1) && (c+(pow(2, bit) - 1)<l)){
            c+=pow(2, bit);
        }
        else{
            if((!((a>>bit)&1) && ((b>>bit)&1)  && (c+pow(2, bit)<r)) || (((a>>bit)&1) && !((b>>bit)&1)  && (c+pow(2, bit)<r))){
                c+= (pow(2, bit));
            }
        }
    }
    if(c == b){
        c--;
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
}

int main() {
    // ifstream inputFile("input.txt");  // Open input file
    // ofstream outputFile("output.txt"); // Open output file
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t=1;
    cin >> t;
    int i = 1;

    while (t--) {
        solve();
        // inputFile >> a >> b >> m; // Read from input file
        // outputFile << "Case #" << i << ": " << solve(a, b, m) << endl; // Write to output file
        i++;
    }

    // inputFile.close();   // Close input file
    // outputFile.close();  // Close output file

    return 0;
}