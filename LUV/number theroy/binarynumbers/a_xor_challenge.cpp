// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int c;
    cin >> c;
    int bit_cnt = (int)log2(c) + 1;  // No. of bits used(i.e. No. of bits after MSB; MSB included)
  
    int a=0,b=0;
    vector<int> set_bits;
    for(int i=0;i<bit_cnt; ++i){
        if(c & (1<<i)){
            set_bits.push_back(i);
        }
        else{
            // Set ith bits in a & b for which ith bit in c is unset(because we want to maximize the numbers)
            a |= (1<<i);   
            b |= (1<<i);
        }
    }
    // for(int i=0;i<set_bits.size();++i){
    //     cout << set_bits[i] << " ";
    // }

    // Now we will check for all subset of set_bits(using bit masking)
    int sz = (1<<set_bits.size());  // No. of subsets (2^n)
 
    long long ans = -1;
    for(int mask=0;mask<sz;++mask){
        int a_copy = a,b_copy = b;
        for(int j=0;j<set_bits.size();++j){
            if(mask &(1<<j)){
                a_copy |= (1<<set_bits[j]);
            }
            else{
                b_copy |= (1<<set_bits[j]);
            }
        }
        ans = max(ans,a_copy*1LL*b_copy);
    } 
    cout << ans << endl;
}