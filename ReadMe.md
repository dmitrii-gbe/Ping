# Pong Game - Terminal Version

## Overview

This is a simple terminal-based implementation of the classic Pong game, developed by **Team_45**. The game is designed for two players and features basic controls, score tracking, and a dynamic ball movement system. The game continues until one player reaches 21 points, and the winner is displayed with a congratulatory message.

## Features

- **Two-Player Gameplay**: Play against a friend using simple keyboard controls.
- **Dynamic Ball Movement**: The ball changes direction upon hitting the paddles or the top/bottom borders.
- **Score Tracking**: The game keeps track of each player's score and declares a winner when one player reaches 21 points.
- **Customizable Refresh Rate**: Players can set the game's refresh rate (FPS) for smoother or faster gameplay.
- **Terminal-Based Graphics**: The game is rendered entirely in the terminal using ASCII characters.

## How to Play

### Controls

- **Player 1 (Left Paddle)**:
  - Move Up: `A`
  - Move Down: `Z`
  - Skip Turn: `Space`
- **Player 2 (Right Paddle)**:
  - Move Up: `K`
  - Move Down: `M`
  - Skip Turn: `Space`
- **Quit Game**: `Q`

### Rules

1. The game requires two players.
2. The game continues until one player scores 21 points.
3. A player scores a point if the opponent misses the ball.
4. The ball's speed and direction change dynamically based on where it hits the paddles.
5. Players can quit the game early by pressing `Q`.

### Starting the Game

1. Compile the code using a C compiler (e.g., `gcc`):
   ```bash
   gcc -o pong pong.c
   ```
2. Run the executable:
   ```bash
   ./pong
   ```
3. Enter the desired refresh rate (FPS) when prompted. The recommended range is **8 - 20 FPS**.

### Gameplay

- The ball starts in the center of the screen and moves randomly.
- Use the controls to move your paddle up or down to hit the ball.
- If the ball passes your paddle, the opponent scores a point.
- The game ends when one player reaches 21 points.

## Code Structure

The code is organized into several functions:

- **`IfInputAvailable()`**: Checks if user input is available.
- **`PrintCongratulations()`**: Displays the winner's congratulatory message.
- **`PrintRules()`**: Prints the game rules and instructions.
- **`DrawScore()`**: Draws the current score on the screen.
- **`DrawBorders()`**: Draws the game borders and paddles.
- **`DrawBall()`**: Draws the ball on the screen.
- **`DrawLeftRacket()`** and **`DrawRightRacket()`**: Draw the left and right paddles.
- **`DrawField()`**: Renders the entire game field, including the ball, paddles, and borders.
- **`PrintSign()`**: Displays the developers' credits.
- **`ReadInput()`**: Reads and processes user input.
- **`ClearField()`**: Clears the terminal screen for the next frame.
- **`main()`**: The main game loop, handling game logic, rendering, and input.

## Dependencies

- The code uses standard C libraries (`stdio.h`, `stdlib.h`, `unistd.h`, etc.).
- It relies on terminal capabilities for rendering and input handling.

## Customization

- **Refresh Rate**: Adjust the refresh rate for smoother or faster gameplay.
- **Game Dimensions**: Modify the `WIDTH` and `HEIGHT` constants in the `main()` function to change the game's size.
- **Ball and Paddle Characters**: Change the `ball` and `racket` characters in the `main()` function to customize the game's appearance.

## Credits

- Developed by **cinnamoa**, **eijhyon**, and **reynoldw**.

## License

This project is open-source and available for personal and educational use. For commercial use, please contact the developers.

---

Enjoy the game! 🎮
