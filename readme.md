# Snakes and Ladders Solver – Interview Question

## Description

Write a function to solve a Snakes and Ladders game.  
Given a board, a step value, a start point, and an end point, determine if it is possible to reach the end point from the start point by advancing in constant steps.

- **Ladders:** Stepping on a ladder moves the player directly to the top of the ladder. Ladders are always vertical.
- **Snakes:** Stepping on the head of a snake moves the player to the snake’s tail. Snakes can be vertical or diagonal.
- The start and end positions must be on the board.

## Input

- **board:** A 2D array of strings. Each cell contains:
  - `" "` (empty)
  - `"l"` (ladder)
  - `"c"` (cable/snake)
- **step:** An integer (1 to board length) representing the number of steps per move.
- **start_position:** A tuple `(row, col)` for the starting position.
- **end_position:** A tuple `(row, col)` for the required end position.

## Output

- `True` if the player can reach the end position with constant steps.
- `False` if the player cannot land exactly on the end position.
- **Note:** The player must land exactly on the endpoint after a move to win. Passing over the endpoint does not count as a win.

## Assumptions

- There is only one snake and one ladder (due to the 1-hour time limit).

## Example

```python
board = [
    [" ", "l", "c", " "],
    [" ", "l", " ", "c"],
    [" ", "l", " ", "c"]
]
step = 2
start_position = (0, 1)
end_position = (2, 2)
result = True
```

**Explanation:**  
The player starts at `(0, 1)` and moves:  
`(0,1) → (0,3) → (1,2) → (1,0) → (2,1) → (1,3) [snake] → (0,2) → (1,3) → (1,1) → (2,0) → (2,2)`

---