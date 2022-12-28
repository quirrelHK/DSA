/*
Consider this problem: There are N≤5000 workers. Each worker is available during some days of this month (which has 30 days). 
For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability. 
You need to assign an important project to two workers but they will be able to work on the project only when they are both available. 
Find two workers that are best for the job — maximize the number of days when both these workers are available.
*/
#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=32; i>=0;--i){
        cout << ((num >>  i) & 1);
    }
    cout << endl;
}
int main(){
    int n; // No. of workers
    cin >> n;
    vector<int> workers_mask(n,0);
    for(int i=0;i<n;++i){
        int days_available;
        cin >> days_available;
        int mask=0;
        for(int j=0;j<days_available;++j){
            int day;
            cin >> day;
            mask = (mask | (1<<day)); 
        }
        workers_mask[i] = mask;  // No. of days(which days)
    }

    // for(int i=0;i<n;++i){
    //     cout << workers_mask[i] << endl;
    //     printBinary(workers_mask[i]);
    // }

    // Choose days
    int max_days=0;
    int worker1=-1,worker2=-1;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            // intersection of workers[i] & worker[j]
            int intersection = (workers_mask[i] & workers_mask[j]); // O(1)
            int common_days = __builtin_popcount(intersection); // O(1)
            cout << i << " " << j << " " << common_days << endl;
            if(max_days < common_days){
                max_days = common_days;
                worker1 = i;
                worker2 = j;
            }
        }
    }

    cout << worker1 << " " << worker2 << " " <<"Max common days: " << max_days << endl;
} // O(N*2)