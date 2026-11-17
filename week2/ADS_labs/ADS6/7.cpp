#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

int main(){
    int n;
    std::cin>>n;
    std::unordered_map<std::string, std::string> umap;
    std::map<std::string, std::string> map;

    std::string og;
    std::string copy;
    while(n--){
        std::cin>>og>>copy;
        umap[copy] = og;

        if(umap.find(og)!=umap.end()){
            og = umap[og];
        }
        map[og] = copy;

    }
    std::cout<<map.size()<<"\n";
    for(auto it: map){
        std::cout<<it.first<<" "<<it.second<<"\n";
    }
    return 0;
}