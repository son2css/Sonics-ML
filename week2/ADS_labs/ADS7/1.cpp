#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void merge(std::vector<std::string>& v, int l, int mid, int r){
    int n1 = mid- l +1;
    int n2 = r-mid;

    std::vector<std::string> L(n1), R(n2);

    for(int i=0; i<n1; i++){
        L[i] = v[l + i];
    }
    for(int i=0; i<n2; i++){
        R[i] = v[mid + i + 1];
    }

    int i=0;
    int j=0;
    int k = l;

    while(i<n1 && j<n2){
        if(L[i].size() <= R[j].size()){
            v[k++] = L[i++];
        }
        else{
            v[k++] = R[j++];
        }
    }
    while(i<n1){
        v[k++] = L[i++];
    }
    while(j<n2){
        v[k++] = R[j++];
    }
}

void merge_sort(std::vector<std::string>& v, int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;

        merge_sort(v, l, mid);
        merge_sort(v, mid+1, r);

        merge(v, l, mid, r);
    }
}

int main(){
    int n;
    std::cin>>n;

    std::cin.ignore();
    while(n--){
        std::vector<std::string> v;
        std::string s;

        std::getline(std::cin, s);

        std::stringstream ss(s);

        std::string word;

        while(ss>>word){
            v.push_back(word);
        }

        merge_sort(v, 0, v.size()-1);

        for(int i=0; i<v.size(); i++){
            std::cout<<v[i]<<(i+1==v.size()?"\n":" ");
        }
    }
}