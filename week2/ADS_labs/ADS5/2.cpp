#include <iostream>
#include <vector>

class max_heap{
public:
    std::vector<long long> a;

    int right(int i){
        return i*2 +2;
    }
    int left(int i){
        return i*2 +1;
    }
    int parent(int i){
        return (i-1)/2;
    }

    long long max(){
        return a[0];
    }

    void insert(long long val){
        a.push_back(val);
        int i= a.size() -1;

        while(i >= 0 && a[i]>a[parent(i)]){
            std::swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i){
        if(left(i) >= a.size()) return;

        int j = left(i);

        if(right(i)<a.size() && a[right(i)] > a[j] ){
            j = right(i);
        }
        if(a[i] < a[j]){
            std::swap(a[i], a[j]);
            heapify(j);
        }
    }
    long long extract_max(){
        long long root = max();
        std::swap(a[a.size() -1], a[0]);

        a.pop_back();
        heapify(0);

        return root;
    }
};
int main(){
    max_heap* h = new max_heap();
    int n, el;
    std::cin>>n;

    while(n--){
        std::cin>>el;
        h->insert(el);
    }

    while(h->a.size() > 1){
        long long max1 = h->extract_max();
        long long max2 = h->extract_max();

        long long extr = max1- max2;

        if(extr !=0){
            h->insert(extr);
        }
    }
    if(h->a.size() == 0){
        std::cout<<0;
    }
    else{
        std::cout<<h->a[0];
    }
    return 0;
}