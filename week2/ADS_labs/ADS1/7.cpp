#include <iostream>
#include <string>
#include <stack>

int main(){
    std::string s;
    std::stack<char> stack;

    std::cin>>s;

    for(char c: s){
        if(stack.empty()){
            stack.push(c);
            continue;
        }

        if(c == stack.top()){
            stack.pop();
            continue;
        }

        stack.push(c);
    }

    if(stack.empty()){
        std::cout<<"YES";
    }
    else{
        std::cout<<"NO";
    }
}