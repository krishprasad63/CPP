//This will be the prooject for advanced smart parking system
#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <fstream>
#include <string>
#include <iomanip>
#include <array>
#include <ctime>

int main();
int eoo;
void intro();
enum VehicleType { CAR=1, BIKE=2, TRUCK=3 };
int vehicle;
std::string vehicle_number;

int rows = 2, cols = 3; // for floors and number of slots
//string array, will consist vehicle no. or empty
std::vector<std::vector<std::string>> stringMatrix(rows, std::vector<std::string>(cols, "Empty"));


//temporary i and j for location purposes :)
int temp_i{2};
int temp_j{3};

//entry time array

std::array<std::array<std::chrono::high_resolution_clock::time_point, 3>, 2> start_time;

//Human readable time format

std::string getTimeAsString(const std::chrono::high_resolution_clock::time_point& time_point) {
    auto time_t = std::chrono::system_clock::to_time_t(
        std::chrono::time_point_cast<std::chrono::seconds>(time_point)
    );
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

bool check_slot(){
    for(int i{0};i<rows;i++){
        for(int j{0};j<cols;j++){
            if(stringMatrix[i][j]=="Empty"){
                temp_i = i;
                temp_j = j;
                
                return true;
            }
        }
    }
    return false;
}
//entry receipt
void entry_receipt(std::string vehicle_num, int vehic, int floor, int slot){
    std::string file_name= "EntryReceipt-"+vehicle_num+".txt";
    std::ofstream file(file_name, std::ios::app); // 'app' to append data to the file
    if (!file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    // Write data to the file
    file << "--------Parking Complex--------"<<"\n"
         << "    -----Entry Reciept-----\n"
         << "-------------------------------\n"
         << "Entry Time :"<< getTimeAsString(start_time[floor][slot])<<"\n"
         << "Vehicle Number: " << vehicle_num << "\n"
         << "Vehicle Type: " << vehic << "\n"
         << "Floor: " << floor << "\n"
         << "Slot: " << slot+1 << "\n"
         << "-------------------------------\n"
         << "Keep this Receipt with"<<"\n"
         << "you for check out!"<<"\n"
         << "-------------------------------\n";

    // Close the file
    file.close();

    std::cout << "Vehicle data saved successfully." << std::endl;
    std::cout<<"----------------------------------------------------------\n";
    
    intro();

}
void enter(){
    if(check_slot()==true){
        std::cout<<"Enter your Vehicle type :\n1.Car\n2.Bike\n3.Truck\n";
        std::cin>>vehicle;
        switch (vehicle)
        {
        case CAR:
            std::cout<<"Your vehicle is a car.\nEnter the vehicle number : ";
            break;
        case BIKE:
            std::cout<<"Your vehicle is a bike.\nEnter the vehicle number : ";
            break;
        case TRUCK:
            std::cout<<"Your vehicle is a truck.\nEnter the vehicle number : ";
            break;
        
        default:
            std::cout<<"Invalid Input\n";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            intro();
            
            break;
        }
        std::cin>>vehicle_number;
        std::cout<<"----------------------------------------------------------\n";
        std::cout<<"Your vehicle number is :"<<vehicle_number<<std::endl;
        stringMatrix[temp_i][temp_j]=vehicle_number;
        std::cout<<"Your vehicle is parked at floor "<<temp_i<<" at SLOT "<<temp_j+1<<std::endl;
       
        start_time[temp_i][temp_j]= std::chrono::high_resolution_clock::now();
        std::cout<<"----------------------------------------------------------\n";
        std::cout<<"-----Collect your Entry Receipt.-----"<<std::endl;
        std::cout<<"----------------------------------------------------------\n";
        entry_receipt(vehicle_number, vehicle, temp_i, temp_j);

    }else{
        std::cout<<"There is NO SLOTS Empty. Sorry for the inconvenience.";
        std::cin.clear();
        std::cin.ignore(256,'\n');
    }
    
}
int exit_i{0};
int exit_j{0};

//find vehicle with vehicle number for exit purposes
bool find_vehicle_with_vehicle_no(std::string vehic_number){
    for(int i{0};i<rows;i++){
        for(int j{0};j<cols;j++){
            if(stringMatrix[i][j]==vehic_number){
                exit_i = i;
                exit_j = j;
                //stringMatrix[i][j]="Empty";
                return true;
            }
        }
    }
    return false;

}
//exit receipt
void exit_receipt(std::string vehicle_num, std::string vehic, double charge){

    stringMatrix[exit_i][exit_j]="Empty";
    auto exit_time = std::chrono::high_resolution_clock::now();//exit time

    auto duration = std::chrono::duration_cast<std::chrono::minutes>(exit_time - start_time[exit_i][exit_j]);
    int duration_count = duration.count();
    double total_price =charge*duration_count;
    double gst = (18*total_price)/100;
    double final_price = total_price + gst;

    //std::cout << "Duration: " << duration.count() << " minutes" << std::endl;


    std::string file_name= "PaymentReceipt-"+vehicle_num+".txt"; // file name

    std::ofstream file(file_name, std::ios::app); // 'app' to append data to the file
    if (!file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    // Write data to the file
    file << "--------Parking Complex--------"<<"\n"
         << "   -----Payment Receipt-----\n"
         << "-------------------------------\n"
         << "Entry Time :"<< getTimeAsString(start_time[exit_i][exit_j])<<"\n"
         << "Exit Time  :"<< getTimeAsString(exit_time)<<"\n"
         << "Duration   :"<< duration_count <<"\n"
         << "--------------------------------\n"
         << "Vehicle Number: " << vehicle_num << "\n"
         << "Vehicle Type: " << vehic << "\n"
         << "-------------------------------\n"
         << "For 1 minute, Charge: $"<<charge<< "\n"
         << "Total Cost : $" << charge*duration_count<< "\n"
         << "GST (18%) : $"  << gst<< "\n"
         << "-------------------------------\n"
         << "Final Price : $"<< final_price<< "\n"
         << "-------------------------------\n"
         << "Thanks for visiting to us."<<"\n"
         << "Hope, we will see you again."<<"\n"
         << "-------------------------------\n";

    // Close the file
    file.close();
    std::cout<<"----------------------------------------------------------\n";
    std::cout << "Payment Receipt generated.\nCollect your Receipt." << std::endl;
    std::cout<<"----------------------------------------------------------\n";
    
    intro();

}
void leave(int opt, std::string vehic){
    double charge;
    switch (opt)
    {
    case 1:
        charge = 0.50;
        break;
    case 2:
        charge = 0.30;
        break;
    case 3:
        charge = 1.00;
        break;
    
    default:
        std::cin.clear();
        std::cin.ignore(256,'\n');
        intro();
        break;
    }
    std::cout<<"Thanks for using our service."<<std::endl;
    std::string vehicle_to_be_left ;
    std::cout<< "Enter your vehicle number : ";
    std::cin>>vehicle_to_be_left;

    if(find_vehicle_with_vehicle_no(vehicle_to_be_left)==true){
        exit_receipt(vehicle_to_be_left, vehic,charge);
        
    }else{
        std::cout<<"----------------------------------------------------------\n";
        std::cout<<"No vehicle found with vehicle no. : "<<vehicle_to_be_left<<std::endl;
        std::cout<<"----------------------------------------------------------\n";
        intro();
    }
}
//For exit vehicle type input
int opt;
std::string vehic(){
    std::cout << "Enter your vehicle type : \n1.Car\n2.Bike\n3.Truck\n ";
    
    std::cin>>opt;
    switch (opt)
    {
    case 1:
        return "Car";
        break;
    case 2:
        return "Bike";
        break;
    case 3:
        return "Truck";
        break;
    
    default:
        return "Invalid";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        intro();
        break;
    }
}
void print_str_array(){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << stringMatrix[i][j] << " ";  
        }
        std::cout << std::endl;  
    }

}

void admin(){
    int choose;
    std::cin>>choose;
    switch (choose)
    {
    case 1:
        print_str_array();
        intro();
        break;
    
    default:
        break;
    }
}
int error(){
    std::cout<<"Some error occured\n";
    //main();
    return 0;
}

void intro(){
    std::cout<<"----------------------------------------------------------\n";
    std::cout<<"Welcome to the parking. Here, you can park your vehicle.\n";
    std::cout<<"\n";
    std::cout<<"Choose from the following :\n";
    std::cout<<"1.Enter   2. Leave\n   ";
    
    std::cin>>eoo;
    //std::cout<<"Value of eoo : "<<eoo<<"\n";
    


    if (eoo==1)
    {
        enter();
    }else if(eoo==2){
        leave(opt,vehic());
    }else if(eoo==3){
        admin();
    }else{
        error();
        std::cin.clear();
        std::cin.ignore(256,'\n');
    }
    
}

int main(){
    while(true)
    {
        intro();
    }
    
    

}



