#include <iostream>
#include <deque>

int main(){
    int n;
    std::cin>>n;
    
    while(n--){
        int size;
        std::cin>>size;
        int target;
        std::cin>>target;
        
        std::deque<int> v;
        int sum = 0;
        int max_size = -1;
        
        for(int i=0; i<size; i++){
            int el;
            std::cin>>el;
            v.push_back(el);
            sum+=v.back();
            
            while(sum>target){
                sum-=v.front();
                v.pop_front();
            }
            if(max_size<(int)v.size()){
                max_size = v.size();
            }
        }
        if(sum!=target){
            std::cout<<"-1"<<"\n";
        }
        else{
            std::cout<<size - max_size<<"\n";
        }
        
    }
}