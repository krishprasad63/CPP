//This will be a traffic light program. So here it goes :)
#include <iostream>
#include <chrono>
#include <thread>
void open_ew(){
    std::cout<< "\n";
    std::cout <<"     Open Lanes:"<<std::endl;
    std::cout <<"East to West  : Green"<<std::endl;
    std::cout <<"West to East  : Green"<<std::endl;
    std::cout <<"West to North : Green"<<std::endl;
    std::cout <<"East to South : Green"<<std::endl;
    std::cout<< "\n";

}
void close_ew(){
    std::cout<< "\n";
    std::cout <<"East to West  : Red"<<std::endl;
    std::cout <<"West to East  : Red"<<std::endl;
    std::cout <<"West to North : Red"<<std::endl;
    std::cout <<"East to South : Red"<<std::endl;
    std::cout<< "\n";
}

void open_ns(){
    std::cout<< "\n";
    std::cout <<"     Open Lanes:"<<std::endl;
    std::cout <<"North to South : Green"<<std::endl;
    std::cout <<"South to North : Green"<<std::endl;
    std::cout <<"South to West  : Green"<<std::endl;
    std::cout <<"North to East  : Green"<<std::endl;
    std::cout<< "\n";
}


void close_ns(){
    std::cout << "Timeout reached!" << std::endl;
    std::cout<< "\n";
    std::cout <<"North to South : Red"<<std::endl;
    std::cout <<"South to North : Red"<<std::endl;
    std::cout <<"South to West  : Red"<<std::endl;
    std::cout <<"North to East  : Red"<<std::endl;
    std::cout<< "\n";
}

void east_west(){
    auto start = std::chrono::steady_clock::now();
    int i=10;
    int timeout = 10; 
    open_ew();
    while(true){
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = now - start;
        if (elapsed.count() >= timeout) {
            std::cout << "Timeout reached!" << std::endl;
            close_ew();
            i=10;
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
        
        std::cout << i << " ";
        i-=1;

    } 
    
}
void north_south(){
    auto start = std::chrono::steady_clock::now();
    int i=10;
    int timeout = 10; 
    open_ns();
    while(true){
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = now - start;
        if (elapsed.count() >= timeout) {
            close_ns();
            i=10;
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));  
        
        std::cout << i << " ";
        i-=1;

    } 
    
}

void road(){
    std::cout<<"                     |        .        |  N"<<std::endl;
    for(int i{0};i<5;i++){
        std::cout<<"                     |        .        |"<<std::endl;
    }
    std::cout<<" W                   |        .        |                   E"<<std::endl;
    std::cout<<"_____________________|        .        |_____________________"<<std::endl;
    for(int i{0};i<3;i++){
        std::cout<<"                                         "<<std::endl;
    }
    std::cout<<". . . . . . . . . . .                     . . . . . . . . . . ."<<std::endl;
    for(int i{0};i<2;i++){
        std::cout<<"                                         "<<std::endl;
    }
    std::cout<<"_____________________                   _____________________"<<std::endl;
    for(int i{0};i<7;i++){
        std::cout<<"                     |        .        |"<<std::endl;
    }
    std::cout<<"                     |        .        |  S"<<std::endl;
    

}

int main(){
    road();
    while(true){
        north_south();
        east_west();
    }

}

