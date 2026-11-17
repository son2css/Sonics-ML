#include <iostream>
#include <vector>

int merge(std::vector<int>& v, int l, int mid, int r){
    std::vector<int> L(v.begin()+l, v.begin()+mid+1);
    std::vector<int> R(v.begin()+mid+1, v.begin()+r+1);

    int count =0;

    int i=0;
    int j=0;
    int k =l;

    while(i<L.size() && j<R.size()){
        if(L[i]<= R[j]){
            v[k++] = L[i++];
        }
        else{
            v[k++] = R[j++];
            count+= (L.size() -i);
        }
    }

    while(i<L.size()){
        v[k++] = L[i++];
    }
    while(j < R.size()){
        v[k++] = R[j++];
    }

    return count;
}

int count(std::vector<int>& v, int l, int r){
    int cnt =0;
    if(l<r){
        int mid = l + (r-l)/2;

        cnt+= count(v, l, mid);
        cnt+= count(v, mid+1, r);

        cnt+= merge(v, l, mid, r);
    }
    return cnt;
}

int main(){
    int n;
    std::cin>>n;
    std::vector<int> v(n);
    for(int i=0; i<n; i++){
        std::cin>>v[i];
    }

    std::cout<<count(v, 0, v.size()-1);
}