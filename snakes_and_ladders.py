
"""
Determines if the player can reach the end position from the start position
on a Snakes and Ladders board using constant step size.

Args:
    board (list[list[str]]): 2D board with " ", "l", or "c" in each cell.
    step_size (int): Number of steps to move each turn.
    start_pos (tuple): (row, col) starting position.
    end_pos (tuple): (row, col) target position.

Returns:
    bool: True if the player can land exactly on the end position, False otherwise.
"""
def solver(board: list[list[str]], step_size:int, start_pos: tuple, end_pos: tuple):
    #initial values
    blength = len(board) - 1
    bwidth = len(board[0]) - 1
    direct = "R"
    cur = start_pos
    # map ladders and snakes on the board
    ladders = find_ladders(board)
    snakes = find_snakes_bf(board)
    #edge case -> step < 1
    if step_size < 1:
        return cur == end_pos
    #edge case -> start point == end point
    if start_pos == end_pos:
        return True
    #main logic - while loops runs the steps while the current point is in the board
    while cur[1] <= bwidth and cur[0] <= blength:
        #execute turn by steps
        cur, direct = movement(bwidth, blength, step_size, cur, direct)
        #check and execute snake and ladder logic
        cur = sign_checker(cur,ladders,snakes)
        # check if curent point is the end point 
        if cur == end_pos:
            return True
    return False

"""
Checks if the current position is the start of a ladder or snake.
If so, returns the destination; otherwise, returns the current position.

Args:
    cur_pos (tuple): Current (row, col) position.
    ladders (dict): Mapping of ladder starts to ends.
    snakes (dict): Mapping of snake heads to tails.

Returns:
    tuple: New position after applying ladder/snake logic.
"""
def sign_checker(cur_pos,ladders,snakes):
    if cur_pos in ladders:
        return ladders[cur_pos]
    if cur_pos in snakes:
        return snakes[cur_pos]
    return cur_pos

"""
Finds all ladders on the board. Ladders are vertical and mapped from bottom to top.

Args:
    board (list[list[str]]): 2D board.

Returns:
    dict: Mapping from ladder start (row, col) to ladder end (row, col).
"""
def find_ladders(board):
    ladders = {}
    rows = len(board)
    cols = len(board[0])
    for col in range(cols):
        ladder_cells = [row for row in range(rows) if board[row][col] == "l"]
        if ladder_cells:
            ladders[(min(ladder_cells), col)] = (max(ladder_cells), col)
    return ladders

"""
Finds the snake on the board by brute force.
Assumes only one snake exists. Maps the highest 'c' cell to the lowest.
Should be replaced by a dfs/bfs search algortithm 
Args:
    board (list[list[str]]): 2D board.

Returns:
    dict: Mapping from snake head (row, col) to snake tail (row, col).
"""
def find_snakes_bf(board):
    snake_cells = []
    rows = len(board)
    cols = len(board[0])
    for row in range(rows):
        for col in range(cols):
            if board[row][col] == "c":
                snake_cells.append((row, col))
    snakes = {}
    if snake_cells:
        head = max(snake_cells)  
        tail = min(snake_cells)
        snakes[head] = tail
    return snakes

# handels turns 
"""
Moves the player across the board in a snaking pattern for a given number of steps.

Args:
    wid (int): Board width (max column index).
    leng (int): Board length (max row index).
    step (int): Number of steps to move.
    cur_pos (tuple): Current (row, col) position.
    direct (str): Current direction ("R" for right, "L" for left).

Returns:
    tuple: (new (row, col) position, new direction)
"""
def movement(wid, leng, step, cur_pos, direct):
    row, col = cur_pos
    for _ in range(step):
        if direct == "R":
            if col < wid:
                col += 1
            else:
                row += 1
                direct = "L"
                # Move left if possible, else go out of bounds
                if row > leng:
                    break
        elif direct == "L":
            if col > 0:
                col -= 1
            else:
                row += 1
                direct = "R"
                # Move right if possible, else go out of bounds
                if row > leng:
                    break
    return (row, col), direct
