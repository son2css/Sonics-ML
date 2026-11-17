#include <iostream>
#include <string>
#include <algorithm>

bool is_vowel(char a){
    std::string s = "aeiou";

    return s.find(a)!=std::string::npos;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string vowel="";
    std::string other="";

    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;

    for(int i=0; i<n; i++){
        if(is_vowel(s[i])){
            vowel.push_back(s[i]);
        }
        else{
            other.push_back(s[i]);
        }
    }
    std::sort(vowel.begin(), vowel.end());
    std::sort(other.begin(), other.end());

    std::cout<<vowel+other<<"/n";
}