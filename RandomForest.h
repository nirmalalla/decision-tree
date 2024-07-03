//
// Created by allan on 7/1/2024.
//

#ifndef DECISION_TREE_RANDOMFOREST_H
#define DECISION_TREE_RANDOMFOREST_H

#include "DecisionTree.h"
#include <deque>
#include <vector>

class RandomForest {
public:
    RandomForest();
    ~RandomForest() = default;

    void predict();
    std::vector<std::vector<std::string>> getFile(std::string& filename);
private:
    std::vector<DecisionTree> trees;
    std::vector<std::vector<std::string>> data;
    std::vector<std::string> attributes;
};


#endif //DECISION_TREE_RANDOMFOREST_H
