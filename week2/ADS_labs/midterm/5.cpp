#include <iostream>
#include <vector>
void bs1(std::vector<int>& v, int l, int r, int target){
    int ans =-1;
    int mid = 0;
    while(l<=r){
        mid = l + (r-l)/2;

        if(v[mid]>=target){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if(v[mid] == target){
        std::cout<<ans<<" ";
    }
}
void bs2(std::vector<int>& v, int l, int r, int target){
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2;

        if(v[mid]>target){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    std::cout<<ans-1;
}
int main(){
    int n;
    std::cin>>n;

    std::vector<int> v(n);
    for(int i=0; i<n; i++){
        std::cin>>v[i];
    }
    int k;
    std::cin>>k;

    bs1(v, 0, v.size()-1,k);
    bs2(v, 0, v.size()-1,k);
}
