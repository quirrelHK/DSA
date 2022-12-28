/*
Monk is a multi-talented person, and prepares results for his college in his free time. (Yes, he is still in love with his old college!) He gets a list of students with their marks. The maximum marks which can be obtained in the exam is 100.

The Monk is supposed to arrange the list in such a manner that the list is sorted in decreasing order of marks. And if two students have the same marks, they should be arranged in lexicographical manner.

Help Monk prepare the same!

Input format:
On the first line of the standard input, there is an integer N, denoting the number of students. N lines follow, which contain a string and an integer, denoting the name of the student and his marks.

Output format:
You must print the required list.

Constraints:
1 <= N <= 105
1 <= | Length of the name | <= 100
1 <= Marks <= 100
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    map<int, multiset<string>> m;  // first in sorted order of marks, then in sorted order of names(we can have same names)
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        int marks;
        string name;
        cin >> name >> marks;
        m[-1*marks].insert(name);   // multiplying by -1 will place -100,-99.... first
    }
    // auto cur_it = --m.end(); // iterator to last element
    // while(true){
    //     auto &students = (*cur_it).second;
    //     int marks = (*cur_it).first;
    //     for(auto &student:students){
    //         cout << student << " " << marks << endl;
    //     }
    //     if(cur_it == m.begin()){
    //         break;
    //     }
    //     cur_it--;
    // }

    for(auto &marks_students_pr: m){
        auto &students = marks_students_pr.second;
        int marks = marks_students_pr.first;
        for(auto student: students){
            cout << student << " " << -1*marks << endl;
        }
    }
}