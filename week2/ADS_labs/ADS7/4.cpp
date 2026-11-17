#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin>>n;

    std::vector<int> v(n);
    for(int i=0; i<n; i++){
        std::cin>>v[i];
    }

    if(v[0] > 0){
        for(int i=0; i<n; i++){
            std::cout<<v[i]*v[i]<<" ";
        }
        return 0;
    }

    std::vector<int> ans(v.size());
    int i=0;
    int j= v.size()-1;
    int k = v.size()-1;
    while(i<=j){
        if(v[i]*v[i]>=v[j]*v[j]){
            ans[k--] = v[i]*v[i];
            i++;
        }
        else{
            ans[k--] = v[j]*v[j];
            j--;
        }
    }
    for(int i=0; i<v.size(); i++){
        std::cout<<ans[i]<<" ";
    }
}