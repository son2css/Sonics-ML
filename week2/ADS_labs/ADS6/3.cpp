#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin>>n;
    std::vector<int> a(n);

    for(int i=0; i<n; i++){
        std::cin>>a[i];
    }
    std::sort(a.begin(), a.end());

    int i=0;
    int j =1;
    long long min = 100000000;

    std::vector<int> ans;

    while(i<j && j<n){
        if(a[j] - a[i] < min){
            while(!ans.empty()){
                ans.pop_back();
            }
            min = a[j] - a[i];
            ans.push_back(a[i]);
            ans.push_back(a[j]);
        }
        else if(a[j] - a[i] == min){
            ans.push_back(a[i]);
            ans.push_back(a[j]);
        }
        i++;
        j++;
    }
    for(int i=0; i<ans.size(); i++){
        std::cout<<ans[i]<<" ";
    }
}