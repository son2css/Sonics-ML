#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, m;
    std::cin>>n>>m;
    std::vector<int> v1;
    std::vector<int> v2;
    for(int i=0; i<n; i++){
        int el;
        std::cin>>el;
        v1.push_back(el);
    }
    for(int i=0; i<m; i++){
        int el;
        std::cin>>el;
        v2.push_back(el);
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    int i = 0;
    int j=0;

    while(i<n && j<m){
        if(v1[i]<v2[j]){
            i++;
        }
        else if(v2[j] < v1[i]){
            j++;
        }
        else{
            int count1 =0;
            int count2 =0;
            int val = v1[i];

            while(i<n && val==v1[i]){
                count1++;
                i++;
            }
            while(j<m && val == v2[j]){
                count2++;
                j++;
            }
            int count = std::min(count1, count2);

            while(count--){
                std::cout<<val<<" ";
            }
        }
    }
}