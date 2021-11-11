#include<bits/stdc++.h>
using namespace std;

bool hasCycle(vector<vector<int> > mat,int sv,int visited[],int dfsVis[],int v){
    visited[sv]=1;
    dfsVis[sv]=1;
    for(int i=0;i<v;i++){

        if(mat[sv][i]){
            if(!visited[i]){

                bool cycle=hasCycle(mat,i,visited,dfsVis,v);

                if(cycle){
                    return true;
                }
                else if(dfsVis[i]){
                    return true;
                }
            }
        } 
    }
     dfsVis[sv]=0;
    return false;
}
bool isCyclic(vector<vector<int> > mat,int v){

    int visited[v],dfsVis[v];
    memset(visited,0,sizeof visited);
    memset(dfsVis,0,sizeof dfsVis);

    for(int i=0;i<v;i++){
        if(!visited[i]){
            bool ans=hasCycle(mat,i,visited,dfsVis,v);

            if(ans)
            return true;
        }
    }

    return false;

}
int main(){
    int v;
    cin>>v;
     vector<vector<int> > mat(v, vector<int>(v));

     for(int i=0;i<v;i++){
         for(int j=0;j<v;j++){
             cin>>mat[i][j];
         }
     }

     if(isCyclic(mat,v)){
         cout<<"Yes Cycle Exists"<<endl;
     }
     else{
          cout<<"No Cycle Exists"<<endl;
     }
}