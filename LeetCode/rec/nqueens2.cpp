#include<bits/stdc++.h>

using namespace std;

vector<string> s(8);
map<int, int> row, col, diag1, diag2;
int req;

int rec(int i, int j, map<int, int> s_row, map<int, int> s_col, map<int, int> s_diag1, map<int, int> s_diag2, int cnt){

    if(cnt == req){
        return 1;
    }

    for(int r = 0; r<8; r++){
        for(int c = 0; c<8; c++){
            if(row[r] || col[c] || diag1[i+j] || diag2[i-j]){
                continue;
            }
            
        }
    }
}

signed main(){
    req = 8;
    for(int i=0; i<8; i++){
        cin>>s[i];
        for(int j = 0; j<8; j++){
            if(s[i][j] == '*'){
                req--;
                row[i] = 1, col[j] = 1, diag1[i+j] = 1, diag2[i-j] = 1;
            }
        }
    }
    map<int, int> s_col, s_row, s_diag1, s_diag2;
    cout<<rec(0, 0, s_col, s_row, s_diag1, s_diag2, 0)<<endl;;
    
}