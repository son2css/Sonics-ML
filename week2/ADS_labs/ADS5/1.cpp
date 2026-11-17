#include <iostream>
#include <vector>
class min_heap{
public:
    std::vector<int> a;

    int left(int val){
        return val*2 +1;
    }
    int right(int val){
        return val*2 +2;
    }
    int parent(int val){
        return (val-1)/2;
    }

    long long getmin(){
        return a[0];
    }
    void insert(long long val){
        a.push_back(val);

        int i = a.size()-1;

        while(i>0 && a[i]< a[parent(i)]){
            std::swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i){
        if(left(i) > a.size() -1) return;

        int j = left(i);

        if(right(i) < a.size() && a[right(i)] <a[j]){
            j = right(i);
        }

        if(a[j] < a[i]){
            std::swap(a[j], a[i]);
            heapify(j);
        }
    }
    long long extract_min(){
        long long root = getmin();

        std::swap(a[0], a[a.size() -1] );
        a.pop_back();

        if(!a.empty()){
            heapify(0);
        }
        return root;
    }
};
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    min_heap* h = new min_heap();
    int n, el;
    std::cin>>n;
    long long sum_max = 0;

    for(int i=0; i<n; i++){
        std::cin>>el;
        h->insert(el);
    }

    while(h->a.size() > 1){
        long long min1 = h->extract_min();
        long long min2 = h->extract_min();

        long long sum = min1+min2;

        sum_max += sum;

        h->insert(sum);

    }
    std::cout<<sum_max;
    return 0;
}