//
// Created by allan on 7/1/2024.
//

#include "RandomForest.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

RandomForest::RandomForest() {
    std::string filename = "iris.csv";
    data = loadFile(filename);
    std::vector<std::vector<std::string>> tmpData(data.begin() + 1, data.end());

    for (auto cur = data[0].begin(); cur != data[0].end() - 1; cur++){
        trees.push_back(DecisionTree(*cur, tmpData));
    }
}



std::vector<std::vector<std::string>> RandomForest::loadFile(std::string& filename) {
    std::vector<std::vector<std::string>> data;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::istringstream iss(line);
        std::string field;
        while (std::getline(iss, field, ',')) {
            row.push_back(field);
        }
        data.push_back(row);
    }

    file.close();

    return data;
}
