from src.Python_Homework_6.Heap_sort import heap_sort
from src.Tests.Heap_sort_Random import random_array
import pytest

@pytest.mark.parametrize(
    ["input", "output"],
    [
        ([1, 2, 3, 4, 5], [1, 2, 3, 4, 5]),
        ([9, 4, -10, 11, 2], [-10, 2, 4, 9, 11]),
        ([10, 5, 10, 16, 0, -7, -11, 94, 25], [-11, -7, 0, 5, 10, 10, 16, 25, 94])
    ],
)

def test_heap_sort(input, output):
    assert heap_sort(input) == output

def test_heap_sort_empty():
    assert heap_sort([]) == []

def test_heap_sort_negative():
    assert heap_sort([-1, -10, -19, -2, -4, -6]) == [-19, -10, -6, -4, -2, -1]

def test_heap_sort_one_element():
    assert heap_sort([1]) == 1

def test_heap_sort_random(random_array):
    assert heap_sort(random_array) == sorted(random_array)