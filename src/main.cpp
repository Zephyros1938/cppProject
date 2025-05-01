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

  Window win = Window(1.0f, 0.1f, 0.5f, 0.05);

  refresh();
  win.box();

  int ch;
  bool running = true;

  while (running) {
    ch = getch();
    if (ch == 27) {
      running = false;
      break;
    }

    win.box();
    win.print(1, 1, "Test");
    win.print(2, 1, "Press ESC To Exit");
    win.print(3, 1, format("Key: [{:4c}]", isprint(ch) ? ch : '?').c_str());
    win.refresh();
  }

  win.kill();
  endwin();

  return 0;
}
