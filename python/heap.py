from typing import TypeVar

T = TypeVar("T")


class Heap:
    heap: list[T]
    is_max: bool

    def __init__(self, data: list[T] = None, is_max: bool = False):
        self.is_max = is_max
        self.heap = []

        if data:
            for d in data:
                self.push(d)

    def push(self, item):
        pass

    def pop(self):
        pass

    def peek(self):
        pass

    def _heapify(self, i):
        pass
