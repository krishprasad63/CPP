#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <chrono>

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
    

bool present =false;
int index{0};
void linear_search(int r1, int r2, std::vector<int> arr, int key){
    
    
    for(int i{r1};i<=r2;i++){
        if(arr[i]==key){
            index = i;
            present = true;
            break;
        }
    }
   
}

int main(){
    int key, range1{0}, range2(1), left{0};
    
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

    std::cout<<"\nEnter the key : ";
    std::cin>>key;

    //Start time
    auto start = std::chrono::high_resolution_clock::now();
    int con ;
    while(range2<=length && !present){
        if(arr[range2]>=key){
            linear_search(range1, range2, arr, key);
        }else{
            con = range1+0;
            range1 = range2;
            range2 +=con;
            left = range2+0;
        }
        //std::cout<<"\n"<<range2<<"\n";
    }

    if(!present){
        linear_search(con, length+1, arr, key);
    }
    if(present){
        std::cout<<index ;
    }else{
        std::cout<<-1;
    }

    //End time
    auto end = std::chrono::high_resolution_clock::now();

    std::cout<<" \n Execution Time : "<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<" microseconds";

}