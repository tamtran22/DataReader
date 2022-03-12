#include <iostream>
#include <fstream>
#include <vector>
#include "DataType.h"

class DataReader{
private:
    std::ifstream fileObject;
public:
    DataReader();
    DataReader(std::string filePath);
    ~DataReader();
    void openFileObject(std::string filePath);
    void closeFileObject();
    std::vector<double> readVector(int n);
    BlockDataType<double> readBlockData(std::vector<std::string> dataNameList, int numData);
};

DataReader::DataReader(){}

DataReader::~DataReader(){}

DataReader::DataReader(std::string filePath){
    this->openFileObject(filePath);
}

void DataReader::openFileObject(std::string filePath){
    this->fileObject.open(filePath);
}

void DataReader::closeFileObject(){
    this->fileObject.close();
}

std::vector<double> DataReader::readVector(int n){
    std::vector<double> data;
    if (this->fileObject.is_open()){
        int i = 0;
        double d;
        while (!this->fileObject.eof()) {
            if (i >= n) {break;}
            this->fileObject>>d;
            data.push_back(d);
            i++;
        }
    }
    return data;
}

BlockDataType<double> DataReader::readBlockData(std::vector<std::string> dataNameList, int numData){
    BlockDataType<double> block;
    std::vector<double> dataVec;
    for(int i = 0; i<dataNameList.size(); i++){
        dataVec = this->readVector(numData);
        block.addColumn(dataNameList[i], dataVec);
    }
    return block;
}