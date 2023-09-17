'''

Roll No: 21467
Name : Ayush Shashikant Bulbule

Assignment No: 3
Write a python program to compute following computation on
matrix:
 a) Addition of two matrices
 b) Subtraction of two matrices
 c) Multiplication of two matrices
 d) Transpose of a matrix
'''


# Matrix Operation in python

class Matrix:
    def __init__(self):
        self.m = []

    def init_matrix(self, row, col):
        for i in range(col):
            n = []
            for j in range(row):
                n.append(int(input("Enter the element[{0}][{1}]: ".format(i, j))))
            self.m.append(n)

    # Printing Matrix
    def print_matrix(self):
        for i in range(len(self.m)):
            for j in range(len(self.m[i])):
                print(self.m[i][j], end=" ")
            print()

    # Addition
    def add(self, m1, m2):

        for i in range(len(m1.m)):
            list = []
            for j in range(len(m1.m[i])):
                list.append(m1.m[i][j] + m2.m[i][j])
            self.m.append(list)

    # Subtraction
    def sub(self, m1, m2):
        for i in range(len(m1.m)):
            list = []
            for j in range(len(m1.m[i])):
                list.append(m2.m[i][j] - m1.m[i][j])
            self.m.append(list)

    # Multiplication
    def multiply(self, m1, m2):
        print(m2.m)
        print(m2.m[0])
        for i in range(len(m1.m)):
            temp = []
            for j in range(len(m1.m[i])):
                temp.append(m1.m[i][j] * m2.m[j][i])
            self.m.append(temp)

    # Transpose
    def transpose(self,m1):
        for i in range(len(m1.m)):
            temp = []
            for j in range(len(m1.m[i])):
                temp.append(m1.m[i][j])
            self.m.append(temp)


# Main Body
if __name__ == '__main__':
    print("Enter the size of matrix 1: ")
    row = int(input("Rows: "))
    col = int(input("Column: "))
    m1 = Matrix()
    m1.init_matrix(row, col)
    m1.print_matrix()

    print("Enter the size of matrix 2: ")
    row = int(input("Rows: "))
    col = int(input("Column: "))
    m2 = Matrix()
    m2.init_matrix(row, col)
    m2.print_matrix()

end = False

while not end:
    print("\t\t Matrix Calculator")
    print("\t1. Add Matrix")
    print("\t2. Subtract Matrix")
    print("\t3. Multiply Matrix")
    print("\t4. Transpose Matrix")
    print("\t5. Exit")

    choice = int(input("\n Enter your choice: "))

    if choice == 1:
        print("Addition of Matrix is: ")
        m3 = Matrix()
        m3.add(m1, m2)
        m3.print_matrix()
        input()

    elif choice == 2:
        print("Subtraction of Matrix: ")
        m3 = Matrix()
        m3.sub(m1, m2)
        m3.print_matrix()
        input()

    elif choice == 3:
        print("Multiplication of Matrix: ")
        m3 = Matrix()
        m3.multiply(m1, m2)
        m3.print_matrix()
        input()

    elif choice == 4:
        print("Transpose of Matrix: ")
        m3 = Matrix()
        m3.transpose(m1)
        m3.print_matrix()
        input()
    elif choice == 5:
        break
    else:
        print("Wrong Choice! Try Again")

