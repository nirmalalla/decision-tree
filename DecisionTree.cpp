//
// Created by allan on 6/30/2024.
//

#include "DecisionTree.h"
#include "DecisionNode.h"
#include <algorithm>

DecisionTree::DecisionTree(std::string attribute, std::vector<std::vector<std::string>> data) {
    this->attribute = attribute;
    this->data = data;

    auto attributeIndexIterator = std::find(data[0].begin(), data[0].end(), attribute);
    attributeIndex = std::distance(data[0].begin(), attributeIndexIterator);

    root = new DecisionNode(attributeIndex, data[0].size() - 1, findMin(), findMax(), 0, false, "root", data);
}

DecisionTree::~DecisionTree() {
    delete root;
}

double DecisionTree::findMin() {
    double min = 0.0;

    for (auto cur = data.begin(); cur != data.end(); ++cur){
        if (std::stod((*cur)[attributeIndex]) < min){
            min = std::stod((*cur)[attributeIndex]);
        }
    }

    return min;
}

double DecisionTree::findMax() {
    double max = 0.0;

    for (auto cur = data.begin(); cur != data.end(); ++cur){
        if (std::stod((*cur)[attributeIndex]) > max){
            max = std::stod((*cur)[attributeIndex]);
        }
    }

    return max;
}

