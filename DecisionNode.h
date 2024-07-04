//
// Created by allan on 7/1/2024.
//

#ifndef DECISION_TREE_DECISIONNODE_H
#define DECISION_TREE_DECISIONNODE_H

#include <cstdint>
#include <deque>
#include <map>
#include <string>
#include <vector>

class DecisionNode {
public:
  const uint32_t MAX_DEPTH = 10;

  /**
   * Default Constructor
   * @param attributeIndex -- uint32_t representing the index of the attribute
   * in the vector
   * @param nameIndex -- uint32_t representing the index of the class/name in
   * the vector
   * @param bottom -- double representing the bottom/minimum data points for
   * this node
   * @param top -- double representing the top/maximum data points for this node
   * @param depth -- uint32_t representing the depth of the node
   * @param leaf -- bool representing the node's leaf status
   * @param type -- std::string representing the type of condition
   * @param data -- 2-D vector representing the data
   */
  DecisionNode(uint32_t attributeIndex, uint32_t nameIndex, double bottom,
               double top, uint32_t depth, bool leaf, std::string type,
               std::vector<std::vector<std::string>> &data);

  ~DecisionNode() = default;

  /**
   * giniImpurity
   * Method to calculate the Gini Impurity of a split
   * @return double representing the total impurity
   */
  double giniImpurity(double, bool);

  /**
   * findSplit
   * Method to find the best split based on the impurity calculations
   */
  void findSplit();

  /**
   * determineClass
   * Method to determine the class for the leaf node
   */
  void determineClass();

  /**
   * analyze
   * Method to predict the most likely class of an individual
   * @param val -- double representing the hypothetical attribute value
   * @return std::string representing the most likely class
   */
  std::string analyze(double val);

private:
  uint32_t attributeIndex;
  uint32_t nameIndex;
  double bottom;
  double top;
  uint32_t depth;
  DecisionNode *left;
  DecisionNode *right;
  bool leaf;
  bool root;
  double split;
  std::string type;
  std::vector<std::vector<std::string>> data;
};

#endif // DECISION_TREE_DECISIONNODE_H
