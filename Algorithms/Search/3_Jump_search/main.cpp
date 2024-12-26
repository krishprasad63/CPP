#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>

int length;
/*
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
    */

int main(){
    int root, index{0}, to_check{0},key,remain{0};
    
    //std::vector<int> arr = taking_array_and_key();
    std::ifstream inputFile("sorted_numbers.txt"); 
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    std::vector<int> arr; 
    int number;

    
    while (inputFile >> number) {
        arr.push_back(number);
    }

    inputFile.close();

    length = arr.size();;
  
    std::cout << std::endl;

    std::cout<<"\n";
    std::cout<<"Enter the key : ";
    std::cin>>key;
    
    auto start = std::chrono::high_resolution_clock::now();
    root = int(sqrt(length));
    
    for(int i{root-1};i<length;i+=root){
        //std::cout<<i<<"\n";
        if(key<=arr[i]){
            to_check = i;
            break;
        }
        remain = i;

    }
    bool present=false;
    for(int i{to_check-root};i<to_check+1;i++){
        if(key==arr[i]){
            index=i;
            present=true;
            break;
        }
        
    }
    bool special = false;
    if(remain!=0){
        for(int i{remain};i<length;i++){
            if(key==arr[i]){
                index=i;
                special=true;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();


    if(present){
        std::cout<<index;
    }else if(special){
        std::cout<<index;
    }else{
        std::cout<<-1;
    }
   
    std::cout << "\nExecution time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds" << std::endl;

}