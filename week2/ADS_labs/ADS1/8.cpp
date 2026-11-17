#include <iostream>
#include <queue>
#include <stack>

int main(){
    int n;
    std::cin>>n;

    std::queue<long long> q;
    std::stack<long long> stack;

    while(n--){
        int el;
        std::cin>>el;

        if(q.empty()){
            q.push(-1);
            stack.push(el);
            continue;
        }

        while(!stack.empty()){
            if(stack.top() < el){
                q.push(stack.top());
                stack.push(el);
                break;
            }
            else{
                stack.pop();
            }
        }
        if(stack.empty()){
            q.push(-1);
            stack.push(el);
        }
    }

    while(!q.empty()){
        std::cout<<q.front()<<" ";
        q.pop();
    }
}