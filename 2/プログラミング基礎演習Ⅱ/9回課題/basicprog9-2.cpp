#include<iostream>
#include<fstream>
#include<string>

int main(){
    std::string line;
    std::ifstream file("personal_info.txt");
    if(!file){
        std::cout << "Eroor : Failed to open file\.n" << std::endl;
        return 0;
    }
    while (!file.eof()){
        std::getline(file,line);
        std::cout << line << std::endl;
    }
    return 0;
}