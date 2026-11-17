#include <iostream>
#include <vector>

void max_heap(std::vector<int>& v, int i){
    int n = v.size();
    while(2 * i < n) {
        int c = 2 * i;
        if (c+1 < n && v[c] < v[c+1]) {
            c = c + 1;
        }
        if (v[c] > v[i]) {
            std::swap(v[c], v[i]);
            i = c;
        } else break;
    }
}

int main(){
    int n;
    std::cin>>n;

    std::vector<int> v(n+1);

    for(int i=1; i<n+1; i++){
        std::cin>>v[i];
    }
    for (int i = n / 2; i >= 1; i--) {
        max_heap(v, i);
    }
    for (int i = 1 ; i <= n; ++i) {
        std::cout << v[i] << " ";
    }
    std::sort(v.begin()+1, v.end());
    std::cout<<"\n";
    for (int i = 1 ; i <= n; ++i) {
        std::cout << v[i] << " ";
    }
}