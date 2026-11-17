#include <iostream>
#include <vector>

class min_heap{
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

    int min(){
        return a[0];
    }

    void insert(int val){
        a.push_back(val);
        int i = a.size()-1;

        while(i>0 && a[i] < a[parent(i)]){
            std::swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i){
        if(left(i) > a.size()-1) return;

        int j = left(i);

        if(right(i) < a.size() && a[right(i)] < a[j]){
            j = right(i);
        }

        if(a[i] > a[j]){
            std::swap(a[i], a[j]);
            heapify(j);
        }
    }
    int extract_min(){
        int root = a[0];
        std::swap(a[0], a[a.size()-1]);

        a.pop_back();
        heapify(0);
        return root;
    }
};
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    min_heap* h = new min_heap();

    int n, m, el;
    std::cin>>n>>m;
    while(n--){
        std::cin>>el;
        h->insert(el);
    }   
    int count = 0;

    while(h->min() < m){
        if(h->a.size() < 2){
            std::cout<<-1;
            return 0;
        }
        
        int min1 = h->extract_min();
        int min2 = h->extract_min();

        int merge = min1 + 2*min2;
        count++;
        h->insert(merge);
    }
    std::cout<<count;
}

