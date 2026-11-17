#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
const long long mod = 1000000007;

long long get_hash(std::string& s){
    int n = s.size();

    long long hash =0;
    long long pow = 1;
    for(int i=0; i<n; i++){
        hash = ((hash% mod) + ((s[i] - 47)* pow)%mod) % mod;
        pow= (pow*11) % mod; 
    }

    return hash;
}

int main(){
    int n;
    std::cin>>n;

    std::vector<std::string> lines(2*n);

    for(int i=0; i<2*n; i++){
        std::cin>>lines[i];
    }

    for(int i=0; i<2*n; i++){
        std::string h = std::to_string(get_hash(lines[i]));

        if(std::find(lines.begin(), lines.end(), h)!= lines.end()){
            std::cout<<"Hash of string "<<"\""<<lines[i]<<"\""<<" is "<<h<<"\n";
        }
    }

}