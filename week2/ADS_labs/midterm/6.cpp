#include <iostream>
#include <vector>
#include <algorithm>
void Merge(std::vector<int>& v, int l, int r, int mid){
    int n = mid - l + 1;
    int m = r - mid;
    std::vector<int> L(n);
    std::vector<int> R(m);

    for(int i=0; i<n; i++){
        L[i] = v[l + i];
    }
    for(int j= 0; j<m; j++){
        R[j] = v[mid+1+j];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n && j<m){
        if(L[i]<=R[j]){
            v[k++] = L[i++];
        }
        else{
            v[k++]= R[j++];
        }
    }
    while(i<n){
        v[k++] = L[i++];
    }
    while(j<m){
        v[k++] = R[j++];
    }
}

void mergesort(std::vector<int>& v, int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;

        mergesort(v, l, mid);
        mergesort(v, mid+1, r);

        Merge(v, l, r, mid);
    }
}

int main(){
    return 0;
}