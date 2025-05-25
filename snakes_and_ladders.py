
#main solving logic
def solver(board: list[list[str]], step_size, start_pos: list[int, int], end_pos: list[int, int]):
    #initial values
    blength = len(board) - 1
    bwidth = len(board[0]) - 1
    direct = "R"
    cur = start_pos
    # map ladders and snakes on the board
    ladders = find_items(board)
    snakes = find_snakes_bf(board)
    #edge case -> step < 1
    if step_size < 1:
        return cur[0] == end_pos[0] and cur[1] == end_pos[1]
    #edge case -> start point == end point
    if start_pos == end_pos:
        return True
    #main logic - while loops runs the steps while the current point is in the board
    while cur[1] <= bwidth and cur[0] <= blength:
        #execute turn by steps
        cur, direct = movement(bwidth, blength, step_size, cur, direct, end_pos)
        # check if curent point is the end point 
        if cur[0] == end_pos[0] and cur[1] == end_pos[1]:
            return True
        cur = sign_checker(cur,ladders,snakes)
    return False


#check cell for ladder start or snake start and returns the end position, or the current position if not 
def sign_checker(cur_pos,ladders,snakes):
    pos = (cur_pos[0], cur_pos[1])
    if pos in ladders:
        return list(ladders[pos])
    if pos in snakes:
        print(snakes)
        return list(snakes[pos])
    return cur_pos

#maps snakes and ladders 
def find_items(board):
    ladders = {}
    snakes = {}
    rows = len(board)
    cols = len(board[0])
    for col in range(cols):
        ladder_cells = [row for row in range(rows) if board[row][col] == "l"]
        if ladder_cells:
            ladders[(min(ladder_cells), col)] = (max(ladder_cells), col)
      #  snake_cells = [row for row in range(rows) if board[row][col] == "c"]
      #  if snake_cells:
      #      snakes[(max(snake_cells), col)] = (min(snake_cells), col)
    return ladders#, snakes


def find_snakes_bf(board):
    snake_cells = []
    rows = len(board)
    cols = len(board[0])
    for r in range(rows):
        for c in range(cols):
            if board[r][c] == "c":
                snake_cells.append((r, c))
    snakes = {}
    if snake_cells:
        head = max(snake_cells)  # or use a custom rule
        tail = min(snake_cells)
        snakes[head] = tail
    return snakes

# handels turns 
def movement(wid, leng, step, cur_pos, direct, end_pos):
    pos = cur_pos[:]  # Work on a copy
    for _ in range(step):
        if direct == "R":
            if pos[1] < wid:
                pos[1] += 1
            elif pos[0] < leng:
                pos[0] += 1
                direct = "L"
            else:
                break 
        elif direct == "L":
            if pos[1] > 0:
                pos[1] -= 1
            elif pos[0] < leng:
                pos[0] += 1
                direct = "R"
            else:
                break 
    return pos, direct



test_board = [[" ", "l", "c", " "],
              [" ", "l", " ", "c"],
              [" ", "l", " ", "c"]]


print(solver(test_board,2, [0,1],[2,2]))
