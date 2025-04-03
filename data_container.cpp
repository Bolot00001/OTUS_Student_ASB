#include "data_container.h"

void DataContainer::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    std::string line;
    std::getline(file, line);  // Пропускаем заголовок

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        DataRow row;

        std::getline(ss, row.DateTime, ',');
        ss >> row.High; ss.ignore();
        ss >> row.Open; ss.ignore();
        ss >> row.Close; ss.ignore();
        ss >> row.Low; ss.ignore();
        ss >> row.iMACD_1; ss.ignore();
        ss >> row.iMACD_2; ss.ignore();
        ss >> row.RSI; ss.ignore();
        ss >> row.Bear; ss.ignore();
        ss >> row.Bull; ss.ignore();
        ss >> row.Stohastic_1; ss.ignore();
        ss >> row.Stohastic_2; ss.ignore();
        ss >> row.Bollindg_h_h; ss.ignore();
        ss >> row.Bollindg_l_h; ss.ignore();
        ss >> row.Bollindg_h_m; ss.ignore();
        ss >> row.Bollindg_l_m; ss.ignore();
        ss >> row.Bollindg_h_l; ss.ignore();
        ss >> row.Bollindg_l_l; ss.ignore();
        ss >> row.Digits;

        data.push_back(row);
    }
    file.close();
}
