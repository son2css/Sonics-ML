#include <iostream>
#include <vector>
#include <algorithm>
class max_heap{
public:
    std::vector<int> a;

    int left(int i){
        return i*2 +1;
    }
    int right(int i){
        return i*2 +2;
    }
    int parent(int i){
        return (i-1)/2;
    }

    int getmax(){
        return a[0];
    }

    void insert(int val){
        a.push_back(val);

        int i = a.size()-1;

        while(i>0 && a[i]>a[parent(i)]){
            std::swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i){
        if(left(i) >= a.size()){
            return;
        }
        int j = left(i);

        if(right(i) < a.size() && a[right(i)] > a[j]){
            j = right(i);
        }

        if(a[i] < a[j]){
            std::swap(a[i], a[j]);
            heapify(j);
        }
    }
    int extract_max(){
        int root = getmax();
        
        std::swap(a[0], a[a.size()-1]);

        a.pop_back();
        heapify(0);
        
        return root;
    }
};
int main(){
    max_heap* h = new max_heap();
    int n, k, el;
    std::cin>>n>>k;

    while(n--){
        std::cin>>el;
        h->insert(el);
    }
    int sum =0;
    while(k--){
        int max = h->extract_max();
        sum+=max;
        max--;
        if(max!=0) h->insert(max);
    }
    std::cout<< sum;
    return 0;
}