#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    int n, m;
    std::cin>>n>>m;
    int ans[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cin>>ans[i][j];
        }
    }

    for(int j =0; j<m; j++){
        std::vector<int> vec;
        for(int i=0; i<n; i++){
            vec.push_back(ans[i][j]);
        }
        std::sort(vec.begin(), vec.end(), std::greater<int>());

        for(int i=0; i<n; i++){
            ans[i][j] = vec[i];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cout<<ans[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}