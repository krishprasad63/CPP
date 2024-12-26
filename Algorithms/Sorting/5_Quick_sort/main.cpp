#include <iostream>
#include <fstream>
#include <vector>
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
    
    for(int i=1;i<size;++i){
        int value = arr[i];
        int j=i-1;
        while(value<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1]=value;
    }
    std::cout<<"\n sorted\n";
    printarray(arr);
}
int main(){
    std::vector<int> arr;
    arr = testcase();
    printarray(arr);
    int size = arr.size();
    //std::cout<<size;
    insertionsort(size, arr);



}