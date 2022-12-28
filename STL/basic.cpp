#include<bits/stdc++.h>
using namespace std;


/* The insert funtion in vector is very costly even if we want to push at front because in vector a dynamic array
which adds up to the insertion time. But in list a doubly linked list is maintained so push_front operation is super cheap
*/

void explainPair(){

    // pair is inside the utility library
    pair<int, int> p = {1,4};

    cout << p.first << " " << p.second << endl;

    // Nested pair

    pair<int, pair<int, int>> p1= {3,{6,7}};
    cout << p1.first << " " << p1.second.second << endl;

    // array of pairs
    pair<int, int> arr[] = {{4,5},{-1,7},{8,9}};
    cout << arr[0].second << endl;
}


void explianVector(){

    // Unlike normal arrays size of vectors can be changed(dynamic in nature)
    vector<int> v;

    v.push_back(55);
    v.emplace_back(56);  // same as push_back(generally faster)

    cout << v[0];
    vector<pair<int, int>> vec;

    vec.push_back({1,2});
    vec.emplace_back(5,6);

    cout << "\n" << vec[0].first;

    vector<int> v(5,100);



    vector<int> v(5);  // depends upon compiler but usually garbage value

    vector<int> v1(5, 20);
    vector<int> v2(v2);  // copying container v2 into v1

    v = {1,2,3,4,5,6};
   
   
    // Iterator - here the data type of iterator is vector of integers
    vector<int>::iterator it = v.begin();  // iterator points to the memory address
    it++;
    cout << *(it) << endl; 

    it = it + 2;  // 
    cout << *(it) << endl;

    vector<int>::iterator it = v.end();  //  end will point to a memory lecation that is right after the last element(i.e. not the vector itself)
   
   /* vector<int>::iterator it = v.rend();  // 
    vector<int>::iterator it = v.rbegin();  */


    cout << v.back() << endl;

    // Looping thourgh a vector:
    // 1. use a for loop
    // 2. use a itrator

    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *(it) << " ";
    }
    cout << endl;
    for(auto it =v.begin(); it!= v.end(); it++){  // automatically assign a data type to the variale (here iterator is assigned)
        cout << *(it) << " ";
    }
    cout << endl;

    for(auto it : v){       // here not a iterator but rather of type int
        cout << it << " ";
    }


    // *******Deletion from a vector********

    //{10,20,30,40}
    v.erase(v.begin()+1); // removes 20

    //{10,20,30,40,50}
    v.erase(v.begin()+2,v.begin()+4); //{10,20,50} erase in a range last element not included


    // ***********Insert fucntion********

    vector<int>v(2,100);

    v.insert(v.begin(),300); // {300,100,100}
    v.insert(v.begin()+1,10); // {300, 10, 100, 100}

    //  Insert multiple elements
    // (begin, no. of elemets,the element to insert)
    v.insert(v.begin()+1,2,66);

    // insert a vector
    vector<int> copy = {11,22};
    v.insert(v.begin(),copy.begin(),copy.end());

    cout << v.size(); // no. of elements

    v.pop_back();

    // v1 -> {10,20}
    // v2 -> {30,40}
    v1.swap(v2);  // v1 -> {30,40}  v2 -> {10,20}

    v.clear(); // erases the entire vector

    cout << v.empty();  // true or false 

}


void explainList(){
    // Same as vector but allows front operations

    list<int> ls;

    ls.push_back(33);
    ls.emplace_back(55);

    ls.push_front(11); 
    ls.emplace_front(55);

}

void explainDeque(){
    // same as vector and list

    deque<int> dq;
    dq.push_back(2);
    dq.emplace_back(56);
    dq.push_front(11); 
    dq.emplace_front(55);

    dq.pop_back();
    dq.pop_front();

    // reference to the data at front or back
    dq.front();
    dq.back();
    
}

void explainStack(){

    // Every operation is O(1)
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(66);

    cout << st.top();  // peek at the top element

    st.pop();
    cout << st.top() << endl;
    cout << st.empty() << endl;

    stack<int> st1;
    st.swap(st1);
    cout << "kjlksd"

}

void explainQueue(){
    // All operation O(1)

    queue<int> q;
    q.push(5);
    q.push(6);
    q.emplace(7);

    q.back() +=10; // add 10 to the last element

    cout << q.back() << endl;

    cout << q.front() << endl;

    q.pop();  // deletes from front

    cout << q.front() << endl;

}

void explainPriorityQueue(){
    // The largest element stays at the top
    // inside a tree is maintained

    // push() annd pop() O(logn)
    // top() O(1)

    //****   MinHeap  ****
    priority_queue<int> pq;
    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(10);// {10,5,2}
    pq.emplace(8);// {10,8,5,2}

    cout << pq.top() << endl; // 10

    pq.pop(); // {8,5,2}

    cout << pq.top() << endl; // 8

    //****Store the minimum element at the top****//

    //********Minimum prioriy queue, aka MAX HEAP*********//

    priority_queue<int, vector<int>, greater<int>> pq;  // greater is a comparator
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(10);// {2,5,10}
    pq.emplace(8);// {2,5,8,10}

    cout << pq.top() << endl; // 2
}

void explainSet(){
    // Every thing is in sorted order and unique

    // Everything happens in O(logn)

    // NOT a linear structur inside a tree is maintained
    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(1);
    st.insert(5);
    st.insert(3);
    st.insert(5);



    // begin(), end(), rbegin(), rend(), size(),
    // empty() and swap() are same as above

    auto it = st.find(3);  // returns an iterators that points to the element

    auto it = st.find(6); // if not in set then returns st.end() (i.e. the location after the set)

    st.erase(5); // erases and maintains the sorted order - O(logn)

    auto it = st.find(2);
    st.erase(it);  // element at that memory location O(1)


    int cnt = st.count(1); // Will return either 1 or o (present or not present)

    //{1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // {1,4,5}

    // lower_bound() and upper_bound() function works the same way as it vector

    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);


}


void explainMulitSet(){
    // Same at set but also stores duplicate values, maintains sorted order

    multiset<int> ms;

    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    // ms.erase(1); // removes all 1's

    int cnt = ms.count(1);
    auto it = ms.find(1);
    cout << &it << endl;
    cout << &(*it) << endl;
    

    // Erase only single 1
    // ms.erase(ms.find(1)); // find will return itrator to the first occurence of 1
    
    ms.erase(it,&(*it+2));

    // Rest all functions are same
    for(auto it: ms){
        cout << it << " ";
    }


}

void explainUSet(){
   // Stores unique value and do not store in sorted order
   // lower_bound and upper_bound doesn't work

   // every operation take O(1)
   // In the worst case (generally doesn't happen) takes O(n)


}


void explainMap(){
    // Map stroes unique keys in a sorted order of keys
    // Works in O(logn)
    map<int, int> mpp;

    map<int, pair<int, int>> mpp1;  // key can be of any datatye

    map<pair<int, int>, int> mpp2;

    mpp[1] = 2;
    mpp.emplace(2,5);
    mpp2.insert({{4,5},77});

    mpp2[{6,5}] = 9;

    for(auto it : mpp){
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1] << endl; // prints the value
    cout << mpp[88] << endl; //prints null or 0

    auto it = mpp.find(3);  // address to the key and value pair
    cout << *(it).second;

    auto it = mpp.find(5); // points after the map
    auto it = mpp.lower_bound(2);
    auto it = mpp.lower_bound(3);
}


void explainMultiMap(){
    // Everything is the same, it allows duplicate keys
    // map[key] cannot be used

}

void explainUnorderedMap(){
    // same as unordered_set()
    // Values not sorted, does not allow duplicates

    // Generally works in O(1)
}


//********* Algorithm *******/

bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    
    // if they are same
    if(p1.first > p2.first) return true;
    return false;
}

void explainAlgorithm(){
    sort(a,a+n); // (straing iterator, endind iterator)
    sort(v.begin(), v.end());

    // sort a portion
    sort(a+2,s+4);

    // Sort in decreasing order
    sort(a, a+n, greater<int>);  // greater is a comparator

    // Sort in some other way

    pair<int, int> a[] = {{1,2},{2,1},{4,1}};

    // Sort it according to second element
    // if second element is same, then sort
    // it according to first element but in descending
    // i.e after sorting {{4,1},{2,1},{1,2}}

    // ********* Comparators *************
    sort(a, a+n, comp);  // comp is self written boolean comparator(it has to return a bool value)

    int num = 7;
    int cnt = __builtin_popcount(num);  // returns no. of 1's or set bits in 32-bit number

    long long num = 12365478965;
    int cnt = __builtin_popcountll(num);

    string s = "231";
    sort(s.begin(),s.end());

    do{
        cout << s << endl;
    }while(next_permutation(s.begin(), s.end())); // returns null if no more permutations are there

    int maxi = *max_element(a, a+n); // returns the address
}   

int main(){

    // explainPair();
    explainMulitSet();
    return 0;
}