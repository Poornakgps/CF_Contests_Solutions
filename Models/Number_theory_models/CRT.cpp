#include<bits/stdc++.h>
using namespace std;

#define ll long long
/*
    You are given two modular congruences:
    1. x mod m1 = a1
    2. x mod m2 = a2
    where m1 and m2 may not be coprime. Your task is to find a value of x such that both congruences hold, and x is unique modulo 𝑚=lcm(𝑚1,𝑚2). 
    If no such x exists, return an indication of failure(-1).
    0 <= m1, m2 <= 1e18
    0 <= a1,a2 <= m1,m2
*/

// ax + by = __gcd(a, b)
// returns __gcd(a, b)
ll extended_euclidian(ll a, ll b ,ll &x, ll &y ){
  ll xx = y = 0;
  ll yy = x = 1;
  while (b) {
    ll q = a / b;
    ll t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
  }
  return a;
}
// finds x such that x % m1 = a1, x % m2 = a2. m1 and m2 may not be coprime
// here, x is unique modulo m = lcm(m1, m2). returns (x, m). on failure, m = -1.
pair<ll,ll> CRT(ll a1, ll m1, ll a2, ll m2){

    ll p, q;
    ll g = extended_euclidian(m1, m2, p, q);
    // cout << g << endl;
    // cout<< p<<" "<<q <<endl;
    if (a1 % g != a2 % g) return make_pair(0, -1);
    ll m = m1*m2 / g;
    p = (p % m + m) % m;
    q = (q % m + m) % m;
    // cout << m <<" "<<m1<<" "<<m2 <<endl;
    
    ll x = (p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) %  m;
    // cout<<(x%m1) <<" "<<a1<<" "<<m1<<" "<< (x%m2)<<" "<< a2 <<" "<<m2<<endl;
    return make_pair(x, m);
}

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << (int)CRT(5, 9, 13, 32).first << '\n';
  return 0;
}