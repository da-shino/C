#include <iostream>
#include <string>

using namespace std;

#define NUM_MINE      10
#define BOARD_WIDTH   9
#define BOARD_HEIGHT  9

// +2 due to avoid boundary check
// available x, y range is [1,WIDTH][1,HEIGHT]
bool gIsOpen[BOARD_WIDTH+2][BOARD_HEIGHT+2];
bool gIsMine[BOARD_WIDTH+2][BOARD_HEIGHT+2];
char gNumMine[BOARD_WIDTH+2][BOARD_HEIGHT+2];

void init_board() {
  // initialize array
  for (int x=1; x < BOARD_WIDTH+1; ++x) {
    for (int y=1; y < BOARD_HEIGHT+1; ++y) {
      gIsOpen[x][y] = false;
      gIsMine[x][y] = false;
      gNumMine[x][y] = 0;
    }
  }

  // Set bomb
  for (int i=0; i < NUM_MINE; ++i) {
    int x, y;
    do {
      x = rand() % BOARD_WIDTH + 1; // [1, BOARD_WIDTH]
      y = rand() % BOARD_HEIGHT + 1; // [1, BOARD_WIDTH]
    } while (gIsMine[x][y]);
    gIsMine[x][y] = true;

    // increment
    gNumMine[x-1][y-1] += 1;
    gNumMine[x-1][y] += 1;
    gNumMine[x-1][y+1] += 1;
    gNumMine[x][y-1] += 1;
    gNumMine[x][y+1] += 1;
    gNumMine[x+1][y-1] += 1;
    gNumMine[x+1][y] += 1;
    gNumMine[x+1][y+1] += 1;
  }
}

void print_board() {
  cout << "\n abcdefghi\n";
  for (int y=1; y<=BOARD_HEIGHT; ++y) {
    cout << y;
    for (int x=1; x <= BOARD_WIDTH; ++x) {
      cout << "o";
    }
    cout << "\n";
  }
  cout << "\n";
}

int main() {
  string buffer;
  init_board();
  print_board();
  return 0;
}
