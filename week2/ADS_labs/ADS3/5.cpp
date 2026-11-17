#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

bool is_cover(std::vector<long long>& a, int k, long long max){
    int count = 0;
    for(int i=0; i<a.size(); i++){
        if(a.at(i)<=max){
            count++;
        }
    }
    return count>=k;
}

int main(){
    int n, k;
    std::cin>>n>>k;
    std::vector<long long> a(n);

    for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        std::cin>>x1>> y1>> x2>> y2;

        a.at(i) = std::max(x2, y2);
    }

    std::sort(a.begin(), a.end());

    int l=0;
    int r= a.size() -1;
    int ans = r;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(is_cover(a, k, a[mid])){
            ans = mid;
            r = mid-1;
        }else{
            l= mid+1;
        }
    }

    std::cout<<a[ans]<<std::endl;
}