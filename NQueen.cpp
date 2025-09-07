#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>&v){
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==1){
                cout<<"Q";
            }else{
                cout<<".";
            }
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>>&v,int row,int col){
    int n=v.size();
    for(int i=0;i<n;i++){
        if(v[i][col]){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(v[i][j]){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(v[i][j]){
            return false;
        }
    }
    return true;
}

bool solveNQUtil(vector<vector<int>>&v,int row){
     int n=v.size();
     if(row>=n){
        return true;
     }

     for(int col=0;col<n;col++){
        if(isSafe(v,row,col)){
            v[row][col]=1;
        
            if(solveNQUtil(v,row+1)){
                return true;
            }
            v[row][col]=0;
        }
     }
     return false;
}

void solve( int n){
    vector<vector<int>>v(n,vector<int>(n,0));
    if(solveNQUtil(v,0)==false){
        cout<<"NO valid solution"<<endl;
    }
    print(v);
}
int main(){
    int n;
    cin>>n;
    solve(n);
}