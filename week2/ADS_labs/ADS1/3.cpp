#include <iostream>
#include <cmath>

int main(){
    int n;
    std::cin>>n;

    bool is_prime= true;

    if(n==1){
        is_prime = false;
    }

    for(int i=std::sqrt(n); i>1; i--){
        if(n%i==0){
            is_prime = false;
            break;
        }
    }
    if(is_prime){
        std::cout<<"YES";
    }
    else{
        std::cout<<"NO";
    }
}