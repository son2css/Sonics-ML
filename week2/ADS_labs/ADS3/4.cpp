#include <iostream>
#include <vector>
#include <algorithm>

int lower_bound(std::vector<long long>& a, long long target){
    int l=0;
    int r = a.size()-1;
    int ans = a.size();

    while(l<=r){
        int mid = l + (r-l)/2;

        if(a.at(mid) >= target){
            ans = mid;
            r = mid -1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}

int upper_bound(std::vector<long long>& a, long long target){
    int l=0;
    int r = a.size()-1;
    int ans = a.size();

    while(l<=r){
        int mid = l + (r-l)/2;
        if(a.at(mid)>target){
            r = mid -1;
            ans= mid;
        }
        else{
            l= mid+1;
        }
    }
    return ans;
}

int count(std::vector<long long>& a, long long l, long long r){
    if(l>r) return 0;
    return upper_bound(a, r) - lower_bound(a, l);
}

int main(){
    long long n;
    long long q;

    std::cin>>n>>q;

    std::vector<long long> vec(n);

    for(int i=0; i<n; i++){
        std::cin>>vec.at(i);
    }
    
    std::sort(vec.begin(), vec.end());

    while(q--){
        long long l1, r1, l2, r2;
        std::cin>>l1>>r1>>l2>>r2;

        if(std::max(l1, l2) <= std::min(r1, r2)){
            long long L = std::min(l1, l2);
            long long R = std::max(r1, r2);
            std::cout<<count(vec, L, R)<<"\n";
        }
        else{
            std::cout<<count(vec, l1, r1) + count(vec, l2, r2)<<"\n";
        }
    }

}