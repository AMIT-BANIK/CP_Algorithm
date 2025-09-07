#include<bits/stdc++.h>
using namespace std;

int V;
int solution=0;
void print(vector<int>&color){

    for(int i=0;i<V;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl;

}

bool issafe(int v,vector<vector<int>>&graph,vector<int>&color,int c){
    for(int i=0;i<V;i++){
        if(graph[v][i] && color[i]==c){
            return false;
        }
    }
    return true;
}

void graphColoringUtil(vector<vector<int>>&graph,int m,vector<int>&color,int v){
    if(V==v){
        solution++;
        print(color);
        return;
    }

    for(int c=1;c<=m;c++){
        if(issafe(v,graph,color,c)){
            color[v]=c;

            graphColoringUtil(graph,m,color,v+1);
            color[v]=0;
        }

    }
}
   

void graphColoring(vector<vector<int>> &graph, int m) {
    vector<int> color(V, 0);
    graphColoringUtil(graph, m, color, 0);

    if (solution == 0) {
        cout << "NO valid solution exist" << endl;
    } else {
        cout << "Total solutions: " << solution << endl;
    }
}


int main(){
    int m,e;
    cin>>V>>m>>e;
    vector<vector<int>>graph(V,vector<int>(V,0));
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;

    }
     graphColoring(graph,m);

}
echo "# CP_ALGORITHM" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/AMIT-BANIK/CP_ALGORITHM.git
git push -u origin main