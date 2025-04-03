#ifndef DATA_CONTAINER_H
#define DATA_CONTAINER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

struct DataRow {
    std::string DateTime;
    double High, Open, Close, Low;
    double iMACD_1, iMACD_2, RSI, Bear, Bull, Stohastic_1, Stohastic_2;
    double Bollindg_h_h, Bollindg_l_h, Bollindg_h_m, Bollindg_l_m, Bollindg_h_l, Bollindg_l_l;
    int Digits;
};

class DataContainer {
private:
    std::vector<DataRow> data;
public:
    DataContainer() = default;
    DataContainer(const DataContainer& other) = default;
    DataContainer& operator=(const DataContainer& other) = default;
    DataContainer(DataContainer&& other) noexcept = default;
    DataContainer& operator=(DataContainer&& other) noexcept = default;
    ~DataContainer() = default;

    void loadFromFile(const std::string& filename);
    const DataRow& operator[](size_t index) const { return data[index]; }
    size_t size() const { return data.size(); }
    std::vector<DataRow>& getData() { return data; }
};

#endif
