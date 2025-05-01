#include "window.h"
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

  Window win = Window(1.0f, 0.1f, 0.0f, 0.00);
  Window win2 = Window(1.0f, 0.1f, 0.0f, 0.0);
  Window keyWin = Window(0.2f, 0.2f, 0.0f, 0.0);

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
    win2.box();
    win.print(1, 1, "Test");
    keyWin.print(2, 1, format("Key: [{:4c}]", isprint(ch) ? ch : '?'));
    win2.print(1, 1, "Press ESC To Exit");
    win.refresh();
    win2.refresh();
    keyWin.refresh();
  }

  win.kill();
  win2.kill();
  keyWin.kill();
  endwin();

  return 0;
}
