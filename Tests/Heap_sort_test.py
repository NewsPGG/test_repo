from src/Python_Homework_6/Heap_sort.py import heap_sort
import pytest

@pytest.mark.parametrize(
    ["input", "output"],
    [
        ([10, 5, -4, 0, 1, -7], [-7, -4, 0, 1, 5, 10]),
        (
            [12, 0, -9, 11, 94, -4, 6, 13, 3, -5],
            [-9, -5, -4, 0, 3, 6, 11, 12, 13, 94],
        ),
    ],
)

def test_heap_sort_basic(input, output):
    assert heap_sort(input) == output


def test_one_element():
    assert heap_sort([0]) == [0]


def test_empty():
    assert heap_sort([]) == []


def test_positive():
    assert heap_sort([5, 7, 3, 1, 10, 9, 7]) == [1, 3, 5, 7, 7, 9, 10]


def test_negative():
    assert heap_sort([-10, -2, -3, -9, -5, -3, -4]) == [-10, -9, -5, -4, -3, -3, -2]


def test_sort_numbers():
    assert heap_sort([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]