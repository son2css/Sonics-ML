#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using ull = unsigned long long;

int main(){
    std::string s;
    std::cin>>s;

    int n = s.size();

    std::vector<ull> p(n);
    p[0] = 1;

    for(int i=1; i<n; i++){
        p[i] = p[i-1]*29;
    }

    std::vector<ull> h(n);

    h[0] = s[0];
    for(int i=1; i<n; i++){
        h[i] = h[i-1] + s[i]*p[i];
    }

    int q;
    std::cin>>q;

    while(q--){
        int l, r;
        int count =0;
        std::cin>>l>>r;
        l--; r--;

        ull target = h[r];
        if(l>0){
            target = h[r] - h[l-1];
        }
        for(int i=0; i<n-(r-l); i++){
            int len = (r-l) + 1;

            ull curr = h[i + len -1];

            if(i>0) curr -=h[i-1];

            if(target*p[i] == curr*p[l]){
                count++;
            }
        }
        std::cout<<count<<"\n";
    }
    return 0;
}