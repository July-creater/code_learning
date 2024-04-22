cmake_minimum_required(VERSION 3.10)

project(BinaryTreeProject)

# 设定使用的C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加包含头文件的目录
include_directories(data_struct)

# 添加选项，是否构建测试
option(BUILD_TESTS "Build the tests." ON)

# Google Test的设置
if (BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    # 创建测试可执行文件
    add_executable(BinaryTreeTest test/binary_tree_test.cc)
    target_link_libraries(BinaryTreeTest ${GTEST_BOTH_LIBRARIES} pthread)

    # 添加测试
    add_test(NAME BinaryTreeTest COMMAND BinaryTreeTest)
endif()
