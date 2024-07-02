//
// Created by allan on 7/1/2024.
//

#ifndef DECISION_TREE_DECISIONNODE_H
#define DECISION_TREE_DECISIONNODE_H

#include <string>
#include <vector>
#include <cstdint>
#include <map>

class DecisionNode {
public:
    const uint32_t MAX_DEPTH = 10;

    DecisionNode(uint32_t attributeIndex, uint32_t nameIndex, double bottom,
                 double top, uint32_t depth, bool leaf, std::string type, std::vector<std::vector<std::string>>& data);
    ~DecisionNode();
    double giniImpurity(double, bool);
    void findSplit();

private:
    uint32_t attributeIndex;
    uint32_t nameIndex;
    double bottom;
    double top;
    uint32_t depth;
    DecisionNode* left;
    DecisionNode* right;
    bool leaf;
    double split;
    std::string type;
    std::vector<std::vector<std::string>> data;
};


#endif //DECISION_TREE_DECISIONNODE_H
