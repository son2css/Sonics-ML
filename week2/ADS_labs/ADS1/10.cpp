#include <iostream>
#include <deque>

int main(){
    std::deque<int> nurs;
    std::deque<int> bor;

    for(int i=0; i<5; i++){
        int el;
        std::cin>>el;
        bor.push_back(el);
    }

    for(int i=0; i<5; i++){
        int el;
        std::cin>>el;
        nurs.push_back(el);
    }
    int count = 0;
    while(!bor.empty() && !nurs.empty()){
        int b= bor.front();
        int n = nurs.front();
        bor.pop_front();
        nurs.pop_front();

        bool b_wins = ((b==0 && n ==9) || ((b > n) && !(b==9 && n == 0)));

        if(b_wins){
            count++;

            bor.push_back(b);
            bor.push_back(n);
        }
        else{
            count++;

            nurs.push_back(b);
            nurs.push_back(n);
        }

    }

    if(!bor.empty()){
        std::cout<<"Boris"<<" "<<count;;
    }
    else{
        std::cout<<"Nursik"<<" "<<count;
    }
}