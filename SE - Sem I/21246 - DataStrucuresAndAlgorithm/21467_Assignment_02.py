'''
Name: Ayush Shashikant Bulbule
Roll No: 21467

Problem Statement:
Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
'''


# To split the string into pats
def split_str(str):
    splited_str = []
    new_str = ''
    for i in range(len(str)):
        if str[i] == " " and str[i] != '':
            splited_str.append(new_str)
            new_str = ''
        else:
            new_str += str[i]

    if new_str != '':
        splited_str.append(new_str)

    return splited_str


# Taking String Input:
string = input("Enter a string: ")

# Testing Part
print(split_str(string))

# Creating a Menu

end = False

while not end:
    print('''\t\t # MENU #
        1) To display word with the longest length
        2) To determines the frequency of occurrence of particular character in the string
        3) To check whether given string is palindrome or not
        4) To display index of first appearance of the substring
        5) To count the occurrences of each word in a given string          
        ''')

    choice = int(input("Enter your choice :  "))

    if choice == 1:
        print(" The word with longest length: ", end=" ")
        # Word with longest length
        splited_str = split_str(string)
        print(splited_str)

        max_len = 0
        long_str = ''

        for i in range(len(splited_str)):
            # Store count of current string
            count_str = 0
            # Get the length of each string
            for j in range(len(splited_str)):
                count_str += 1

            if max_len < count_str:
                long_str = splited_str[i]

        print(long_str)

    elif choice == 2:
        letter = input("Enter a letter to find its frequency in string: ")

        frequency = 0
        for i in range(len(string)):
            if string[i] == letter:
                frequency += 1
        print("The letter {0} occurred {1} times".format(letter, frequency))

    elif choice == 3:
        str = input("Enter the string to check it is palindrome or not: ")

        str_rev = ''
        for i in range(len(str), 0,1):
            str_rev += str[i-1]
            print(i)

        print(str_rev)
        if str == str_rev:
            print("Entered string is palindrome!")

    elif choice == 4:
        sub_str = input("Enter the substring to find the first occurrence: ")

        splitted_str = split_str(string)
        for i in range(0,len(splitted_str)):
            if splitted_str[i] == sub_str:
                print(i)

    elif choice == 5:
        print("The occurence of each word in string: ")
        splitted_str = split_str(string)
        count = []

        for i in range(0,len(splitted_str)):
            count.append(0)
            for j in range(len(splitted_str)):
                if splitted_str[i] == splitted_str[j]:
                    count[len(count)-1] += 1
        print(count)

    elif choice == 6:
        print("Exiting.....")
        end = True
    else:
        print("Wrong Choice!!")
