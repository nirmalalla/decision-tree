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
  /**
   * Default Constructor
   */
  RandomForest(std::string);

  ~RandomForest() = default;

  /**
   * predict
   * Method to predict the class of an individual based on user inputs
   */
  void predict();

  /**
   * getFile
   * Method to read through .csv file and store data in a 2-D vector
   * @param filename -- Path to the .csv file
   * @return 2-D vector containing all the file data
   */
  std::vector<std::vector<std::string>> getFile(std::string &filename);

private:
  std::vector<DecisionTree> trees;
  std::vector<std::vector<std::string>> data;
  std::vector<std::string> attributes;
};

#endif // DECISION_TREE_RANDOMFOREST_H
