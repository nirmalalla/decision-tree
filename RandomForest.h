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
    std::deque<std::deque<char*>> loadFile(std::string& filename);
private:
    std::vector<DecisionTree> trees;
    std::deque<std::deque<char*>> data;
    std::vector<std::string> attributes;
};


#endif //DECISION_TREE_RANDOMFOREST_H
