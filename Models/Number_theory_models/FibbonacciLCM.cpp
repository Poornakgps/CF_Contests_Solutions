#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

const int N = 3e5 + 9, mod= 1e9 + 7;

int power(long long n, long long k) {
    int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
    while (k) {
        if (k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
    return ans;
}
int fib(long long n) {
    assert (n >= 0);
    if (n <= 1) return n;
    int a = 0;
    int b = 1;
    long long i = 1ll << (63 - __builtin_clzll(n) - 1);
    for (; i; i >>= 1) {
        int na = (a *(long long) a + b *(long long) b) % mod;
        int nb = (2ll * a + b) * b % mod;
        a = na;
        b = nb;
        if (n & i) {
        int c = a + b; if (c >= mod) c -= mod;
        a = b;
        b = c;
        }
    }
    return b;
}

struct Matrix{
    ll n = 2;
    vector<vector<ll>> v = vector<vector<ll>> (n, vector<ll> (n));
    void operator *=(const Matrix& B){
        vector<vector<ll>> mul(n, vector<ll>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    mul[i][k]+=(v[i][j]*B.v[j][k])%mod;
                    mul[i][k]%=mod;
                }
            }
        }
        v=mul;
    }
};
 
Matrix expo(Matrix A, ll m){
    Matrix result;
    ll n=2;
    for(int i=0;i<n;i++) result.v[i][i]=1;
    while(m){
        if(m%2!=0){
            result*=A;
        }
        m/=2;
        A*=A;
    }
    return result;
}
map<vector<int>, int> dp;
Matrix A;
/**
O((max number of divisors of a[i]) * n * log(max a[i])) but faster in practice
lcm(a1, a2, ... an) 
= lcm(lcm(a1, ..., a[n-1]), an)
= lcm(a1, ..., a[n-1]) * an / gcd(lcm(a1, ..., a[n-1]), an)
= lcm(a1, ..., a[n-1]) * an / lcm(gcd(a1, an), ... gcd(a[n-1], an))
1<=n<=100
1<=ai<=1e9
**/
int yo(vector<int> a) {

    sort(a.rbegin(), a.rend());
    while (!a.empty() && a.back() <= 2) a.pop_back();
    a.resize(unique(a.begin(), a.end()) - a.begin());
    if (a.empty()) return 1;
    if (a.size() == 1){ 
        Matrix B=expo(A, a[0]-1);
        int ans=B.v[0][0];
        return ans;
    }
    if (dp.count(a)) return dp[a];
    vector<int> b(a.begin(), a.end() - 1);
    long long res = yo(b);
    for (int i = 0; i < b.size(); ++i) b[i] = __gcd(b[i], a.back());
    Matrix B=expo(A, a.back()-1);
    int ans=B.v[0][0];
    res = res * ans % mod * power(yo(b), mod - 2) % mod;
    dp[a] = res;
    return res;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    A.v={{1, 1}, {1, 0}};
    for (auto &x: a) cin >> x;
    cout << yo(a) << '\n';
    return 0;
}
//https://www.hackerrank.com/contests/infinitum10/challenges/fibonacci-lcm/problem