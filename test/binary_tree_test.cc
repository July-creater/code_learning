#include "binary_tree.h"

#include <cstdint>
#include <gtest/gtest.h>

TEST(BinaryTreeTest, InsertAndOrderTest) {
  LeeCode::Tree::BinaryTree<LeeCode::Tree::TreeNode<int32_t>, int32_t> bt;
  bt.Insert(5);
  bt.Insert(3);
  bt.Insert(7);
  bt.Insert(2);
  bt.Insert(4);
  bt.Insert(6);
  bt.Insert(8);

  EXPECT_EQ(7, bt.PreOrder(bt.GetRoot()).size());
  EXPECT_EQ(7, bt.InOrder(bt.GetRoot()).size());
  EXPECT_EQ(7, bt.PostOrder(bt.GetRoot()).size());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
