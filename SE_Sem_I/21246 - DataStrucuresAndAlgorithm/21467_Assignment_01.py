'''
Author: Ayush Shashikant Bulbule

Problem Statement:
In  second  year  computer engineering class, group A student’s play cricket,
group B students play badminton and group C students play football. Write a
Python program using functions to compute following: -
a)List of students who play both cricket and badminton
b)List of students who play either cricket or badminton but not both
c)Number of students who play neither cricket nor badminton
d)Number of students who play cricket and football but not badminton.
(Note-While  realizing  the  group,  duplicate  entries  should  be  avoided,
Do  not  use  SET built-in functions)

'''


# Functions to perform SET operations

# Traverse the set
def traverse(l1):
    for i in range(len(l1)):
        print(l1[i])

# Remove Duplicate
def rem_duplicate(l1):
    l2 = []
    for i in range(len(l1)):
        flag = False
        for j in range(len(l2)):
            if l1[i] == l2[j]:
                flag = True
        if not flag:
            l2.append(l1[i])
    return l2

# Function to get intersection of SET
def intersection(l1, l2):
    l3 = []
    for i in range(len(l1)):
        for j in range(len(l2)):
            if l1[i] == l2[j]:
                l3.append(l1[i])
    return l3

# Function to get union of the both set
def union(l1, l2):
    l3 = []
    for i in range(len(l1)):
        l3.append(l1[i])
    for j in range(len(l2)):
        l3.append(l2[j])
    return rem_duplicate(l3)

# Function to find out the difference of the SET
def symmetric_difference(l1, l2):
    l3 = []
    u = union(l1, l2)
    inter = intersection(l1, l2)
    for i in range(len(u)):
        flag = False
        for j in range(len(inter)):
            if u[i] == inter[j]:
                flag = True
        if not flag:
            l3.append(u[i])

    return rem_duplicate(l3)

# For finding difference
def difference(l1, l2):
    l3 = []
    for i in range(len(l1)):
        flag = False
        for j in range(len(l2)):
            if l1[i] == l2[j]:
                flag = True
        if not flag:
            print(l1[i])
            l3.append(l1[i])

    return rem_duplicate(l3)

# Taking student as input:
n = int(input("Enter the number of student you want to add: "))

# List containing al SE Students
SEStudents = []

# Adding ALL Students in list
for i in range(0, n):
    stud = input("Enter the name of student {0} :".format(i))
    SEStudents.append(stud)
print(rem_duplicate(SEStudents))
# Adding students in GroupA: Cricket
SECricket = []

nA = int(input("Enter the number of student in Group A: "))

for i in range(0, nA):
    stud = input("Enter the name of student in Group A {0} :".format(i))
    SECricket.append(stud)

# Adding students in Group B: Badminton
SEBadminton = []
nB = int(input("Enter the number of student in Group B: "))

for i in range(0, nB):
    stud = input("Enter the name of student in Group B {0} :".format(i))
    SEBadminton.append(stud)

# Adding students in Group C: Football
SEFootball = []
nC = int(input("Enter the number of student in Group C: "))

for i in range(0, nC):
    stud = input("Enter the name of student in Group C {0} :".format(i))
    SEFootball.append(stud)


# Creating  Menu
end = False

while not end:

    print('''\t\t # MENU #
        1)List of students who play both cricket and badminton 
        2)List of students who play either cricket or badminton but not both 
        3)Number of students who play neither cricket nor badminton
        4)Number of students who play cricket and football but not badminton.
        5)Exit...
    ''')

    choice = int(input("Enter your choice: "))

    if choice == 1:
        print("1")
        print(SEStudents)

        print("Students who play cricket and football both are : ")
        print(intersection(SECricket, SEBadminton))

    elif choice == 2:
        print("2")
        print(symmetric_difference(SECricket, SEBadminton))
        # print(difference(intersection(SECricket, SEBadminton), union(SECricket, SEBadminton)))
    elif choice == 3:
        print("Number of students who play neither cricket nor badminton : ")
        inter_f_b = intersection(SEFootball, SEBadminton)
        inter_f_c = intersection(SEFootball, SECricket)
        print(symmetric_difference(union(inter_f_b, inter_f_c), SEFootball))
        print(len(symmetric_difference(union(inter_f_b, inter_f_c), SEFootball)))
    elif choice == 4:
        n_circkt_footbal = difference(union(SECricket, SEFootball), SEBadminton)
        print("No of students playing circket and football but not badminton: ", len(n_circkt_footbal))
        print(n_circkt_footbal)
    elif choice == 5:
        print("Exiting.........")
        end = True
    else:
        print("Wrong Choice!!")
