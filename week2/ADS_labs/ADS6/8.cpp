#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int k;
    std::cin>>k;
    std::vector<char> vec(k);

    for(int i=0; i<k; i++){
        std::cin>>vec[i];
    }

    char target;
    std::cin>>target;
    std::sort(vec.begin(), vec.end());
    bool truth = true;
    for(int i=0; i<k; i++){
        if(vec[i] > target){
            std::cout<< vec[i]<<"\n";
            truth = false;
            break;
        }
    }
    if(truth){
        std::cout<<vec[0];
    }
}