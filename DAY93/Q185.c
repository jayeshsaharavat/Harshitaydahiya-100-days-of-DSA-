def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]  # element to be inserted
        j = i - 1
        
        # shift elements greater than key to one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        arr[j + 1] = key  # place key in correct position
    
    return arr

# Example
arr = [5, 2, 9, 1, 5, 6]
sorted_arr = insertion_sort(arr)
print("Sorted array:", sorted_arr)
