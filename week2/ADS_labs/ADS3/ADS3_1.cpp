#include <iostream>

int main(){
    int matrix[100][100];

    int n;
    std::cin>>n;

    int find_nums[n];
    int nums;

    for(int i=0; i<n; i++){
        std::cin>>nums;
        find_nums[i] = nums;
    }

    int rows, columns;
    std::cin>>rows>>columns;

    int element;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            std::cin>>element;
            matrix[i][j] = element;
        }
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<rows; i++){
            if(i%2==0){
                if(matrix[i][0]>find_nums[k]){
                    continue;
                }else{
                    int l=0; 
                    int r = columns-1;
                    while(l<=r){
                        int mid = (l+r)/2;

                        if(find_nums[k] > matrix[i][mid]){
                            r = mid-1;
                            continue;
                        }
                        else if(find_nums[k] < matrix[i][mid]){
                            l = mid+1;
                            continue;
                        }
                        else{
                            std::cout<<i<<" "<<mid<<std::endl;
                            break;
                        }
                    }
                }
            }
            else{
                if(matrix[i][0]<find_nums[k]){
                    continue;
                }
                else{
                    int l=0;
                    int r = columns-1;

                    while(l<=r){
                        int mid = (l+r)/2;

                        if(find_nums[k]<matrix[i][mid]){
                            r= mid-1;
                            continue;
                        }
                        else if(find_nums[k] > matrix[i][mid]){
                            l = mid+1;
                            continue;
                        }
                        else{
                            std::cout<<i<<" "<<mid<<std::endl;
                            break;
                        }
                    }
                }
            }
        }
    }
}