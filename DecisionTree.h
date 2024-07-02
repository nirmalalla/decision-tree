//
// Created by allan on 6/30/2024.
//

#ifndef UNTITLED_DECISIONTREE_H
#define UNTITLED_DECISIONTREE_H

#include <deque>
#include <string>
#include "DecisionNode.h"

class DecisionTree {
public:
    DecisionTree(std::string, std::deque<std::deque<char*>>);
    ~DecisionTree();

    double findMax();
    double findMin();
    std::string analyze(double val);
private:
    std::string attribute;
    DecisionNode* root;
    std::deque<std::deque<char*>> data;
    uint32_t attributeIndex;
};


#endif //UNTITLED_DECISIONTREE_H
