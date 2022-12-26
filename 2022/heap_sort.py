# parent of a: (a-1)>>1
# left child of a: a<<1 + 1
# right child of a: a<<1 + 2
def max_heapify(arr, heap_size, i):
    j = i
    while j < heap_size:
        left = (j<<1) + 1
        right = (j<<1) + 2
        largest = j
        if left < heap_size and arr[left] > arr[j]:
            largest = left
        if right < heap_size and arr[right] > arr[largest]:
            largest = right
        if largest != j:
            tmp = arr[j]
            arr[j] = arr[largest]
            arr[largest] = tmp
            j = largest
        else:
            break

def build_max_heap(arr, heap_size):
    i = (heap_size>>1) - 1
    while i >= 0:
        max_heapify(arr, heap_size, i)
        i -= 1

def heap_sort(arr):
    build_max_heap(arr, len(arr))
    i = len(arr)
    while i >= 1:
        tmp = arr[0]
        arr[0] = arr[i-1]
        arr[i-1] = tmp
        max_heapify(arr, i-1, 0)
        i -= 1

if __name__ == '__main__':
    arr = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
    heap_sort(arr)
    print(arr)
