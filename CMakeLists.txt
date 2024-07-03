cmake_minimum_required(VERSION 3.27)
project(random-forest)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
    DecisionTree.cpp
    DecisionTree.h
    DecisionNode.cpp
    DecisionNode.h
    RandomForest.cpp
    RandomForest.h
        cmake-build-debug/iris.csv
)

add_executable(decision_tree ${SOURCES})
