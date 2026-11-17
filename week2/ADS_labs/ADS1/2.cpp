#include <iostream>
#include <cmath>

long long bin_exp(long long a, long long n, long long m){
    if(n==0) return 1%m;

    if(n%2==0){
        return ((bin_exp(a, n/2, m)%m) * (bin_exp(a, n/2, m)%m))%m;
    }
    else{
        return (a%m * (bin_exp(a, n-1, m)%m))%m;
    }
}

int main(){
    long long a, n, m;

    std::cin>>a>>n>>m;

    std::cout<<bin_exp(a, n, m);
}