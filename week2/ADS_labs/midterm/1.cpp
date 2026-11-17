#include <iostream>
#include <vector>

void merge(std::vector<int>& v, std::vector<int>& v1, std::vector<int>& v2){
    int i=0;
    int j =0;
    int k =0;

    while(i<v1.size() && j<v2.size()){
        if(v1[i]<= v2[j]){
            v[k++] = v1[i++];
        }
        else{
            v[k++]= v2[j++];
        }
    }

    if(i<v1.size()){
        v[k++] = v1[i++];
    }
    if(j<v2.size()){
        v[k++] = v2[j++];
    }
}

int main(){
    int n, m;
    std::cin>>n;
    std::vector<int> v(n);

    for(int i=0; i<n; i++){
        std::cin>>v[i];
    }
    std::cin>>m;
    
    std::vector<int> v1(m);
    for(int i=0; i<m; i++){
        std::cin>>v1[i];
    }

    std::vector<int> v_or(m+n);

    merge(v_or, v, v1);

    for(int i=0; i<v_or.size(); i++){
        std::cout<<v_or[i]<<" ";
    }

}