#include <bits/stdc++.h>
using namespace std;
bool hasPath(vector<vector<int> > mat,vector<int> &visited, int s, int d,int v )
{
    if(mat[s][d]==1){
        return true;
    }
    visited[s]=1;
    bool ans=false;
    
    for(int i=0;i<v;i++){

        if(mat[s][i]){

            if(!visited[i]){
               ans=hasPath(mat,visited,i,d,v);

               if(ans)
               return true;
            }
        }
    }
    return false;
}
bool isPathDFS( vector<vector<int> > mat, int s, int d,int v)
{
    if (s == d)
        return true;

    vector<int> visited(v, 0);

    
    for(int i=0;i<v;i++){
        
            if(!visited[i]){
                if(hasPath(mat,visited,s,d,v))
                return true;
            }
        
    }
    return false;
}
int main()
{
    int v;
    cin>>v;
    vector<vector<int> > mat(v,vector<int> (v));
    for (int i = 0; i < v; i++)
    {
        for(int j=0;j<v;j++){
            cin>>mat[i][j];
        }
        
    }
    int src,dest;
    cin>>src>>dest;
    if (isPathDFS(mat,src,dest,v))
        cout << "Yes Path Exist" << endl;
    else
        cout << "No Such Path Exists" << endl;

    return 0;
}