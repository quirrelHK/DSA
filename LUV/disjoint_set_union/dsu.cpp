// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/

/*
DSU is used when we want to make groups or set.
Like agglomerative clustering (when we perform union of two groups we are essentially making a single larger groups from the two groups)

In DSU operations are done in ALMOST CONSTANT TIME  
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int parent[N];
int size_group[N];


// Add new node; make a group 
void make(int a){   
    parent[a]=a;
    size_group[a]=1;
}


// Find the parent of a group
int find(int a){
    
    if(parent[a]==a) return a;

    // Path Compression- optimization all the nodes in the path will now directly point to the parent node
    return parent[a] = find(parent[a]);   // return the parent of current node 
}

void Union(int a, int b){
    a = find(a);  // Parent of group of a
    b = find(b); // Parent of group of b

    if(a!=b){   // If roots are not same
        
        // Union by size: optimization; we want to add smaller group to the larger group by size so that depth of tree does not increase
        if(size_group[a] < size_group[b]){
            swap(a,b);
        }
        parent[b]=a;
        size_group[a]+=size_group[b];
    }
}

int main(){

    int n,k; // n nodes; k edges or union
    cin >> n >> k;
    for(int i=1;i<=n;++i){
        make(i);
    }
    while(k--){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }

    int connected_component_cnt=0;  // basically no. of parents
    for(int i=1;i<=n;++i){
        if(i==find(i)) connected_component_cnt++;
    }

    cout << "No. of groups: " << connected_component_cnt << endl;

}