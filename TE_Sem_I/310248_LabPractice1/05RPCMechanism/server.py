from xmlrpc.server import SimpleXMLRPCServer

def cube(n):
    cb = n * n * n 
    return cb

def factorial(n):
    fact = 1
    if(n < 0):
        return -1
    for i in range(1, n + 1):
        fact = fact * i
    return fact

port = 8000

server = SimpleXMLRPCServer(("localhost", port), logRequests = False)
server.register_function(factorial, 'factorial_rpc')
server.register_function(cube, 'cube_rpc')

try:
    print("Server started and is listening on Port ", port)
    server.serve_forever()
except :
    print("Server Shutting Down")