// Comparator function defines the behaviour of swapping
// We are not doing any changes in the sorting algorithm itself, just how the swapping is done
#include<bits/stdc++.h>
using namespace std;

bool should_i_swap(int a, int b){
    if(a < b) return true;
    return false;
}

bool should_i_swap(pair<int, int> a, pair<int,int> b){
    // first increasing order of first, if equal then decreasing order of second
    if(a.first != b.first){
        if(a.first > b.first) return true;
        return false;
    }
    else{
        if(a.second < b.second) return true;
        return false;
    }
}
bool cmp(pair<int, int> a, pair<int,int> b){
    // first increasing order of first, if equal then decreasing order of second
    // if(a.first != b.first){
    //     if(a.first > b.first) return false;
    //     return true;
    // }
    // else{
    //     if(a.second < b.second) return false;
    //     return true;
    // }

    // Easier way to remember; just return the order in which you want to sort
    if(a.first!=b.first){
        return a.first < b.first;     // swaps if a.first > b.first
    }
    else{
        return a.second > b.second;
    }
}

int main(){
    int n;
    cin >> n;
    // vector<int> v(n);
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i].first;
        cin >> v[i].second;

    }

    // ***********basic sorting algo**********
    // for(int i=0;i<n;++i){
    //     for(int j=i+1;j<n;++j){
    //         // if(v[i] > v[j]){
    //         //     swap(v[i],v[j]);
    //         // }
    //         if(should_i_swap(v[i],v[j])){  // comparator(decreasing)- the order of sorting depends upon how swapping is done
    //             swap(v[i],v[j]);
    //         }
    //     }
    // }

    /*
     comparotor of inbuilt sorting works in the opposite way
     if you want to swap return false
     if you don't want to swap return true
    */
    sort(v.begin(),v.end(),cmp);  
    


    for(int i=0;i<n;++i){
        cout <<  v[i].first <<" " << v[i].second << endl;
    }
}