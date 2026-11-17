#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <iomanip>
#include <algorithm>
int main(){
    int n;
    std::cin>>n;
    std::vector<std::tuple<int, int, int>> ans;

    while(n--){
        std::string s;
        std::cin>>s;

        int day = std::stoi(s.substr(0, 2));
        int month = std::stoi(s.substr(3, 2));
        int year = std::stoi(s.substr(6, 4));

        ans.emplace_back(year, month, day);
    }
    std::sort(ans.begin(), ans.end());

    for(const auto& [year, month, day] : ans){
        std::cout<<std::setfill('0')<<std::setw(2)<<day<<"-"<<std::setw(2)<<month<<"-"<<std::setw(4)<<year<<"\n";
    }
}