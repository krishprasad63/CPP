#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>



int main(){//Start time
    

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

    int key, index;
    int len = 100000;
  
    std::cout << std::endl;


    std::cout<<"\n";
    
    std::cout<<"Enter the key : ";
    std::cin>>key;
    auto start = std::chrono::high_resolution_clock::now();

    bool present = false;

    for(int i{0};i<len;i++){
        if(numbers[i] == key){
            index = i;
            present = true;
            break;
        }
    }
    if(present){
        std::cout<<"Required index is : "<<index;

    }else{
        std::cout<<-1;
    }
    //End time
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nExecution time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds" << std::endl;
}
