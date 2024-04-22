#include <vector>
#include <iostream>

namespace LeeCode {
namespace Tree {

template <typename ValueType>
struct TreeNode {
  ValueType value_;
  TreeNode* left_node_;
  TreeNode* right_node_;
  TreeNode() : left_node_(nullptr), right_node_(nullptr) {}

  TreeNode(ValueType value)
      : value_(value), left_node_(nullptr), right_node_(nullptr) {}

  TreeNode(ValueType value, TreeNode* left, TreeNode* right)
      : value_(value), left_node_(left), right_node_(right) {}
};

template <typename TreeNode, typename ValueType>
class BinaryTree {
 public:
  BinaryTree() : root_(nullptr) {}

  ~BinaryTree() {}

  std::vector<ValueType> PreOrder(TreeNode* root) {
    std::vector<ValueType> res;
    PreOrderTraversal(root, &res);
    std::cout << "res size is " << res.size() << std::endl;
    return res;
  }

  std::vector<ValueType> InOrder(TreeNode* root) {
    std::vector<ValueType> res;
    InOrderTraversal(root, &res);
    std::cout << "res size is " << res.size() << std::endl;
    return res;
  }

  std::vector<ValueType> PostOrder(TreeNode* root) {
    std::vector<ValueType> res;
    PostOrderTraversal(root, &res);
    std::cout << "res size is " << res.size() << std::endl;
    return res;
  }

  void Insert(ValueType value) { root_ = InsertRec(root_, value); }

  TreeNode* GetRoot() const { return root_; }

 private:
  void PreOrderTraversal(TreeNode* cur_node,
                         std::vector<ValueType>* const value_vec) {
    if (cur_node == nullptr) {
      return;
    }
    value_vec->emplace_back(cur_node->value_);            // 中节点
    PreOrderTraversal(cur_node->left_node_, value_vec);   // 左节点
    PreOrderTraversal(cur_node->right_node_, value_vec);  // 右节点
  }

  void InOrderTraversal(TreeNode* cur_node,
                        std::vector<ValueType>* const value_vec) {
    if (cur_node == nullptr) {
      return;
    }
    InOrderTraversal(cur_node->left_node_, value_vec);   // 左节点
    value_vec->emplace_back(cur_node->value_);           // 中节点
    InOrderTraversal(cur_node->right_node_, value_vec);  // 右节点
  }

  void PostOrderTraversal(TreeNode* cur_node,
                          std::vector<ValueType>* const value_vec) {
    if (cur_node == nullptr) {
      return;
    }
    PostOrderTraversal(cur_node->left_node_, value_vec);   // 左节点
    PostOrderTraversal(cur_node->right_node_, value_vec);  // 右节点
    value_vec->emplace_back(cur_node->value_);             // 中节点
  }

  TreeNode* InsertRec(TreeNode* node, ValueType value) {
    if (node == nullptr) {
      return new TreeNode(value);
    }
    if (value < node->value_) {
      node->left_node_ = InsertRec(node->left_node_, value);
    } else if (value > node->value_) {
      node->right_node_ = InsertRec(node->right_node_, value);
    }
    return node;
  }

 private:
  TreeNode* root_;
};

}  // namespace Tree
}  // namespace LeeCode