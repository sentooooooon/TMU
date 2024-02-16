#include<iostream>
#include<fstream>
#include<string>

int main(){
    std::string line;
    std::ifstream file("personal_info.txt");
    if(!file){
        std::cout << "Eroor : Failed to open file.\n" << std::endl;
        return 0;
    }
    int c=-1;
    int b = 0;
    while (!file.eof()){
        if(std::getline(file,line)){
            c++;
            }
        int a = line.find("Tokyo");
        /*std::cout << a << std::endl;*/
        if(a!=-1)b++;

    }
    std::cout << "全部で" << c  << "人います。" << std::endl;
    std::cout << "東京住みの人数　：　" << b << std::endl;
    return 0;
}