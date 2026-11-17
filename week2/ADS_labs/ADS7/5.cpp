#include <iostream>
#include <vector>

void merge(std::vector<std::pair<int, std::vector<int>>>& v, int l, int mid, int r){
    std::vector<std::pair<int, std::vector<int>>> L(v.begin()+l, v.begin()+mid+1);
    std::vector<std::pair<int, std::vector<int>>> R(v.begin()+mid+1, v.begin()+r+1);

    int i=0;
    int j =0;
    int k=l;

    int n1= L.size();
    int n2 = R.size();

    while(i<n1 && j<n2){
        if(L[i].first > R[j].first){
            v[k++] = L[i++];
        }
        else if(L[i].first < R[j].first){
            v[k++] = R[j++];
        }
        else{
            if(L[i].second<= R[j].second){
                v[k++] = L[i++];
            }
            else{
                v[k++] = R[j++];
            }
        }
    }

    while(i<n1){
        v[k++] = L[i++];
    }
    while(j<n2){
        v[k++] = R[j++];
    }
}

void merge_sort(std::vector<std::pair<int, std::vector<int>>>& v, int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;

        merge_sort(v, l, mid);
        merge_sort(v, mid+1, r);

        merge(v, l, mid, r);
    }
}

int main(){
    int n, m;
    std::cin>>n>>m;

    std::vector<std::pair<int, std::vector<int>>> v;

    while(n--){
        int el;
        int sum =0;
        std::vector<int> temp(m);
        for(int i=0; i<m; i++){
            std::cin>>temp[i];
            sum+=temp[i];
        }

        v.push_back({sum, temp});
    }
    
    merge_sort(v, 0, v.size()-1);

    for(auto it: v){
        for(int i=0; i<it.second.size(); i++){
            std::cout<<it.second[i]<<" ";
        }
        std::cout<<"\n";
    }
}