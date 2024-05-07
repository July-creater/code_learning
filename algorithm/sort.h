#pragma once

#include <cstdint>
#include <iostream>
#include <vector>

namespace Algorithm {

template <typename ValueType>
class Sort {
 public:
  // 冒泡排序，每次比较相邻两个，每一轮循环下来之后，最大数会到最后一个，下次排序之后就不需要最大的数来参与就行
  void BubbleSort(std::vector<ValueType>* const value_vec) {
    if (value_vec->empty()) {
      return;
    }
    const int32_t size = value_vec->size();
    for (int32_t j = size; j > 0; --j) {
      for (int32_t i = 0; i < j - 1; ++i) {
        if (value_vec->at(i) > value_vec->at(i + 1)) {
          Swap(&value_vec->at(i), &value_vec->at(i + 1));
        }
      }
    }
  }

  // 选择排序，类似于纸牌一样，选出最小的元素，将这个元素从头开始排，或者交换
  void SelectionSort(std::vector<ValueType>* const value_vec) {
    const int32_t size = value_vec->size();
    for (int32_t j = 0; j < size - 1; ++j) {
      int32_t the_min_index = j;
      int32_t the_min = value_vec->at(j);
      // 这样循环下来，每循环一次就可以得到一个最小的值和相对应的索引
      for (int32_t i = j + 1; i < size; ++i) {
        if (the_min > value_vec->at(i)) {
          the_min_index = i;
          the_min = value_vec->at(i);
        }
      }
      Swap(&value_vec->at(the_min_index), &value_vec->at(j));
    }
  }

  // 插入排序，类似于抓牌的过程，每抓一张新的排，就会将牌插入到已经排序好的牌组中合适的位置
  void InsertionSort(std::vector<ValueType>* const value_vec) {
    
    const int32_t size = value_vec->size();
    for (int32_t i = 0; i < )
    
  }




  void MergeSort(std::vector<ValueType>* const value_vec);
  void HeapSort(std::vector<ValueType>* const value_vec);
  void ShellSort(std::vector<ValueType>* const value_vec);
  void RadixSort(std::vector<ValueType>* const value_vec);
  void BucketSort(std::vector<ValueType>* const value_vec);

 private:
  void Swap(ValueType* const a, ValueType* const b) {
    ValueType temp = *b;
    *b = *a;
    *a = temp;
  }
};

}  // namespace Algorithm