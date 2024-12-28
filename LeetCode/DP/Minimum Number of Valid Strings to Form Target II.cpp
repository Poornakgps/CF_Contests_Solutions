#include<bits/stdc++.h>

using namespace std;

vector<int> z_fun(string &s, string &t){
    string w = s+'#'+t;

    int l = 0, r = 0;

    int n = w.size();
    vector<int> z(n, 0); 
    for(int i=1; i<n; i++){
        if(i<r){
            z[i] = min(r-i, z[i-l]);
        }

        while(i+z[i]<n && w[i+z[i]] == w[z[i]]){
            z[i]++;
        }
        if(z[i]+i>r){
            r = z[i] + i;
            l = i;
        }
    }

    vector<int>ans;
    for(int i=s.size()+1;i<n;i++){
        ans.push_back(z[i]);
    }
    return ans;
}

int minValidStrings(vector<string>& a, string s) {
    int n=s.size();
    vector<int>mx(n,-1);
    for(int i=0;i<a.size();i++){
        vector<int>temp=z_fun(a[i],s);

        for(int j=0;j<s.size();j++) mx[j]=max(mx[j],temp[j]);
    }
    priority_queue<pair<int,int> >pq;
    set<int>st;
    vector<int>dp(n,1e9);
    for(int i=0;i<n;i++){
        pq.push({-(mx[i]+i-1),i});
        st.insert(i);
        while(!pq.empty() && -pq.top().first<i){
            st.erase(pq.top().second);
            pq.pop();
        }
        if(pq.empty()) return -1;
        int ind=*st.begin();
        if(ind==0){
            dp[i]=1;
        }
        else 
            dp[i]=dp[ind-1]+1;
    }
    return dp[n-1];
}

signed main(){
    int n;
    cin>>n;

    vector<string> str;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        str.push_back(s);
    } 
    string target;
    cin>>target;
    int ans = minValidStrings(str, target);
    cout<<ans<<endl;
}