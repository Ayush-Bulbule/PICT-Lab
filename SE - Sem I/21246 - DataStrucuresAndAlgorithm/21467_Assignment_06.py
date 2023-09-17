"""
Assignment no 06: Quick Sort
"""


def quicksort(arr, low, high):
    if(low < high):
        partation_pos = partition(arr, low, high)
        quicksort(arr, low, partation_pos-1)
        quicksort(arr, partation_pos+1, high)


def partition(arr, left, right):
    i = left
    j = right

    pivot = arr[right]

    while i < j:
        #i will find greater than pivot
        while i < right and arr[i] < pivot:
            i += 1

        #j will find smaller than pivot
        while j > left and arr[j] >= pivot:
            j -= 1

        #Swap i and j once greater and smaller than pivot is find out
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
    # Swap greater with pivot
    if arr[i] > pivot:
        arr[i], arr[right] = arr[right], arr[i]

    # return  the index of greater i.e partationing position
    return i

if __name__ == '__main__':

    n = int(input("Enter total no of students: "))

    arr = []

    for i in range(n):
        arr.append(int(input("Enter the roll no of student: ")))

    print("After quick sort: ")
    quicksort(arr, 0, n-1)

    print(arr)






# ---------------------------------------------------------------------------------------------
# first element as pivot
def partition1(arr, low, high):
    i = low
    j = high
    pivot = arr[low]

    while(i < j):
        # i will give element greater than pivot
        while i<high and arr[i] <= pivot:
            i = i+1
        # j will give element smaller than pivot

        while j>low and arr[j]>pivot:
            j = j-1

        if i < j:
            arr[i], arr[j] = arr[j], arr[i]  # swap
    print("i: ",arr[i])
    print("j:",arr[j])
    
    # As i>j swap with pivot
    if arr[j]<pivot:
        arr[j], arr[low] = arr[low], arr[j]
    print(pivot)

    return j  #j is partitioning position
