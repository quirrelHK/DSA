#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
// #include<iostream>
// using namespace std;


int main(){
    int p;
    p = fork();
    if(p == 0){
        fork();
        // cout << "Hello\n";
        printf("Hello\n");
    }
    else{
        fork();
        // cout << "Hello\n";
        printf("Hello\n");

    }
}