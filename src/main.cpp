#include "../include/window.h"
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <fmt/core.h>
#include <fmt/format.h>
#include <format>
#include <ncurses.h>
#include <string>

using namespace std;

int main() {
#ifdef _WIN32
  cout << "Windows platforms are not supported." << endl;
  return -1;
#endif
  initscr();
  cbreak();
  noecho();
  scrollok(stdscr, TRUE);
  // nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);

  Window win = Window(0.0f, 0.0f, 1.0f, 0.2f);
  Window exitWin = Window(0.0f, -0.33f, 0.2f, 0.2f);
  Window keyWin = Window(0.5f, -0.33f, 0.2f, 0.2f);

  refresh();

  int ch;
  bool running = true;

  while (running) {
    ch = getch();
    if (ch == 27) {
      running = false;
      break;
    }

    win.box();
    exitWin.box();
    keyWin.box();
    win.print(1, 1, "ZCurses Window");
    win.print(2, 1, format("Terminal Size: [{:4d}x{:4d}]", LINES, COLS));
    Dimensions winDimensions = win.getDimensions();
    Dimensions exitWinDimensions = exitWin.getDimensions();
    Dimensions keyWinDimensions = keyWin.getDimensions();
    win.print(3, 1,
              format("win dimensions: [{:4d}x{:4d} {:4d}x{:4d}]",
                     winDimensions.xpos, winDimensions.ypos,
                     winDimensions.width, winDimensions.height));
    win.print(4, 1,
              format("exitWin dimensions: [{:4d}x{:4d} {:4d}x{:4d}]",
                     exitWinDimensions.xpos, exitWinDimensions.ypos,
                     exitWinDimensions.width, exitWinDimensions.height));
    win.print(5, 1,
              format("keyWin dimensions: [{:4d}x{:4d} {:4d}x{:4d}]",
                     keyWinDimensions.xpos, keyWinDimensions.ypos,
                     keyWinDimensions.width, keyWinDimensions.height));
    keyWin.print(1, 1, format("Key: [{:4c}]", isprint(ch) ? ch : '?'));
    exitWin.print(1, 1, "Press ESC To Exit");
    win.refresh();
    exitWin.refresh();
    keyWin.refresh();
  }

  win.kill();
  exitWin.kill();
  keyWin.kill();
  endwin();

  return 0;
}
