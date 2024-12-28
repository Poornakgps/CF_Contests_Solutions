#include <bits/stdc++.h>

#include <iostream>
#include <set>
#include <fstream>
#include <string>
using namespace std;
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


set<long long> st1, st2;

void generateMountainNumbers(int len, int prev_digit, set<long long>& results, int k, string& s) {
    if (len < k) {
        for (int cur = prev_digit; cur <= 8; ++cur) {
            s += to_string(cur);
            generateMountainNumbers(len + 1, cur, results, k, s);
            s.pop_back();  // backtrack
        }
    } else if (len == k) {
        results.insert(stoll(s));
    } 
}

set<long long> generateAllMountainNumbers(int max_digits) {
    set<long long> results;

    for (int k = 0; k <= (max_digits - 1) / 2; ++k) {
        for (int sd = 1; sd <= 8; ++sd) {  // Starting digit can't be 0
            string s = to_string(sd);
            generateMountainNumbers(1, sd, results, k, s);
        }
    }

    return results;
}

map<pair<int, int>, int> mp;
vector<ll> vt1, vt2, vt_mountain;

ll solve() {
    ll a, b, m;
    cin >> a >> b >> m;

    ll ans = 0;
    auto it = lower_bound(all(vt_mountain), a);
    while (it != vt_mountain.end() && *it <= b) {
        if (*it >= a && *it <= b && *it % m == 0) {
            ans++;
        }
        it++;
    }
 
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // I/O Setup
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    ll t = 1;
    inputFile >> t;
    int i = 1;
    st1 = generateAllMountainNumbers(17);

    for (auto it : st1) {
        vt1.pb(it);
        string s = to_string(it);
        reverse(all(s));
        vt2.pb(stoll(s));
    }

    map<ll, ll> l, r;
    for (int i = 0; i < vt1.size(); i++) {
        ll sz = to_string(vt1[i]).size();
        if (l[sz]) {
            r[sz] = i;
        } else {
            l[sz] = i;
            r[sz] = i;
        }
    }

    // Generate mountain numbers by combining ascending and descending parts
    for (int i = 0; i < vt1.size(); i++) {
        ll rem = vt1[i] % 10;
        int sz1 = to_string(vt1[i]).size();
        for (int digit = rem + 1; digit <= 9; digit++) {
            for (int j = l[sz1]; j <= r[sz1]; j++) {
                int sz2 = to_string(vt2[j]).size();
                int rem2 = (int)(to_string(vt2[j])[0] - '0');
                if (rem2 < digit) {
                    string s = to_string(vt1[i]) + (to_string(digit)) + to_string(vt2[j]);
                    vt_mountain.pb(stoll(s));
                }
            }
        }
    }

    while (t--) {
        ll result = solve();
        outputFile << "Case #" << i << ": " << result << endl;
        i++;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;
}