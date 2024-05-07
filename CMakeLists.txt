cmake_minimum_required(VERSION 3.10)

project(CodeLearning)

# 设定使用的C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Eigen3 REQUIRED)

# 添加包含头文件的目录
include_directories(
    ${EIGEN3_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/structure
    ${PROJECT_SOURCE_DIR}/algorithm
    ../code_utils/include)


add_library(code_utils_libs
    ../code_utils/src/util/logger.cc
    ../code_utils/src/util/time.cc
    ../code_utils/src/util/math.cc)

# 添加选项，是否构建测试
option(BUILD_TESTS "Build the tests." ON)

# Google Test的设置
if (BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    # 创建测试可执行文件
    add_executable(DataStructureTest test/data_structure_test.cc)
    target_link_libraries(DataStructureTest ${GTEST_BOTH_LIBRARIES} code_utils_libs pthread)

    # 添加测试
    add_test(NAME DataStructureTest COMMAND DataStructureTest)

    # 创建测试可执行文件
    add_executable(AlgorithmTest test/algorithm_test.cc)
    target_link_libraries(AlgorithmTest ${GTEST_BOTH_LIBRARIES} code_utils_libs pthread)

    # 添加测试
    add_test(NAME AlgorithmTest COMMAND AlgorithmTest)
endif()
