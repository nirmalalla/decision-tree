//
// Created by allan on 7/1/2024.
//

#ifndef DECISION_TREE_DECISIONNODE_H
#define DECISION_TREE_DECISIONNODE_H

#include <string>
#include <deque>
#include <cstdint>
#include <map>

class DecisionNode {
public:
    const uint32_t MAX_DEPTH = 10;

    DecisionNode(uint32_t attributeIndex, uint32_t nameIndex, double bottom,
                 double top, uint32_t depth, bool leaf, std::string type, std::deque<std::deque<char*>>& data);
    ~DecisionNode();

    double giniImpurity(double, bool);
    void findSplit();
    void determineClass();
    std::string analyze(double val);

private:
    uint32_t attributeIndex;
    uint32_t nameIndex;
    double bottom;
    double top;
    uint32_t depth;
    DecisionNode* left;
    DecisionNode* right;
    bool leaf;
    bool root;
    double split;
    std::string type;
    std::deque<std::deque<char*>> data;
};


#endif //DECISION_TREE_DECISIONNODE_H
