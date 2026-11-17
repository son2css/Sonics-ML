#include <iostream>
#include <vector>
#include <string>

int main(){
    int n;
    std::cin>>n;
    std::vector<std::string> stack;
    std::string s;

    for(int i=0; i<n; i++){
        std::cin>>s;

        if(stack.empty() || stack.back() != s){
            stack.push_back(s);
        }
    }

    std::cout<<stack.size()<<std::endl;
    for(int i=0; i<stack.size(); i++){
        std::cout<<stack.at(i)<<(i+1==stack.size()?"":" ");
    }
}