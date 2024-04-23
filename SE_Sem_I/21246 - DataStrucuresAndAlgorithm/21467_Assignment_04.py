"""===========================================================================
 Name        : Linear Search - Sequential & Sentinel
 Author      : Ayush Bulbule
 Version     :
 Copyright   : Your copyright notice
 Description :  a) Write a python program to store roll numbers of student in array who attended training
                program in random order. Write function for searching whether particular student attended
                training program or not, using Linear search and Sentinel search.
                Linear Seaerch
                 a) Sequential Search b) Sentinel Search
============================================================================
"""

class Search:
    arr = []
    n = len(arr)

    def __init__(self):
        pass

    def init_arr(self):
        self.n = int(input("Enter no. of students: "))

        for i in range(self.n):
            self.arr.append(
                int(input("Enter roll no of student ({0}): ".format(i))))

    def print_arr(self):
        for i in range(0, n):
            print(self.arr[i]+" ")
        print()

    # Linear Search
    def linear_search(self, key):
        for i in range(self.n):
            if (self.arr[i] == key):
                print("Student Attended training Program #{0}".format(i))
                return
        print("Student Does not Attended Training Program")

    #Sentinel Search
    def sentinel_search(self, key):

        # Store Last Element
        last = self.arr[self.n-1]

        # Store key at last
        self.arr[self.n-1] = key

        i = 0
        while (self.arr[i] != key):
            i = i+1

        # regin last element
        self.arr[self.n-1] = last

        # check if its last or not
        if (i < self.n-1 or self.arr[self.n-1] == key):
            print("Student Attended #{0}".format(i))
        else:
            print("Student did not Attented!")


if __name__ == '__main__':

    search = Search()

    search.init_arr()

    end = False

    while not end:
        print("##### Seaching #####")
        print("\n 1. Search using Linear Search.")
        print(" 2. Search using Sential Search")

        choice = int(input("\n Enter your choice: "))

        if choice == 1:
            key = int(input("Enter roll no: "))
            search.linear_search(key)
        elif choice == 2:
            key = int(input("Enter roll no: "))
            search.sentinel_search(key)
        elif choice == 3:
            end = True
        else:
            print("Wrong Input")
