#include <iostream>
#include <vector>

int main(){
    int n, q;
    std::cin>>n>>q;
    
    std::vector<int> Nums(n);

    for(int i=0; i<n; i++){
        std::cin>>Nums.at(i);
    }

    for(int i=0; i<q; i++){
        int l1, r1, l2, r2;
        std::cin>>l1>>r1>>l2>>r2;
        int count =0;

        for(int j=0; j<Nums.size(); j++){
            if((Nums.at(j)>=l1 && Nums.at(j)<=r1) || (Nums.at(j)>=l2 && Nums.at(j)<=r2)){
                count++;
            }
        }
        std::cout<<count<<std::endl;

    }
}