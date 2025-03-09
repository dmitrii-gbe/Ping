#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>

bool IfInputAvailable() {
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    return (FD_ISSET(0, &fds));
}

void PrintCongratulations(const int left_score, const int right_score) {
    if (left_score > right_score) {
        printf(
            " #                                                                                              "
            "   ###\n");
        printf(
            " #       ###### ###### #####    #####  #        ##   #   # ###### #####     #    # # #    #  "
            "####  ###\n");
        printf(
            " #       #      #        #      #    # #       #  #   # #  #      #    #    #    # # ##   # #   "
            "   ###\n");
        printf(
            " #       #####  #####    #      #    # #      #    #   #   #####  #    #    #    # # # #  #  "
            "####   # \n");
        printf(
            " #       #      #        #      #####  #      ######   #   #      #####     # ## # # #  # #     "
            " #    \n");
        printf(
            " #       #      #        #      #      #      #    #   #   #      #   #     ##  ## # #   ## #   "
            " # ###\n");
        printf(
            " ####### ###### #        #      #      ###### #    #   #   ###### #    #    #    # # #    #  "
            "####  ###\n");
    } else if (right_score > left_score) {
        printf(
            " ######                                                                                         "
            "     ###\n");
        printf(
            " #     # #  ####  #    # #####    #####  #        ##   #   # ###### #####     #    # # #    #  "
            "####  ###\n");
        printf(
            " #     # # #    # #    #   #      #    # #       #  #   # #  #      #    #    #    # # ##   # # "
            "     ###\n");
        printf(
            " ######  # #      ######   #      #    # #      #    #   #   #####  #    #    #    # # # #  #  "
            "####   # \n");
        printf(
            " #   #   # #  ### #    #   #      #####  #      ######   #   #      #####     # ## # # #  # #   "
            "   #    \n");
        printf(
            " #    #  # #    # #    #   #      #      #      #    #   #   #      #   #     ##  ## # #   ## # "
            "   # ###\n");
        printf(
            " #     # #  ####  #    #   #      #      ###### #    #   #   ###### #    #    #    # # #    #  "
            "####  ###\n");
    }
    printf(" ####### #     # #######    ####### #     # ###### \n");
    printf("    #    #     # #          #       ##    # #     #\n");
    printf("    #    #     # #          #       # #   # #     #\n");
    printf("    #    ####### #####      #####   #  #  # #     #\n");
    printf("    #    #     # #          #       #   # # #     #\n");
    printf("    #    #     # #          #       #    ## #     #\n");
    printf("    #    #     # #######    ####### #     # ###### \n");
}

void PrintRules() {
    printf("Welcome to the terminal game 'Pong' developed by Team_45\n");
    printf("Rules of the game: \n");
    printf(
        "1. The game requires 2 players. Control keys for the 1st player: 'A' and 'Z'.\n   Controls keys for "
        "2nd players: 'K' and 'M'. If you wish to skip your turn, press 'space'\n");
    printf("2. The game continues until one player scores 21 points.\n");
    printf("3. If you decide to stop the game earlier, please press the 'Q' key.\n");
    printf("4. A player gets a point if the other player misses the ball.\n");
    printf("   Have a good game!\n");
}

int DrawScore(const int height, const int width, const int left_score, const int right_score) {
    int return_value = 0;
    if (height == 0 && width == 20) {
        printf(" L: %d ", left_score);
        if (left_score < 10) {
            for (int i = 0; i < 29; ++i) {
                printf("=");
            }
        } else {
            for (int i = 0; i < 28; ++i) {
                printf("=");
            }
        }
        return_value = 1;
    } else if (height == 0 && width == 56) {
        printf(" R: %d ", right_score);
        if (right_score < 10) {
            for (int i = 0; i < 19; ++i) {
                printf("=");
            }
        } else {
            for (int i = 0; i < 18; ++i) {
                printf("=");
            }
        }
        return_value = 2;
    }
    return return_value;
}

void DrawBorders(const int height, const int width, const int max_height, const int max_width,
                 const char horizontal_border, const char vertical_border, const int right_racket_position_y,
                 const int left_racket_position_y) {
    if (height == 0 || height == max_height - 1) {
        printf("%c", horizontal_border);
    } else if (((width == 0) &&
                ((height > left_racket_position_y + 1) || (height < left_racket_position_y - 1))) ||
               ((width == max_width - 1) &&
                ((height < right_racket_position_y - 1) || (height > right_racket_position_y + 1)))) {
        printf("%c", vertical_border);
    } else {
        printf("%c", ' ');
    }
}

int DrawBall(int height, int width, const int ball_position_x, const int ball_position_y, const char ball) {
    if (height == ball_position_y && width == ball_position_x) {
        printf("%c", ball);
        return 1;
    } else {
        return 0;
    }
}

int DrawLeftRacket(int height, int width, const int left_racket_position_y, const char racket) {
    if (height <= (left_racket_position_y + 1) && height >= (left_racket_position_y - 1) && width == 0) {
        printf("%c%c%c", '\b', racket, ' ');
        return 1;
    } else {
        return 0;
    }
}

int DrawRightRacket(int height, int width, const int max_width, const int right_racket_position_y,
                    const char racket) {
    if (height <= (right_racket_position_y + 1) && height >= (right_racket_position_y - 1) &&
        width == (max_width - 1)) {
        printf("%c%c", '\b', racket);
        return 1;
    } else {
        return 0;
    }
}

void DrawField(const int max_height, const int max_width, const int horizontal_border,
               const int vertical_border, const int right_racket_position_y, const int left_racket_position_y,
               const int ball_position_x, const int ball_position_y, const char ball, const char racket,
               const int left_score, const int right_score) {
    for (int i = 0; i < max_height; ++i) {
        for (int j = 0; j < max_width; ++j) {
            DrawBorders(i, j, max_height, max_width, horizontal_border, vertical_border,
                        right_racket_position_y, left_racket_position_y);
            int shift = 0;
            int draw_score_flag = DrawScore(i, j, left_score, right_score);
            if (draw_score_flag == 1) {
                shift = 35;
            } else if (draw_score_flag == 2) {
                shift = 25;
            }
            j += shift;
            j += (DrawBall(i, j, ball_position_x, ball_position_y, ball)) ? 1 : 0;
            j += (DrawLeftRacket(i, j, left_racket_position_y, racket)) ? 1 : 0;
            DrawRightRacket(i, j, max_width, right_racket_position_y, racket);
            if (j == max_width - 1) {
                printf("%c", '\n');
            }
        }
    }
}

void PrintSign() {
    printf("\nDesigned by cinnamoa, eijhyon, and reynoldw.\nAll rights reserved. (C) 2024.\n\n");
}

int ReadInput(const int max_height, const int left_racket_position_y, const int right_racket_position_y) {
    char input;
    int flag = 0;

    while (1) {
        if (IfInputAvailable()) {
            input = getchar();
        } else {
            flag = 7;
            break;
        }
        if ((input == 'a' || input == 'z' || input == 'q' || input == ' ')) {
            if (input == 'q') {
                flag = 0;
            } else if (input == ' ') {
                flag = 1;
            } else if (input == 'a') {
                if (left_racket_position_y - 1 >= 2) {
                    flag = 2;
                } else {
                    flag = 1;
                }
            } else if (input == 'z') {
                if (left_racket_position_y + 1 < max_height - 2) {
                    flag = 3;
                } else {
                    flag = 1;
                }
            }
            break;
        } else if ((input == 'k' || input == 'm' || input == 'q' || input == ' ')) {
            if (input == 'q') {
                flag = 0;
            } else if (input == ' ') {
                flag = 4;
            } else if (input == 'k') {
                if (right_racket_position_y - 1 >= 2) {
                    flag = 5;
                } else {
                    flag = 4;
                }
            } else if (input == 'm') {
                if (right_racket_position_y + 1 < max_height - 2) {
                    flag = 6;
                } else {
                    flag = 4;
                }
            }
            break;
        } else if (input != '\n') {
            printf("Error: You entered the wrong character. Please try again.\n");
        }
    }
    return flag;
}

void ClearField() { printf("\e[1;1H\e[2J"); }

int main() {
    int refresh_rate = 0;
    printf("Please, enter the desired refresh rate in FPS (recommended range 8 - 20):\n");
    scanf("%d", &refresh_rate);
    const int WIDTH = 82;
    const int HEIGHT = 27;

    const char horizontal_border = '=';
    const char vertical_border = ' ';

    const char ball = '*';
    const char racket = '|';

    int left_score = 0;
    int right_score = 0;

    int ball_position_x = 40;
    int ball_position_y = 12;
    int ball_move_step_x = -1;
    int ball_move_step_y = 1;
    int left_racket_position_y = 2;
    int right_racket_position_y = 22;

    int action_flag = -1;

    static struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while (left_score < 21 && right_score < 21 && action_flag != 0) {
        ClearField();

        DrawField(HEIGHT, WIDTH, horizontal_border, vertical_border, right_racket_position_y,
                  left_racket_position_y, ball_position_x, ball_position_y, ball, racket, left_score,
                  right_score);
        PrintRules();

        PrintSign();

        action_flag = ReadInput(HEIGHT, left_racket_position_y, right_racket_position_y);
        if (action_flag == 0) {
            break;
        } else if (action_flag == 2) {
            left_racket_position_y -= 1;
        } else if (action_flag == 3) {
            left_racket_position_y += 1;
        } else if (action_flag == 5) {
            right_racket_position_y -= 1;
        } else if (action_flag == 6) {
            right_racket_position_y += 1;
        }

        if (ball_position_y == HEIGHT - 2 || ball_position_y == 1) {
            ball_move_step_y *= -1;
        }
        if (ball_position_x == 1 && (ball_position_y <= left_racket_position_y + 1 &&
                                     ball_position_y >= left_racket_position_y - 1)) {
            ball_move_step_x *= -1;
        } else if (ball_position_x == WIDTH - 2 && (ball_position_y <= right_racket_position_y + 1 &&
                                                    ball_position_y >= right_racket_position_y - 1)) {
            ball_move_step_x *= -1;
        } else if (ball_position_x == 0 && (ball_position_y < left_racket_position_y + 1 ||
                                            ball_position_y > left_racket_position_y - 1)) {
            ++right_score;
            ball_position_x = rand() % (WIDTH - 15);
            ball_position_y = rand() % (HEIGHT - 4);
            int new_step_x = 1 - (rand() % 3);
            ball_move_step_x = (new_step_x == 0) ? 1 : new_step_x;
            int new_step_y = 1 - (rand() % 3);
            ball_move_step_y = (new_step_y == 0) ? 1 : new_step_y;

        } else if (ball_position_x == WIDTH - 1 && (ball_position_y < right_racket_position_y + 1 ||
                                                    ball_position_y > right_racket_position_y - 1)) {
            ++left_score;
            ball_position_x = rand() % (WIDTH - 15);
            ball_position_y = rand() % (HEIGHT - 4);
            int new_step_x = 1 - (rand() % 3);
            ball_move_step_x = (new_step_x == 0) ? 1 : new_step_x;
            int new_step_y = 1 - (rand() % 3);
            ball_move_step_y = (new_step_y == 0) ? 1 : new_step_y;
        }

        ball_position_x += ball_move_step_x;
        ball_position_y += ball_move_step_y;
        usleep((1.0 / refresh_rate) * 1e6);
    }

    ClearField();

    DrawField(HEIGHT, WIDTH, horizontal_border, vertical_border, right_racket_position_y,
              left_racket_position_y, ball_position_x, ball_position_y, ball, racket, left_score,
              right_score);
    PrintRules();

    PrintSign();

    PrintCongratulations(left_score, right_score);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}
