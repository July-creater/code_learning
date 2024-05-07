#include <gtest/gtest.h>

#include <cstdint>

#include "binary_tree.h"

class DataStructureTest : public ::testing::Test {
 public:
  void SetUp() override {}
  DataStructure::Tree::BinaryTree<DataStructure::Tree::TreeNode<int32_t>, int32_t> binary_tree_;
};

TEST_F(DataStructureTest, InsertAndOrderTest) {
  binary_tree_.Insert(5);
  binary_tree_.Insert(3);
  binary_tree_.Insert(7);
  binary_tree_.Insert(2);
  binary_tree_.Insert(4);
  binary_tree_.Insert(6);
  binary_tree_.Insert(8);

  EXPECT_EQ(7, binary_tree_.PreOrder(binary_tree_.GetRoot()).size());
  EXPECT_EQ(7, binary_tree_.InOrder(binary_tree_.GetRoot()).size());
  EXPECT_EQ(7, binary_tree_.PostOrder(binary_tree_.GetRoot()).size());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
