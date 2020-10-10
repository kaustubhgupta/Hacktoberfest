import unittest
import quick_sort

class TestQuickSort(unittest.TestCase):

  def test_sort_array_of_two(self):
    input_array = [4, 2]
    quick_sort.sort(input_array, 0, len(input_array) - 1)
    self.assertEqual(input_array, [2, 4])

  def test_sort_array_of_three(self):
    input_array = [14, 2, 7]
    quick_sort.sort(input_array, 0, len(input_array) - 1)
    self.assertEqual(input_array, [2, 7, 14])

  def test_sort_array_of_10(self):
    input_array = [14, 2, 7,44,55,421,415,4277,4237,1, 32]
    quick_sort.sort(input_array, 0, len(input_array) - 1)
    self.assertEqual(input_array, [1, 2, 7, 14, 32, 44, 55, 415, 421, 4237, 4277])

  def test_sort_array_with_duplicates(self):
    input_array = [5, 5, 4, 4, 1, 1, 38, 38, 29, 29, 29]
    quick_sort.sort(input_array, 0, len(input_array) - 1)
    self.assertEqual(input_array, [1, 1, 4, 4, 5, 5, 29, 29, 29, 38, 38])

  def test_sort_array_with_negatives(self):
    input_array = [10, -10, 5, -3, 0]
    quick_sort.sort(input_array, 0, len(input_array) - 1)
    self.assertEqual(input_array, [-10, -3, 0, 5, 10])
