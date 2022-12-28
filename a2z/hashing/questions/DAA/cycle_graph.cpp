// #include<bits/stdc++.h>
// using namespace std;
// set<int>white;//white container
// set<int>grey;//grey container
// set<int>black;//black container
// int flag=0;
// void addEdge(vector<int>adj[],int u,int v){
//   adj[u].push_back(v);
// }
// //function to detect the cycle in graph
// void CycleDetect(int u,vector<int>adj[]){
//     white.erase(u);//remove from the white set
//     grey.insert(u);//put into the grey set
//     for(int i=0;i<adj[u].size();i++){
//       if(white.find(adj[u][i])!=white.end())
//       {
//       CycleDetect(adj[u][i],adj);
//         }
//       if(grey.find(adj[u][i])!=grey.end()){ //check if its is present or not in grey set
//         flag=1;
//       }
//     }
//     black.insert(u);//put into the black set
//     grey.erase(u);//remove from the grey set
// }
// int main(){
//   vector<int>adj[5];//vector of array to store the graph
  
//   addEdge(adj, 0, 1);
//   addEdge(adj, 1, 2);
//   addEdge(adj, 1, 5);
//   addEdge(adj, 2, 3);
//   addEdge(adj, 3, 4);
//   addEdge(adj, 4, 0);
//   addEdge(adj, 4, 1);
//   for(int i=0;i<5;i++){
//     white.insert(i);
//   }
//   CycleDetect(0,adj);
//   if(flag==0)cout<<"Graph does not contain cycle"<<endl;
//   else
//   cout<<"Graph contain cycle"<<endl;
//   return 0;
// }


#include<bits/stdc++.h>
using namespace std;

set<int> white;
set<int> grey;
set<int> black;
int flag = 0;

void addE(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void detectCycle(vector<int> adj[], int u){
    white.erase(u);
    grey.insert(u);

    for(int i = 0; i < adj[u].size();++i){
        if(white.find(adj[u][i]) != white.end()){
            detectCycle(adj,adj[u][i]);
        }

        else if(grey.find(adj[u][i]) != grey.end()){
            flag = 1;
        }
    }
    black.insert(u);
    grey.erase(u);

}

int main(){
    int n;
    // cin >> n;
    // int u,v;
    vector<int> adj[5];
    // for(int i = 0; i < n; ++i){
    //     cin >> u >> v;
    //     addE(adj,u,v);
    // }
      addE(adj, 0, 1);
addE(adj, 1, 2);
  addE(adj, 1, 5);
  addE(adj, 2, 3);
  addE(adj, 3, 2);
  addE(adj, 3, 4);
  addE(adj, 4, 0);
  addE(adj, 4, 1);
  for(int i = 0;i < 5; ++i){
    white.insert(i);
  }



    detectCycle(adj,0);
    if(flag == 1)
        cout << "Yes";
    else
    cout << "no";
    return 0;
}