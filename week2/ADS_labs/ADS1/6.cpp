#include <iostream>
#include <stack>
#include <string>

int main(){
    std::string s1;
    std::string s2;

    std::stack<char> stack1;
    std::stack<char> stack2;

    std::cin>>s1>>s2;

    for(char c: s1){
        if(c == '#'){
            if(!stack1.empty()){
                stack1.pop();
            }
            continue;
        }
        stack1.push(c);
    }
    for(char c: s2){
        if(c == '#'){
            if(!stack2.empty()){
                stack2.pop();
            }
            continue;
        }
        stack2.push(c);
    }

    if(stack1 == stack2){
        std::cout<<"Yes";
    }
    else{
        std::cout<<"No";
    }
}