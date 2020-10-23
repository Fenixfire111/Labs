#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string file = "input.txt";
    std::string file1 = "output_1.txt";
    std::string file2 = "output_2.txt";
    std::cout << "Do you want to open the input file? (yes/no)"<<std::endl;
    std::string OpenInput;
    std::cin >> OpenInput;
    std::ifstream fin;
    std::string SeeInput;
    if (OpenInput == "yes") {
        fin.open(file);
        std::cout << "Do you want to see the input file? (yes/no)"<<std::endl;
        std::cin >> SeeInput;
    }
    std::cout << "Do you want to open the output1 file? (yes/no)"<<std::endl;
    std::string OpenOutput1;
    std::cin >> OpenOutput1;
    std::ofstream out1;
    std::string SeeOutput1;
    if (OpenOutput1 == "yes") {
        out1.open(file1);
        std::cout << "Do you want to see the output1 file? (yes/no)"<<std::endl;
        std::cin >> SeeOutput1;
    }
    std::cout << "Do you want to open the output2 file? (yes/no)"<<std::endl;
    std::string OpenOutput2;
    std::cin >> OpenOutput2;
    std::ofstream out2;
    std::string SeeOutput2;
    if (OpenOutput2 == "yes") {
        out2.open(file2);
        std::cout << "Do you want to see the output2 file? (yes/no)"<<std::endl;
        std::cin >> SeeOutput2;
    }
    std::string str;
    int name=0;
    while (!fin.eof())
    {
        std::getline(fin, str);
        bool check1 = true;
        bool check2 = true;
        for (int i = 0; i < str.length()-1; ++i)
        {
            if (str[i] > str[i+1]){
                check1 = false;
                break;
            }
        }
        if(check1==true) {
            out1 << str << std::endl;
        }
        for (int i = 0; i < str.length()-1; ++i)
        {
            if (str[i] < str[i+1]){
                check2 = false;
                break;
            }
        }
        if(check2==true) {
            out2 << str << std::endl;
        }
        if (SeeInput == "yes") {
            if(name==0){
                std::cout << "Content of the input file:"<<std::endl;
                ++name;
            }
            std::cout << str<<std::endl;
        }
    }
    if (SeeOutput1 == "yes") {
        std::cout << "Content of the output1 file:"<<std::endl;
        std::ifstream fin1;
        fin1.open(file1);
        while (!fin1.eof()){
            std::getline(fin1, str);
            std::cout << str<<std::endl;
        }
    }
    if (SeeOutput2 == "yes") {
        std::cout << "Content of the output2 file:"<<std::endl;
        std::ifstream fin2;
        fin2.open(file2);
        while (!fin2.eof()){
            std::getline(fin2, str);
            std::cout << str<<std::endl;
        }
    }
    return 0;
}
