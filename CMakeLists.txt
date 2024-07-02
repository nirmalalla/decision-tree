cmake_minimum_required(VERSION 3.27)
project(decision_tree)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
    DecisionTree.cpp
    DecisionTree.h
    DecisionNode.cpp
    DecisionNode.h
)

add_executable(decision_tree ${SOURCES})
