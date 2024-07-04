//
// Created by allan on 6/30/2024.
//

#ifndef UNTITLED_DECISIONTREE_H
#define UNTITLED_DECISIONTREE_H

#include "DecisionNode.h"
#include <deque>
#include <string>

class DecisionTree {
public:
  /**
   * Default Constructor
   */
  DecisionTree(std::string, std::vector<std::vector<std::string>>);

  ~DecisionTree() = default;

  /**
   * findMax
   * Method to find the maximum of an attribute
   * @return double representing the maximum data point
   */
  double findMax();

  /**
   * findMin
   * Method to find the minimum of an attribute
   * @return double representing the minimum data point
   */
  double findMin();

  /**
   * findIndex
   * Method to find the index of a specific attribute
   * @return uint32_t representing the index of an attribute
   */
  uint32_t findIndex(std::vector<std::vector<std::string>>);

  /**
   * analyze
   * Method to find the most likely class of an individual
   * @param val -- Double value representing an attribute
   * @return std::string representing the most likely class
   */
  std::string analyze(double val);

private:
  std::string attribute;
  DecisionNode *root;
  std::vector<std::vector<std::string>> data;
  uint32_t attributeIndex;
};

#endif // UNTITLED_DECISIONTREE_H
