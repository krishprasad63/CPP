#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>
#include <chrono>






int main(){
    int len, key, index, to_check;
    std::ifstream inputFile("sorted_numbers.txt"); 
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    std::vector<int> numbers; 
    int number;

    
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    inputFile.close();

    len = numbers.size();;
  
    std::cout << std::endl;




    std::cout<<"\n";
    
    std::cout<<"Enter the key : ";
    std::cin>>key;

    //Start time
    auto start = std::chrono::high_resolution_clock::now();
    if(len&1){
        to_check = (len-1)/2;

    }else{
        to_check = len/2;
    }

    if(numbers[to_check]==key){

        std::cout<<to_check;

    }else if(numbers[to_check]<key){

        bool present=false;
        for(int i{to_check};i<len;i++){
            if(numbers[i]==key){
                index = i;
                present=true;
                break;
            }
        }
        if(present){
            std::cout<<index;
        }else{
            std::cout<<-1;
        }
    }else if(numbers[to_check]>key){
        
        bool present=false;
        for(int i{0};i<to_check;i++){
            if(numbers[i]==key){
                index = i;
                present=true;
                break;
            }
        }
        if(present){
            std::cout<<index;
        }else{
            std::cout<<-1;
        }
    }
    //End time
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nExecution time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds" << std::endl;


}