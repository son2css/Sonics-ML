#include <iostream>
#include <vector>
int main(){
    int n, k;
    std::cin>>n>>k;

    std::vector<int> v(1);

    for(int t = 1; t<n+1; t++){
        int el;
        std::cin>>el;
        v.push_back(el);

        int i =t;
        while(i>1 && v[i/2] > v[i]){
            std::swap(v[i], v[i/2]);
            i = i/2;
        }
    }

    while(k--){
        std::cout<<v[1]<<(k==0?"\n": " ");

        std::swap(v[1], v[v.size()-1]);

        v.pop_back();
        int i=1;

        while(i*2<v.size()){
            int c= i*2;

            if(c+1<v.size() && v[c+1]<v[c]){
                c= c+1;
            }

            if(v[i] > v[c]){
                std::swap(v[i], v[c]);
                i =c;
            }
            else{
                break;
            }
        }
    }

    for(int i=1; i<(int)v.size(); i++){
        std::cout<<v[i]<<" ";
    }
}