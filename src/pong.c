#include <stdio.h>
int main(void) {
  int width_screen = 80;
  int height_screen = 25;
  int racket_1_start_y = 19;
  int racket_2_start_y = 5;
  int racket_1_default_x = 2;
  int racket_2_default_x = 77;
  int ball_start_x = 40;
  int ball_start_y = 12;
  int mp1sc_x = 57;
  int mp2sc_x = 19;
  int winscore = 21;
  int racket_1_Y = racket_1_start_y;
  int racket_2_Y = racket_2_start_y;
  int ball_X = ball_start_x;
  int ball_Y = ball_start_y;
  int ball_direction_x = -1;
  int ball_direction_y = 1;
  int points_player_1 = 0;
  int points_player_2 = 0;
  int rand_1 = 1, rand_2 = 1;
  while (1) {
    for (int y = 0; y < height_screen; ++y) {
      for (int x = 0; x < width_screen; ++x) {
        if ((x == racket_1_default_x &&
             (y == racket_1_Y - 1 || y == racket_1_Y || y == racket_1_Y + 1)) ||
            (x == racket_2_default_x &&
             (y == racket_2_Y - 1 || y == racket_2_Y || y == racket_2_Y + 1))) {
          printf("|");
        } else if (x == ball_X && y == ball_Y) {
          printf("o");
        } else if ((y == 0 && x != 0 && x <= width_screen - 6) ||
                   (y == height_screen - 1 && x != 0 &&
                    x != width_screen - 1)) {
          if (x == mp1sc_x && y == 0) {
            if (points_player_1 < 10) {
              printf("0%d", points_player_1);
            }
            if (points_player_1 >= 10) {
              printf("%d", points_player_1);
            }
          }
          if (x == mp2sc_x && y == 0) {
            if (points_player_2 < 10) {
              printf("0%d", points_player_2);
            }
            if (points_player_2 >= 10) {
              printf("%d", points_player_2);
            }
          }
          printf("-");
        } else if ((x == 0 && y != 0 && y != 25 - 1) ||
                   (x == 80 - 1 && y != 0 && y != 25 - 1) ||
                   (x == width_screen / 2)) {
          printf("|");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
    char temp;
    switch (temp = getchar()) {
    case 'a':
      ((racket_1_Y - 2) != 0) ? (racket_1_Y -= 1) : racket_1_Y;
      break;
    case 'z':
      ((racket_1_Y + 2) != height_screen - 1) ? (racket_1_Y += 1) : racket_1_Y;
      break;
    case 'k':
      ((racket_2_Y - 2) != 0) ? (racket_2_Y -= 1) : racket_2_Y;
      break;
    case 'm':
      ((racket_2_Y + 2) != height_screen - 1) ? (racket_2_Y += 1) : racket_2_Y;
      break;
    }
    if (ball_Y == 1 || ball_Y == height_screen - 2) {
      ball_direction_y = -(ball_direction_y);
    }
    if (ball_X == racket_1_default_x + 1 &&
        (ball_Y == racket_1_Y - 1 || ball_Y == racket_1_Y ||
         ball_Y == racket_1_Y + 1)) {
      ball_direction_x = -(ball_direction_x);
    }
    if (ball_X == racket_2_default_x - 1 &&
        (ball_Y == racket_2_Y - 1 || ball_Y == racket_2_Y ||
         ball_Y == racket_2_Y + 1)) {
      ball_direction_x = -(ball_direction_x);
    }
    ball_Y += ball_direction_y;
    ball_X += ball_direction_x;
    if (ball_X < 2) {
      points_player_2 += 1;
      ball_X = ball_start_x;
      ball_Y = ball_start_y;
      if (rand_1 == 1) {
        ball_direction_y = -(ball_direction_y);
        ball_direction_x = ball_direction_x + 0;
        rand_1 = 0;
      } else {
        ball_direction_y = -(ball_direction_y);
        ball_direction_x = -(ball_direction_x);
        rand_2 = 1;
      }
    }
    if (ball_X > width_screen - 3) {
      points_player_1 += 1;
      ball_X = ball_start_x;
      ball_Y = ball_start_y;
      if (rand_2 == 1) {
        ball_direction_y = -(ball_direction_y);
        ball_direction_x = ball_direction_x + 0;
        rand_2 = 0;
      } else {
        ball_direction_y = -(ball_direction_y);
        ball_direction_x = -(ball_direction_x);
        rand_1 = 1;
      }
    }
    if (points_player_1 == winscore) {
      printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             "\n\t\tПОЗДРАВЛЯЕМ!! ИГРОК ОДИН ПОБЕДИЛ СО СЧЕТОМ %d К "
             "%d.\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",
             points_player_1, points_player_2);
      break;
    } else if (points_player_2 == winscore) {
      printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             "\n\t\tПОЗДРАВЛЯЕМ!! ИГРОК ДВА ПОБЕДИЛ СО СЧЕТОМ %d К "
             "%d.\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",
             points_player_2, points_player_1);
      break;
    }
    printf("\33[0d\33[2J");
  }
}
