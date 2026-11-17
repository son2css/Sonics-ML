#include <iostream>
#include <vector>

int find(std::vector<long long>& a, int target){
    int left =0;
    int right = a.size()- 1;
    int ans = a.size();

    while(left<=right){
        int mid = left + (right-left)/2;

        if(a.at(mid) >= target){
            ans = mid;
            right = mid - 1;
        }
        else{
            left= mid +1;
        }
    }
    return ans;
}