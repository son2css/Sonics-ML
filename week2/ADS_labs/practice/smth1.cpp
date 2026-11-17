#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin>>n;

    std::vector<char> vec(n);
    for(int i=0; i<n; i++){
        std::cin>>vec[i];
    }

    char target;
    std::cin>>target;

    std::sort(vec.begin(), vec.end());
    bool tru = true;

    for(int i=0; i<n; i++){
        if(vec[i] > target){
            std::cout<<vec[i];
            tru = false;
            break;
        }
    }
    if(tru){
        std::cout<<vec[0];
    }
}