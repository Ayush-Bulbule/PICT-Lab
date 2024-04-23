"""
b) Write a python program to store roll numbers of student array who attended training
program in sorted order. Write function for searching whether particular student attended
training program or not, using Binary search and Fibonacci search

4-B Logarithmic Search

"""


class Search:
    arr = []
    n = len(arr)

    def init_arr(self):
        self.n = int(input("Enter the Number of students: "))

        for i in range(self.n):
            self.arr.append(int(input("Enter the Roll No ({0}): ".format(i))))

    def print_arr(self):
        for i in range(self.n):
            print("{0}, ".format(self.arr[i]))

    # fibonacci search
    def fibonacci_search(self, key):
        fib1 = 0
        fib2 = 1
        fib = fib1 + fib2

        # to mark elemineted range
        flag = -1

        #to reach upto smallest fib no. >= n
        while (fib < self.n):
            fib1 = fib2
            fib2 = fib
            fib = fib1 + fib2

            #print(fib)

        while(fib > 1):
            #get on prticular index using fibonacci
            i  = min(flag+fib,self.n-1)

            if self.arr[i] == key:
                print("Student Attednded! #{0}".format(i))
                return
                
            elif(self.arr[i]>key):  #key smaller than index given by fib
                fib = fib2
                fib1 = fib2 - fib1
                fib2 = fib2-fib1 
            elif (self.arr[i]): 
                fib = fib1
                fib1 = fib2
                fib2 = fib - fib1
                flag = i

        if(fib and self.arr[flag+1] == key):
            print("Student Attednded! #{0}".format(i))
            return

        print("Student Not Attednded! ")


            

    def binary_search(self, key):
        pass


if __name__ == '__main__':
    
    
    search = Search()

    search.init_arr()

    end = False

    while not end:
        print("##### Seaching #####")
        print("\n 1. Search using Fibonacci Search.")
        print(" 2. Search using Binary Search")

        choice = int(input("\n Enter your choice: "))

        if choice == 1:
            key = int(input("Enter roll no: "))
            search.fibonacci_search(key)
        elif choice == 2:
            key = int(input("Enter roll no: "))
            search.binary_search(key)
        elif choice == 3:
            end = True
        else:
            print("Wrong Input")
