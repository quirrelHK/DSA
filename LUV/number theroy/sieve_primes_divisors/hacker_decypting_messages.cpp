// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/


#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int arr[N];
int hp[N];
int canRemove[N];   // canReomve[i] -> if i can we removed from the array then 1 else 0
int hsh[N];
vector<int> distinct_prime_factors(int x){
    vector<int> factors;
    while(x>1){
        int factor = hp[x];
        while(x%factor==0){
            x /= factor;
        }
        factors.push_back(factor);
    }
    return factors;
}

int main()
{   
    for(int i=2;i<N;++i){
        if(hp[i]==0){   // If hp is zero, then it is a prime because it has not been marked by any other number
            for(int j=i;j<N;j+=i){
                hp[j]=i;
            }
        }
    }

    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        hsh[x]=1;   // All the number present in the array will be marked
    }

    for(int i=2;i<N;++i){
        if(hsh[i]){
            for(long long j=i;j<N; j *=i){
                canRemove[j] = 1;         // Also mark all the powers of the number present in the array
            }
        }
    }
 
    while(q--){
        int x;
        cin >> x;
        
        vector<int> prime_factors = distinct_prime_factors(x);
        bool isPossible = false;
        for(int i=0;i<prime_factors.size();++i){
            for(int j=i;j<prime_factors.size();++j){
                int product = prime_factors[i]*prime_factors[j];
                if(i==j && x%product != 0) continue; 
                /* We are not stroing the count of PFs. So, when i == j we do not know if there are actually more than one PFs when both indices are same or not
                   If both are same and the product of same is not able to divide the original nubmer then this means there is only one PF when for i == j 
                   Ex: 60: 2*2*3*5
                       30: 2*3*5     
                */ 

                int toRemove = x/product;
                /*
                    If toRemove is a power of a number present in the array then we can reomve it i.e. if 3 is present in array and toRemove is 27 then we can remove 27 by repeatedly dividing it by 3
                    If toRemove comes out to be one then only two PFs are present 
                */
                if(canRemove[toRemove]==1 || toRemove == 1){
                    isPossible = true;
                    break;
                }
            }
            if(isPossible) break;
        }

        cout << (isPossible?"YES\n":"NO\n");
    }
    return 0;
}