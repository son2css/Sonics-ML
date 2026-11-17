#include <iostream>
#include <vector>
#include <algorithm>
int sum(std::vector<long long>& a, long long pos ){
    long long sum =0;
    for(int i=0; i<=pos; i++){
        sum+=a.at(i);
    }
    return sum;
}

int main(){
    long long total, rounds;
    std::cin>>total;
    std::vector<long long> strengths(total);

    for(int i=0; i<total; i++){
        std::cin>>strengths.at(i);
    }
    std::cin>>rounds;
    std::sort(strengths.begin(), strengths.end());

    while(rounds--){
        int power;
        std::cin>>power;

        long long l=0;
        long long r = strengths.size()-1;
        long long ans = -1;

        while(l<=r){
            long long mid = l + (r-l)/2;

            if(strengths[mid]<=power){
                ans = mid;
                l = mid+1;
            }else{
                r= mid-1;
            }
        }
        if(ans == -1){
            std::cout<<"0 0"<<"\n";
        }
        else{
            std::cout<<ans+1<<" "<<sum(strengths, ans)<<"\n";
        }
    }
}