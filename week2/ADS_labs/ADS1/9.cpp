#include <iostream>
#include <cmath>
#include <deque>

int main(){
    int n;
    std::cin>>n;

    while(n--){
        int quantity;
        std::cin>>quantity;

        std::deque<int> deck;

        for(int i = quantity; i>0; i--){
            if(deck.empty()){
                deck.push_front(i);
                continue;
            }
            deck.push_front(i);

            for(int l = 0; l<i; l++){
                int val = deck.back();
                deck.pop_back();

                deck.push_front(val);
            }
        }

        while(!deck.empty()){
            std::cout<<deck.front()<<" ";
            deck.pop_front();
        }
    }
}