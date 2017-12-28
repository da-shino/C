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
  print_board();
  return 0;
}
