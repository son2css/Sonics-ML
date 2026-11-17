#include <iostream>
#include <vector>

int main(){
    long long n, m;
    std::cin>>n>>m;
    std::vector<long long> a(n);
    std::vector<long long> pref(n);

    for(int i=0; i<n; i++){
        long long elem;
        std::cin>>elem;
        a[i]= elem;
        if(i==0){
            pref[i]= elem;
        }else{
            pref[i] = pref[i-1] + elem;
        }
    }


    while(m--){
        long long l = 0;
        long long r = n-1;
        int ans =-1;
        long long b;
        std::cin>>b;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(pref[mid] >=b){
                r= mid-1;
                ans = mid;
            }
            else{
                l =mid+1;
            }

        }
        std::cout<<ans+1<<"\n";
    }

}