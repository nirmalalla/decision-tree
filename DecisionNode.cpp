//
// Created by allan on 7/1/2024.
//

#include "DecisionNode.h"
#include <map>
#include <string>
#include <limits>

DecisionNode::DecisionNode(uint32_t attributeIndex, uint32_t nameIndex, double bottom, double top, uint32_t depth, bool leaf,
                           std::string type, std::vector<std::vector<std::string>>& data) {
    this->attributeIndex = attributeIndex;
    this->nameIndex = nameIndex;
    this->bottom = bottom;
    this->top = top;
    this->depth = depth;
    this->leaf = leaf;
    this->type = type;
    this->data = data;
    findSplit();
}

std::string DecisionNode::analyze(double val) {
    if (leaf){
        return type;
    }else{
        if (val <= split){
            return left->analyze(val);
        }else{
            return right->analyze(val);
        }
    }
}

double DecisionNode::giniImpurity(double tmpSplit, bool before) {
    std::map<std::string, uint32_t> counts;
    uint32_t total = 0;

    for (auto cur = data.begin(); cur != data.end(); ++cur) {
        double value = std::stod((*cur)[attributeIndex]);
        if (((before && value <= tmpSplit) || (!before && value > tmpSplit)) && value <= top && value >= bottom) {
            ++counts[(*cur)[nameIndex]];
            ++total;
        }
    }

    if (total == 0){
        return 0.0;
    }

    double impurity = 0.0;

    for (auto cur = counts.begin(); cur != counts.end(); ++cur){
        double proportion = static_cast<double>(cur->second) / total;
        impurity += proportion * (1 - proportion);
    }

    return impurity;
}

void DecisionNode::findSplit() {
    if (leaf){
        determineClass();
    }else{
        double minImpurity = std::numeric_limits<double>::max();
        double minSplit = 0.0;

        for (uint32_t i = 1; i < 11; ++i){
            double beforeImpurity = giniImpurity(((top - bottom) / 10) * i, true);
            double afterImpurity = giniImpurity(((top - bottom) / 10) * i, false);

            if (beforeImpurity + afterImpurity < minImpurity){
                minImpurity = beforeImpurity + afterImpurity;
                minSplit = ((top - bottom) / 10) * i;
            }

        }

        bool isLeaf = (depth + 1 == MAX_DEPTH || minImpurity == 0);
        split = minSplit;

        left = new DecisionNode(attributeIndex, nameIndex, bottom, split, depth + 1, isLeaf, "before", data);
        right = new DecisionNode(attributeIndex, nameIndex, split, top, depth + 1, isLeaf, "after", data);
    }
}

void DecisionNode::determineClass() {
    std::map<std::string, uint32_t> typeCounts;

    for (auto cur = data.begin(); cur != data.end(); ++cur){
        double value = std::stod((*cur)[attributeIndex]);

        if (value >= bottom && value <= top){
            ++typeCounts[(*cur)[nameIndex]];
        }
    }

    uint32_t max = 0;
    std::string maxType;

    for (auto cur = typeCounts.begin(); cur != typeCounts.end(); ++cur){
        if (cur->second > max){
            max = cur->second;
            maxType = cur->first;
        }
    }

    type = maxType;
}
