class MaxHeap:
    def __init__(self):
        self.heap = []

    def insert(self, value):
        self.heap.append(value)
        self._heapify_up()

    def _heapify_up(self):
        index = len(self.heap) - 1
        while index > 0:
            parent_index = (index - 1) // 2
            if self.heap[index] > self.heap[parent_index]:
                self.heap[index], self.heap[parent_index] = self.heap[parent_index], self.heap[index]
                index = parent_index
            else:
                break

    def __str__(self):

        return ', '.join(map(str, self.heap))
    
    def remove_max(self):
        if not self.heap:
            return None

        max_value = self.heap[0]

        # If there's only one element in the heap, simply remove it
        if len(self.heap) == 1:
            self.heap.pop()
            return max_value

        # Replace the root with the last element
        self.heap[0] = self.heap.pop()
        self._heapify_down(0)

        return max_value


    def _heapify_down(self, index):
        left_child_index = 2 * index + 1
        right_child_index = 2 * index + 2
        largest = index

        if (
            left_child_index < len(self.heap)
            and self.heap[left_child_index] > self.heap[largest]
        ):
            largest = left_child_index

        if (
            right_child_index < len(self.heap)
            and self.heap[right_child_index] > self.heap[largest]
        ):
            largest = right_child_index

        if largest != index:
            self.heap[index], self.heap[largest] = self.heap[largest], self.heap[index]
            self._heapify_down(largest)

    


# Construct the max heap from an array
arr = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
heap = MaxHeap()
for value in arr:
    heap.insert(value)

print(heap)


while heap.heap:
    print(heap.remove_max(), end=' ')