#include <iostream>
#include <queue>
#include <stack>

int main(){
    std::stack<std::string> arr;
    std::queue<std::string> probs;
    int n, m;
    std::string ch;


    std::cin>>n;
    for(int i=0; i<n; i++){
        std::cin>>m;
        for(int j=0; j<m; j++){
            std::cin>>ch;
            if(arr.empty()){
                arr.push(ch);
                probs.push(ch);
                continue;
            }
            if(arr.top() == ch){
                if(probs.empty()){
                    arr.push("-1");
                    continue;
                }
                if(probs.size() == 1){
                    probs.pop();
                    arr.push("-1");
                    continue;
                }
                probs.pop();
                arr.push(probs.front());
            }else{
                probs.push(ch);
                arr.push(probs.front());
            }

        }
    }
    while(!arr.empty()){
        std::cout<<arr.top()<<" ";
        arr.pop();
    }
}