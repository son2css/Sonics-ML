#include <iostream>
#include <vector>

void merge(std::vector<int>& v, std::vector<int>& L, std::vector<int>& R){
    int n1= L.size();
    int n2 = R.size();

    int i=0;
    int j=0;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            v.push_back(L[i++]);
        }
        else{
            v.push_back(R[j++]);
        }
    }

    while(i<n1){
        v.push_back(L[i++]);
    }
    while(j<n2){
        v.push_back(R[j++]);
    }
}

int main(){
    int n;
    std::cin>>n;
    std::vector<int> L(n);
    for(int i=0; i<n; i++){
        std::cin>>L[i];
    }

    int m;
    std::cin>>m;
    std::vector<int> R(m);
    for(int i=0; i<m; i++){
        std::cin>>R[i];
    }
    std::vector<int> v;

    merge(v, L, R);

    for(int i=0; i<v.size(); i++){
        std::cout<<v[i]<<" ";
    }

}