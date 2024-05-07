
#include <gtest/gtest.h>
#include <random>

#include "util/time.h"
#include "sort.h"

class AlgorithmSortTest : public ::testing::Test {
 public:
  void SetUp() override {
    sort_small_test_vec_ = {18, 2,  77, 23, 14,  22, 5,   8,   91,
                      21, 87, 37, 54, 223, 97, 220, 116, 45};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, large_vec_size_); // 生成1到large_vec_size_范围内的随机整数
    // 生成并打印large_vec_size_个随机整数
    for (int i = 0; i < large_vec_size_; ++i) {
      sort_large_test_vec_.emplace_back(dis(gen));
    }
    std::cout << "Large test date generated done! \n";
  }

  void PrintValue(const std::vector<int32_t>& test_vec) {
    for (uint32_t i = 0; i < test_vec.size(); ++i) {
      std::cout << test_vec.at(i) << ", ";
    }
    std::cout << "\n";
  }

 public:
  int32_t large_vec_size_ = 10000;
  std::vector<int32_t> sort_small_test_vec_;
  std::vector<int32_t> sort_large_test_vec_;
  Algorithm::Sort<int32_t> sorter_;
  Utils::Timer time_;
};


TEST_F(AlgorithmSortTest, BubbleSortTest) {
  std::cout << "Before BubbleSort, the vector is ";
  PrintValue(sort_small_test_vec_);
  sorter_.BubbleSort(&sort_small_test_vec_);
  std::cout << "After BubbleSort, the vector is ";
  PrintValue(sort_small_test_vec_);

  time_.StartTimer("BubbleSort");
  sorter_.BubbleSort(&sort_large_test_vec_);
  time_.StopTimer();
  time_.PrintElapsedTime();
}

TEST_F(AlgorithmSortTest, SelectionSortTest) {
  std::cout << "Before SelectionSort, the vector is ";
  PrintValue(sort_small_test_vec_);
  sorter_.SelectionSort(&sort_small_test_vec_);
  std::cout << "After SelectionSort, the vector is ";
  PrintValue(sort_small_test_vec_);

  time_.StartTimer("SelectionSort");
  sorter_.SelectionSort(&sort_large_test_vec_);
  time_.StopTimer();
  time_.PrintElapsedTime();
}

TEST_F(AlgorithmSortTest, InsertionSortTest) {
  std::cout << "Before InsertionSort, the vector is ";
  PrintValue(sort_small_test_vec_);
  sorter_.InsertionSort(&sort_small_test_vec_);
  std::cout << "After InsertionSort, the vector is ";
  PrintValue(sort_small_test_vec_);

  time_.StartTimer("InsertionSort");
  sorter_.InsertionSort(&sort_large_test_vec_);
  time_.StopTimer();
  time_.PrintElapsedTime();
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
