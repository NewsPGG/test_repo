import pytest
import random

@pytest.fixture()
def random_array():
    n = random.randint(1, 100)
    arr = []
    for i in range(n):
        arr.append(random.randint(-1000, 1000))
    return arr