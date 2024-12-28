#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define N 300005

struct DSURollback {
    int n;
    int parent[N], rnk[N];
    vector<pair<int, int>> stck;
    int sz[N];
    int comp, curr = -1;

    void init(int n) {
        curr = -1;
        comp = n;
        for (int i = 1; i <= n; i++) {
            rnk[i] = 1;
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return find(parent[x]);
    }

    void merge(int x, int y) {
        int xparent = find(x);
        int yparent = find(y);

        if (xparent == yparent) return;

        if (rnk[xparent] > rnk[yparent]) swap(xparent, yparent);

        rnk[yparent] += rnk[xparent];
        parent[xparent] = yparent;
        stck.eb(xparent, yparent);
        curr++;
        sz[curr] = comp;
        comp--;
    }

    void roll_back(int st) {
        while (curr > st) {
            parent[stck[curr].first] = stck[curr].first;
            rnk[stck[curr].second] -= rnk[stck[curr].first];
            comp = sz[curr];
            curr--;
            stck.pop_back();
        }
    }
} ds;

vector<pair<int, int>> t[4 * N];
vector<pair<int, int>> ans;
int query[300001];
pair<int, int> p;

void update(int id, int l, int r, int lq, int rq) {
    if (lq > r || rq < l) return;
    if (lq <= l && rq >= r) {
        t[id].eb(p);
        return;
    }
    int m = (l + r) >> 1;
    update(id << 1, l, m, lq, rq);
    update((id << 1) | 1, m + 1, r, lq, rq);
}

void dfs(int id, int l, int r) {
    int prev = ds.curr;

    for (auto v : t[id]) {
        ds.merge(v.first, v.second);
    }

    if (l == r) {
        if (query[l] != -1) {
            ans.pb({query[l], ds.comp});
        }
    } else {
        int m = (l + r) >> 1;
        dfs(id << 1, l, m);
        dfs((id << 1) | 1, m + 1, r);
    }

    ds.roll_back(prev);
}

signed main() {

    // #define NAME "connect"
    // assert(freopen(NAME ".in", "r", stdin));
    // assert(freopen(NAME ".out", "w", stdout));
    int n, q;
    cin >> n >> q;
    ds.init(n);
    memset(query, -1, sizeof(query));

    map<pair<int, int>, int> mp;

    for (int i = 1; i <= q; i++) {
        char c;
        cin >> c;

        if (c == '+') {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            mp[{a, b}] = i;
        } else if (c == '-') {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            p = {a, b};
            update(1, 0, q, mp[{a, b}], i);
            mp.erase(p);
        } else {
            query[i] = i;
        }
    }

    for (auto it : mp) {
        p = it.first;
        update(1, 0, q, it.second, q);
    }

    dfs(1, 0, q);
    sort(ans.begin(), ans.end());

    for (auto it : ans) {
        cout << it.second << " \n";
    }
    cout << endl;
}
