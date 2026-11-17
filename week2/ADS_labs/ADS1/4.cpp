#include <iostream>
#include <cmath>

int main(){
    int n;
    std::cin>>n;

    int num =2;
    int i=0;

    while(i<n){
        bool is_prime = true;
        for(int j = std::sqrt(num); j>1; j--){
            if(num%j == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            i++;
        }
        if(i!=n) num++;
    }

    std::cout<<num;
}