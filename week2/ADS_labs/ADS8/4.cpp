#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using ll = long long;
using ull = unsigned long long;

int main(){
    ll MOD1 = 1000000007;
    ll MOD2 = 9239429349;
    std::string s;
    std::cin>>s;

    if(s.size() == 0){
        std::cout<<0;
        return 0;
    }

    std::vector<ll> p1(s.size());
    std::vector<ll> p2(s.size());

    std::vector<ll> h1(s.size());
    std::vector<ll> h2(s.size());

    p1[0] = p2[0] = 1;

    for(int i=1; i<s.size(); i++){
        p1[i] = p1[i-1]*31 % MOD1;
        p2[i] = p2[i-1]*31 % MOD2;
    }

    h1[0]= h2[0] = s[0];

    for(int i=1; i<s.size(); i++){
        h1[i] = (h1[i-1] + s[i]*p1[i])%MOD1;
        h2[i] = (h2[i-1] + s[i]*p2[i])%MOD2;
    }

    std::vector<ull> ans;

    for(int i=0; i<s.size(); i++){
        for(int j=i; j<s.size(); j++){
            ll a = h1[j], b = h2[j];

            if(i>0){
                a = (a - h1[i-1] + MOD1)%MOD1;
                b = (b - h2[i-1] + MOD2)%MOD2;
            }

            a = a* p1[s.size() - 1 - i]% MOD1;
            b = b* p2[s.size() - 1 - i]%MOD2;

            ans.push_back(ull(a)<<32|b);
        }
    }

    std::sort(ans.begin(), ans.end());
    std::cout<<std::unique(ans.begin(), ans.end()) - ans.begin();
    return 0;
}