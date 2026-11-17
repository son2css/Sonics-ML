#include <iostream>
#include <algorithm>
#include <vector>
long long total_flights(std::vector<long long>& a, long long num){
    if(num ==0) return 1e18;
    long long total=0;
    for(int i=0; i<a.size(); i++){
        total+=(a[i] + num-1)/num;
    }
    return total;
}

int main(){
    int n, f;
    std::cin>>n>>f;

    std::vector<long long> islands(n);

    for(int i=0; i<n; i++){
        std::cin>>islands[i];
    }

    std::sort(islands.begin(), islands.end());

    int l=1;
    int r=islands[n-1];
    int ans = r;

    while(l<=r){
        int mid = l + (r-l)/2;

        if(total_flights(islands, mid)<=f){
            r = mid-1;
            ans = mid;
        }
        else{
            l = mid+1;
        }
    }
    std::cout<<ans;

}