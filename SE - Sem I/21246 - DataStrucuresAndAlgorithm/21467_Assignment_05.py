"""

Write a python program to store second year percentage of students in array. Write function
for sorting array of floating-point numbers in ascending order using 
a) Insertion sort 
b) Shell Sort and 
display top five scores
"""


def insertion_sort(arr):
    for i in range(1, len(arr)):  # 2 | 3 1 4 5
        j = i                     # 2 3 | 1 4 5

        while arr[j-1] > arr[j] and j > 0:
            # swap
            temp = arr[j-1]
            arr[j-1] = arr[j]
            arr[j] = temp

            j = j - 1

    return arr

def shell_sort(arr):
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j = j - gap

            arr[j] = temp

        gap = gap // 2

    return arr



if __name__ == '__main__':

    flag = True
    arr = []
    n = 0

    while (flag):
        print("Sorting Student Roll No. (Using Insertion and Shell Sort)")
        print("1. Insertion Sort")
        print("2. Shell Sort")
        ch = int(input("Enter Your Choice: "))

        n = int(input("Enter the Number of students: "))

        for i in range(n):
            arr.append(int(input("Enter Persentage of Student [{0}]:".format(i))))

        if ch == 1:
            print("Insertion Sort:")
            print(insertion_sort(arr))
        elif ch == 2:
            print("Shell Sort")
            print(shell_sort(arr))
        else:
            print("Wrong Choice!!")
 