#include <iostream>
#include <vector>

template<typename T>
class BlockDataType {
private:
    std::vector<std::string> dataName;
    std::vector<std::vector<T>> dataStorage;
    int getColumnIndexFromName(std::string name);
    int getSizeOfDataStorage();
public:
    BlockDataType();
    ~BlockDataType();
    void addColumn(std::string colName, std::vector<T> col); // Add 1 data field.
    std::vector<T> getColumnByName(std::string colName);
};

template<typename T>
BlockDataType<T>::BlockDataType(){}
template<typename T>
BlockDataType<T>::~BlockDataType(){}
template<typename T>
int BlockDataType<T>::getColumnIndexFromName(std::string name){
    int id;
    for(id=this->dataName.size()-1; id>=0; id--){
        if (name == this->dataName[id]) {break;}
    }
    return id;
}
template<typename T>
int BlockDataType<T>::getSizeOfDataStorage(){
    int size = 0;
    if (this->dataStorage.size() > 0) {
        size = this->dataStorage[0].size();
    }
    return size;
}
template<typename T>
void BlockDataType<T>::addColumn(std::string colName, std::vector<T> col){
    if (this->dataName.size() != this->dataStorage.size()) {
        std::cout<<"Error: Number of dataName is different with number of dataStorage!"<<std::endl;
    // } else if (col.size() != this->getSizeOfDataStorage()) {
    //     std::cout<<"Error: Size of col is different with size of dataStorage!"<<std::endl;
    } else {
        this->dataName.push_back(colName);
        this->dataStorage.push_back(col);
    }
}
template<typename T>
std::vector<T> BlockDataType<T>::getColumnByName(std::string colName){
    std::vector<T> col;
    int id = this->getColumnIndexFromName(colName);
    if (id >= 0) {
        col = this->dataStorage[id];
    } else {
        std::cout<<"Error: "<<colName<<" doesn't exist in current dataStorage!"<<std::endl;
    }
    return col;
}