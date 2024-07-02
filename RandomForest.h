//
// Created by allan on 7/1/2024.
//

#ifndef DECISION_TREE_RANDOMFOREST_H
#define DECISION_TREE_RANDOMFOREST_H

#include "DecisionTree.h"

class RandomForest {
public:
    RandomForest();
    ~RandomForest() = default;

    std::vector<std::vector<std::string>> loadFile(std::string& filename);
private:
    std::vector<DecisionTree> trees;
    std::vector<std::vector<std::string>> data;
};


#endif //DECISION_TREE_RANDOMFOREST_H
