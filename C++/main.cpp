#include <iostream>
#include <vector>
#include "DataReader.h"

template<typename T>
void print(std::vector<T> vec){
    for(int i=0; i<vec.size(); i++){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    DataReader reader("testdata.txt");
    std::vector<std::string> dataNameList;
    dataNameList.push_back("x");
    dataNameList.push_back("y");
    dataNameList.push_back("z");
    BlockDataType<double> block = reader.readBlockData(dataNameList, 5);
    for(int i = 0; i<dataNameList.size(); i++){
        std::cout<<dataNameList[i]<<" = ";
        print<double>(block.getColumnByName(dataNameList[i]));
    }
    return 0;
}