#include <iostream>
#include <string>
#include <vector>
using ll = long long;

int main(){
    int n;
    std::cin>>n;
    std::vector<ll> vec(n);

    for(int i=0; i<n; i++){
        std::cin>>vec[i];
    }
    ll prev = 0;
    ll pow = 1;

    std::string s="";
    for(int i=0; i<n; i++){
        ll curr = vec[i] - prev;
        prev = vec[i];

        ll c =curr/(pow);
        pow*= 2;

        s+=('a' + c);
    }

    std::cout<<s<<"\n";
}