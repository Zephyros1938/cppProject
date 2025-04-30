#include <cstdlib>
#include <cstring>
#include <fmt/base.h>
#include <fmt/format.h>
#include <iomanip>
#include <iostream>
#include <ncurses.h>
#include <string>

using namespace std;

int main() {
  initscr();
  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);

  int height = 10, width = 30, start_y = (LINES - height) / 2,
      start_x = (COLS - width) / 2;
  WINDOW *win = newwin(height, width, start_y, start_x);
  refresh();
  box(win, 0, 0);

  int ch;
  bool running = true;

  while (running) {
    ch = getch();
    // if (ch == 27) {
    //   running = false;
    //   break;
    // }

    box(win, 0, 0);
    mvwprintw(win, 1, 1, "Test");
    mvwprintw(win, 3, 1, "Press Any Key To Exit");
    mvwprintw(win, 7, 1, "Key: [%4C]", ch);
    wrefresh(win);

  }

  delwin(win);
  endwin();

  return 0;
}
