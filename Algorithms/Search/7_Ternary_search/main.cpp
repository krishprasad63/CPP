#include <iostream>
#include <vector>
#include <cmath>

int length;
std::vector<int> taking_array_and_key(){
    int len;
    std::cout<<"Length of the array : ";
    std::cin>>len;
    length = len;
    std::vector<int> arr(len);
    std::cout<<"Enter array elements : ";

    for(int i{0};i<len;i++){
        std::cin>>arr[i];
    }
    std::cout<<"Array elements you entered are : ";

    for(int i{0};i<len;i++){
        std::cout<<arr[i]<<" ";
    }
    return arr;
}

int main(){
    int key;
    
    std::vector<int> arr = taking_array_and_key();
    std::cout<<"\n";
    std::cout<<"Enter the key : ";
    std::cin>>key;
    
        
}