#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using ull = unsigned long long;
ull get_hash(std::string s){
    ull p = 29;
    ull p_pow = 1;
    ull h=0;

    for(int i=0; i<s.size(); i++){
        h+= s[i] * p_pow;
        p_pow*= p;
    }
    return h;
}

std::vector<ull> get_h(std::string s){
    std::vector<ull> h(s.size());
    ull n = s.size();

    h[0] = s[0];
    ull p = 29;
    ull p_pow = 29;
    for(int i=1; i<n; i++){
        h[i] = h[i-1]+  s[i]*p;
        p*=p_pow; 
    }
    return h;
}

std::vector<int> get_points(std::string s1, std::string target){
    int n = s1.size();
    int m = target.size();
    std::vector<int> ans;

    std::vector<ull> p(n);
    p[0] = 1;
    for(int i=1; i<n; i++){
        p[i] = p[i-1]*29;
    }
    
    ull targets_hash = get_hash(target);
    std::vector<ull> h = get_h(s1);

    for(int i=0; i<n-m+1; i++){
        int j= i + m -1;

        ull hash_at_j = h[j];

        if(i>0) hash_at_j = h[j] - h[i-1];

        if(hash_at_j == targets_hash* p[i]){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    std::string s1, s2, target;

    std::cin>>s1>>s2>>target;

    std::vector<int> ss1 = get_points(s1, target);
    std::vector<int> ss2= get_points(s2, target);

    int i=0; 
    int j =0;

    int n = ss1.size();
    int m = ss2.size();

    int count=0;

    while(i<n && j<m){
        if(ss1[i] == ss2[j]){
            count++;
            i++;
            j++;
        }
        else if(ss1[i] < ss2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    std::cout<<count;
    return 0;
}