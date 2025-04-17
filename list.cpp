#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <fstream>

std::vector<std::string> mainVector;

void addEntry();
void removeEntry();
void viewEntry();

int main(){
    
    int menuOption;
    std::ifstream file("filename.txt");
    std::string line;
    while (std::getline(file, line)) {
    mainVector.push_back(line);
}
    
    while(true){
    std::cout << "What would you like to do?\n1. Add entry\n2. Remove entry\n3. View all entries\n4. Save and exit\n(1, 2, 3 ,4)\n";
    std::cin >> menuOption;
    std::cout << '\n';
    
    if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input, please enter a number between 1 and 4\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1250));
            #ifdef _WIN32
                std::system("cls");
                continue;
            #elif __linux__
                std::system("clear");
                continue;
            #endif
    }
    
    switch(menuOption){
        case 1:
            addEntry();
            break;
        case 2:
            removeEntry();
            break;
        case 3:
            viewEntry();
            break;
        case 4: {
	    std::ofstream MyFile("filename.txt");
            for(int i = 0; i < mainVector.size(); i++){
                MyFile << mainVector[i] << '\n';
            }
            MyFile.close();
            return 0;
        }
        default: 
            std::cout << "Invalid input, please enter a number between 1 and 4\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1250));
            #ifdef _WIN32
                std::system("cls");
                break;
            #elif __linux__
                std::system("clear");
                break;
            #endif
    }}
}

void addEntry(){
    std::string userInput;
    
    std::cout << "What info would you like to input?: ";
    std::cin.ignore();
    std::getline(std::cin, userInput);
    std::cout << "\nEntry added successfully!\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1250));
    #ifdef _WIN32
        std::system("cls");
    #elif __linux__
        std::system("clear");
    #endif
    
    mainVector.push_back(userInput);
}

void removeEntry(){
    int userInput;
    
    if (mainVector.size() <= 0){
        std::cout << "There are no entries to delete\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1250));
        #ifdef _WIN32
            std::system("cls");
        #elif __linux__
            std::system("clear");
        #endif
        return;
    }
    
    for(int i = 0; i < mainVector.size(); i++){
            std::cout << i + 1 << ". " << mainVector[i] << "\n";
    }
    std::cout << '\n';
    
    std::cout << "What info would you like to erase? (1-" << mainVector.size() << ")";
    std::cin >> userInput;
    
    if(userInput <= 0 || userInput > mainVector.size()){
        std::cout << "\nEntry does not exist. Please put in a valid entry\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1250));
    #ifdef _WIN32
        std::system("cls");
    #elif __linux__
        std::system("clear");
    #endif
        return;
    } else {
    std::cout << "\nEntry deleted successfully!\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1250));
    #ifdef _WIN32
        std::system("cls");
    #elif __linux__
        std::system("clear");
    #endif
    
    mainVector.erase(mainVector.begin() + userInput - 1);
    }
}

void viewEntry(){
    if (mainVector.size() <= 0){
        std::cout << "There are no entries to display\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1250));
    #ifdef _WIN32
        std::system("cls");
    #elif __linux__
        std::system("clear");
    #endif
        return;
    }
    
    for(int i = 0; i < mainVector.size(); i++){
            std::cout << i + 1 << ". " << mainVector[i] << '\n';
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1250));
    std::cin.ignore();
    std::cout << "\nPress enter to continue...";
    std::cin.get();
    #ifdef _WIN32
        std::system("cls");
    #elif __linux__
        std::system("clear");
    #endif
    std::cout << '\n';
}
