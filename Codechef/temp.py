counter = 0
import random

def is_sorted(arr):
    for i in range(len(arr) - 1):
        if arr[i] > arr[i + 1]:
            return False
    return True

def bogo_sort(counter,arr):
    while not is_sorted(arr):
        print(arr)
        counter = counter + 1
        random.shuffle(arr)
    print(f"counter = {counter}")    
    return arr

# Example usage (only for very small arrays):

print(bogo_sort(counter,arr))
