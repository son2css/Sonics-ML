#include <iostream>
#include <vector>

class custom_heap{
public:
    std::vector<int> a;
    int s=0;

    int right(int i){
        return i*2 +2;
    }
    int left(int i){
        return i*2 +1;
    }
    int parent(int i){
        return (i-2)/2;
    }

    int getmin(){
        return a[0];
    }

    void insert(int val, int k){
        if(a.size()==k){
            if(val<=getmin()) return;

            s-=a[0];
            a[0] = val;
            s+=val;

            heapify(0);
        }

        else{
            s+=val;
            a.push_back(val);
            int i = a.size()-1;

            while(i>0 && a[i] < a[parent(i)]){
                std::swap(a[i], a[parent(i)]);
                i = parent(i);
        }

    }
}
    void heapify(int i){
        if(left(i) > a.size()-1) return;

        int j = left(i);

        if(right(i) < a.size() && a[j] > a[right(i)]){
            j = parent(i);
        }
        if(a[j] < a[i]){
            std::swap(a[i], a[j]);
            heapify(j);
        }
    }
};
int main(){
    custom_heap* h = new custom_heap();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k, el;
    std::cin>>n>>k;
    while(n--){
        std::string s;
        std::cin>>s;

        if(s == "print"){
            std::cout<<h->s<<"\n";
        }
        else{
            std::cin>>el;

            h->insert(el, k);
        }
    }

}