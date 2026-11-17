#include <vector>
#include <iostream>
#include <cmath>

int main(){
    long long n;
    std::cin>>n;
    std::vector<long long> v;


    long long num =2;

    while(num*num <= n){
        if(n%num == 0){
            v.push_back(num);
            n/=num;
            continue;
        }
        else{
            num++;
        }
    }

    if(n>1) v.push_back(n);

    for(int i=0; i<v.size(); i++){
        std::cout<<v[i]<<(i+1==v.size()?"": " ");
    }
}