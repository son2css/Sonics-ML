#include <iostream>
#include <vector>

bool can_split(std::vector<long long> &a, int n, int k, long long max){
    int block = 1;
    long long curr_sum = 0;

    for(int i=0; i<n; i++){
        if(curr_sum + a[i] <= max){
            curr_sum+=a[i];
        }
        else{
            block++;
            curr_sum=a[i];
        }
    }

    return block<=k;
}

int main(){
    int n, k;
    std::cin>>n>>k;

    std::vector<long long> ghouls(n);

    long long l = 0;
    long long total= 0;

    for(int i=0; i<n; i++){
        std::cin>>ghouls.at(i);
        if(ghouls.at(i) > l) l =ghouls.at(i);
        total +=ghouls.at(i);
    }

    long long r = total;
    long long ans;

    while(l<=r){
        long long mid = l + (r-l)/2;

        if(can_split(ghouls, n, k, mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }

    }
    std::cout<<ans<<std::endl;

}