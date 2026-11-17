#include <iostream>
#include <vector>
#include <queue>

int main(){
    int total;
    std::cin>>total;
    for(int i=0; i<total; i++){
        int length;
        std::cin>>length;
        std::queue<char> q;
        std::vector<int> vec(26, 0);

        for(int j=0; j<length; j++){
            char ch;
            std::cin>>ch;
            vec.at(ch - 'a')++;
            q.push(ch);

            while(!q.empty() && vec.at(q.front() - 'a') > 1){
                q.pop();
            }

            if(q.empty()){
                std::cout<<-1<<" ";
                continue;
            }
            std::cout<<q.front()<<" ";
        }
        std::cout<<"\n";
    }
}