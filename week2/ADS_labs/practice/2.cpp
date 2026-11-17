#include <iostream>
#include <vector>

long long bound(std::vector<long long>& a, long long l ){
    int left=0;
    int right = a.size() -1;
    int ans = 0;

    while(left<=right){
        int mid = left + (right - left)/2;

        if(a.at(mid)>=l){
            ans = mid;
            right = mid -1;
        }
        else{
            left = mid +1;
        }
    }
    return ans;
}
long long uppder_bound(std::vector<long long>& a, long long target){
    int l=0;
    int r = a.size() - 1;
    int ans =0;

    while(l<=r){
        int mid = l + (r-l)/2;

        if(a.at(mid) > target){
            ans = mid;
            r = mid -1;
        }
        else{
            l = mid +1;
        }
    }
}

long long find_range(std::vector<long long>& a, long long l, long long r){
    if(l>r) return 0;

    return (uppder_bound(a, r) - bound(a, l));
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, q;
    std::cin>>n>>q;

    std::vector<long long> vec(n);

    for(int i =0; i<n; i++){
        std::cin>>vec.at(i);
    }

    std::sort(vec.begin(), vec.end());

    while(q--){
        int l1, r1, l2, r2;

        std::cin>>l1>>r1>>l2>>r2;

        if(l1>r1) std::swap(l1, r1);
        if(l2>r2) std::swap(l2, r2);

        if(std::max(l1, l2) <= std::min(r1, r2)){
            int L = std::min(l1, l2);
            int R = std::max(r1, r2);

            std::cout<<find_range(vec, L, R)<<"\n";
        }
        else{
            std::cout<<find_range(vec, l1, r1) + find_range(vec, l2, r2)<<"\n";
        }
    }
}