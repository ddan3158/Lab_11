#include <iostream>
#include "student.h"
#include <fstream>
#include <vector>
#include <string>

namespace YooDaeun2693185{
    void readwriteStudentDataFile(std::istream& fin, std::ostream& fout){
        std::vector<Student> v;
        while(!fin.eof()){
            Student s;
            std::streambuf* origBuf{std::cout.rdbuf()};
            std::cout.rdbuf(nullptr);
            fin>>s;
            std::cout.rdbuf(origBuf);
            v.push_back(s);
        }
        for(const auto& vi:v)
        fout<<vi;
        
    }
}

int main(){
    using namespace YooDaeun2693185;

    std::ifstream fin{"studentData.txt"};
    if(fin.fail()){
        std::cout<<"Input file opening failed.\n";
        std::exit(1);
    }

    std::ifstream fout;
    std::string fileName;
    std::cout<<"Enter file name: ";
    std::cin>>fileName;
    fileName=fileName+".txt";
    fout.open(fileName);

    if(fout.fail()){
        std::cout<<"Output file opening failed.\n";
        std::exit(1);
    }

    readwriteStudentDataFile(fin, fout);

    fin.close();
    fout.close();
    return 0;
}