//
// Created by allan on 6/30/2024.
//

#ifndef UNTITLED_DECISIONTREE_H
#define UNTITLED_DECISIONTREE_H

#include <vector>
#include <string>
#include "DecisionNode.h"

class DecisionTree {
public:
    DecisionTree(std::string, std::vector<std::vector<std::string>>);
    ~DecisionTree();

    double findMax();
    double findMin();
private:
    std::string attribute;
    DecisionNode* root;
    std::vector<std::vector<std::string>> data;
    uint32_t attributeIndex;
};


#endif //UNTITLED_DECISIONTREE_H
