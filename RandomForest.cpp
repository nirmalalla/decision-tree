//
// Created by allan on 7/1/2024.
//

#include "RandomForest.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <vector>
#include <cstring>


RandomForest::RandomForest() {
    std::string filename = "iris.csv";
    data = loadFile(filename);
    std::deque<std::deque<char*>> tmpData(data.begin() + 1, data.end());

    uint32_t count = 1;
    for (auto cur = data[0].begin(); cur != data[0].end() - 1; ++cur){
        attributes.push_back(*cur);
        trees.push_back(DecisionTree(*cur, tmpData));
        std::cout << "Tree #" + std::to_string(count) + " trained." << std::endl;
        ++count;
    }

}

void RandomForest::predict() {
    std::deque<char*> inputs;

    for (auto cur = attributes.begin(); cur != attributes.end(); ++cur){
        char* tmp;
        std::cout << "Enter the " + *cur + ": " << std::endl;
        std::cin >> tmp;
        inputs.push_back(tmp);
    }

    std::vector<std::string> predictions;

    for (uint32_t i = 0; i < inputs.size(); ++i){
        double val = std::stod(inputs[i]);
        predictions.push_back(trees[i].analyze(val));
    }

    std::map<std::string, uint32_t> typeCounts;

    for (auto cur = predictions.begin(); cur != predictions.end(); ++cur){
        ++typeCounts[*cur];
    }

    uint32_t max = 0;
    std::string maxType;

    for (auto cur = typeCounts.begin(); cur != typeCounts.end(); ++cur){
        if (cur->second > max){
            max = cur->second;
            maxType = cur->first;
        }
    }

    std::cout << maxType;
}


std::deque<std::deque<char*>> RandomForest::loadFile(std::string& filename) {
    std::deque<std::deque<char*>> data;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::deque<char*> row;
        std::istringstream iss(line);
        std::string field;
        while (std::getline(iss, field, ',')) {
            // Allocate memory for the field
            char* fieldCopy = new char[field.size() + 1];
            std::strcpy(fieldCopy, field.c_str()); // Copy data to the allocated memory
            row.push_back(fieldCopy);
        }
        data.push_back(row);
    }

    file.close();

    return data;
}
