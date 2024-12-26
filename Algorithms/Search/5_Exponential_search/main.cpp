#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <chrono>

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
bool to_do_more = false;
bool found = false;

void binary_search(int r1,int r2, std::vector<int> arr, int key){
    int len = r2-r1;
    int mid;
    int index;

    if(len&1){
        mid = (len-1)/2;
    }else{
        mid = len/2;
    }
    bool present = false;
    if(arr[mid]>=key){
        for(int i{r1};i<mid;i++){
            if(arr[i]==key){
                index = i;
                present=true;
                break;
            }
        }
    }else if(arr[mid]<key){
        for(int i{mid};i<r2;i++){
            if(arr[i]==key){
                index = i;
                present=true;
                break;
            }
        }
    }
    if(present){
        std::cout<<index;
        found = true;
    }else{
        to_do_more = true;
    }

    
}
void case_special(int con, int key, std::vector<int> arr){
    bool special = false;
    if((length-con)!=0){
        if(arr[length-1]>=key){
            std::cout<<"  ";
            std::cout<<" case special : ";
            binary_search(con, length, arr, key);
        }
    }

}

int main(){
    int key, index, range1{1},range2{1},con;
    
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
    //Start Time
    auto start = std::chrono::high_resolution_clock::now();
    bool present=false;
    for(int i{0};i<length;i++){
        if(arr[range2-1]>=key){
            present = true;
            bool found = false;
            binary_search(range1, range2, arr, key);
            break;
            
        }else{
            //con = range1+0;
            range1=range2;
            range2=2*range1;
            con = range2;
        }
    }
    if(to_do_more){
        bool found = false;
        case_special(con, key, arr);
    }
    if(found==false){
        std::cout<<-1;
    }
    //End Time
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nExecution time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
    << " microseconds" << std::endl;
    
}