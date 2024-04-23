g = 0
def print_board(elements):
    for i in range(9):
        if i % 3 == 0:
            print()
        if elements[i] == 0:
            print("_", end=" ")
        else:
            print(elements[i], end=" ")
    print()

def solvable(start):
    inv = 0
    for i in range(9):
        if start[i] <= 1:
            continue
        for j in range(i + 1, 9):
            if start[j] == 0:
                continue
            if start[i] > start[j]:
                inv += 1
    return inv % 2 == 0

def heuristic(start, goal):
    h = 0
    for i in range(1, 9):  # Exclude the empty space (0)
        start_pos = start.index(i)
        goal_pos = goal.index(i)
        h += abs(start_pos % 3 - goal_pos % 3) + abs(start_pos // 3 - goal_pos // 3)
    return h

def moveleft(start, position):
    start[position], start[position - 1] = start[position - 1], start[position]

def moveright(start, position):
    start[position], start[position + 1] = start[position + 1], start[position]

def moveup(start, position):
    start[position], start[position - 3] = start[position - 3], start[position]

def movedown(start, position):
    start[position], start[position + 3] = start[position + 3], start[position]

def movetile(start, goal):
    emptyat = start.index(0)
    row = emptyat // 3
    col = emptyat % 3
    t1, t2, t3, t4 = start[:], start[:], start[:], start[:]
    f1, f2, f3, f4 = 100, 100, 100, 100

    if col - 1 >= 0:
        moveleft(t1, emptyat)
        f1 = heuristic(t1, goal)
    if col + 1 < 3:
        moveright(t2, emptyat)
        f2 = heuristic(t2, goal)
    if row + 1 < 3:
        movedown(t3, emptyat)
        f3 = heuristic(t3, goal)
    if row - 1 >= 0:
        moveup(t4, emptyat)
        f4 = heuristic(t4, goal)

    min_heuristic = min(f1, f2, f3, f4)

    if f1 == min_heuristic:
        moveleft(start, emptyat)
    elif f2 == min_heuristic:
        moveright(start, emptyat)
    elif f3 == min_heuristic:
        movedown(start, emptyat)
    elif f4 == min_heuristic:
        moveup(start, emptyat)

def solveEight(start, goal):
    global g
    g += 1
    h = heuristic(start, goal)
    print("Chosen Heuristic Value: ", h)

    if h == 0:
        print("\n Solved in {} moves".format(g - 1))
        return

    movetile(start, goal)

    print("Updated State:")
    print_board(start)

    solveEight(start, goal)

def main():
    global g
    start = list()
    goal = list()
    print("\n Enter Initial state:(Enter 0 for empty):")
    start1 = list(map(int, input().split()))
    start2 = list(map(int, input().split()))
    start3 = list(map(int, input().split()))
    for i in start1:
        start.append(i)
    for i in start2:
        start.append(i)
    for i in start3:
        start.append(i)

    print("\n Enter goal state:(Enter 0 for empty):")
    goal1 = list(map(int, input().split()))
    goal2 = list(map(int, input().split()))
    goal3 = list(map(int, input().split()))
    for i in goal1:
        goal.append(i)
    for i in goal2:
        goal.append(i)
    for i in goal3:
        goal.append(i)

    print_board(start)

    if solvable(start):
        solveEight(start, goal)
    else:
        print("Not possible to solve")

if __name__ == '__main__': 
    main()
                                                                                                                                          
