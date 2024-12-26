#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

std::vector<int> testcase(){
    std::ifstream inputfile("numbers.txt");
    std::vector<int> arr;
    int number;
    while(inputfile>>number){
        arr.push_back(number);
    }
    inputfile.close();
    return arr;
}
void printarray(std::vector<int> arr){
    //Printing Array :)
    for(int i:arr){
        std::cout<<i << " ";
    }
}
void insertionsort(int size, std::vector<int> arr){
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=1;i<size;++i){
        int value = arr[i];
        int j=i-1;
        while(value<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1]=value;
    }

    auto end = std::chrono::high_resolution_clock::now();
        
    std::ofstream outfile("sorted_numbers.txt");
    for(int i{0};i<size;i++){
        outfile<<arr[i];
        if(i<size-1){
            outfile<<" ";
        }
    }
    outfile.close();
    std::cout << "Array written to sorted_numbers.txt successfully." << std::endl;

    std::chrono::duration<double> elapsed = end-start;
    std::cout<<" Time taken : "<<elapsed.count()<< " s";
    std::cout<<" Time taken : "<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << " microseconds";
    //std::cout<<"\n sorted\n";
    //printarray(arr);
}
int main(){
    std::vector<int> arr;
    arr = testcase();
    //printarray(arr);
    int size = arr.size();
    //std::cout<<size;
    insertionsort(size, arr);



}