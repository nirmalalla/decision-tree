//
// Created by allan on 6/30/2024.
//

#include "DecisionTree.h"
#include "DecisionNode.h"
#include <algorithm>
#include <limits>

DecisionTree::DecisionTree(std::string attribute,
                           std::vector<std::vector<std::string>> data) {
  this->attribute = attribute;

  attributeIndex = findIndex(data);
  std::vector<std::vector<std::string>> tmpData(data.begin() + 1, data.end());
  this->data = tmpData;

  root = new DecisionNode(attributeIndex, data[0].size() - 1, findMin(),
                          findMax(), 0, false, "root", this->data);
}

std::string DecisionTree::analyze(double val) { return root->analyze(val); }

double DecisionTree::findMin() {
  double min = std::numeric_limits<double>::max();

  for (auto cur = data.begin(); cur != data.end(); ++cur) {
    if (std::stod((*cur)[attributeIndex]) < min) {
      min = std::stod((*cur)[attributeIndex]);
    }
  }

  return min;
}

double DecisionTree::findMax() {
  double max = 0.0;

  for (auto cur = data.begin(); cur != data.end(); ++cur) {
    if (std::stod((*cur)[attributeIndex]) > max) {
      max = std::stod((*cur)[attributeIndex]);
    }
  }

  return max;
}

uint32_t
DecisionTree::findIndex(std::vector<std::vector<std::string>> fileData) {
  for (uint32_t i = 0; i < fileData[0].size(); ++i) {
    if (fileData[0][i] == attribute) {
      return i;
    }
  }

  return 0;
}
