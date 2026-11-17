#include <algorithm>
#include <string>
#include <iostream>
void quick_sort(std::string& s, int l, int r){
    int p = s[(l + r)/2];
    int i = l;
    int j = r;

    while(i<j){
        while(s[i]<p) i++;
        while(s[j]>p) j--;

        if(i<=j){
            std::swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    if(l<j){
        quick_sort(s,l,j);
    }
    if(i<r){
        quick_sort(s, i, r);
    }
}
int main(){
    std::string s;
    std::cin>>s;
    quick_sort(s, 0, s.size()-1);
    std::cout<<s;
}