#include <iostream>

long long gcd(long long a, long long b){
    if(b==0) return a;

    return gcd(b, a%b);
}

int main(){
    long long n, m;
    std::cin>>n>>m;

    std::cout<<gcd(n, m);
}