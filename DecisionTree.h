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
    DecisionTree(std::string, std::string);
private:
    std::string attribute;
    std::string type;
    DecisionNode* root;
};


#endif //UNTITLED_DECISIONTREE_H
