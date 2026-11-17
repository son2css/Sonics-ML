#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <iomanip>
#include <algorithm>

int main(){
    int n;
    std::cin>>n;
    std::vector<std::tuple<int, int ,int>> a(n);
    for(int i=0; i<n; i++){
        std::string date;
        int day = std::stoi(date.substr(0, 2));
        int month = std::stoi(date.substr(3, 2));
        int year = std::stoi(date.substr(6,4));

        a.emplace_back(year, month, day);
    }
    std::sort(a.begin(), a.end());
    for(const auto& [year, month, day] : a){
        std::cout<<std::setfill('0')<<std::setw(2)<<day<<"-"<<std::setw(2)<<month<<"-"<<std::setw(4)<<year<<"\n";
    }
}