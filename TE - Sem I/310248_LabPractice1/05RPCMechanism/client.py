import xmlrpc.client
proxy = xmlrpc.client.ServerProxy('http://localhost:8000/')
while(True):
    c = int(input("1. Cube \n2. Factorial \n3. Exit"))
    if(c == 1):
        a = int(input("Enter the number: "))
        print("Cube of ", a, "is : %s" % str(proxy.factorial_rpc(a)))
    if(c == 2):
        b = int(input("Enter the number: "))
        print("Factorial of ", b, "is : %s" % str(proxy.factorial_rpc(b)))
    if(c == 3):
        break
    if(c < 0  or c > 3):
        print("Enter correct option")