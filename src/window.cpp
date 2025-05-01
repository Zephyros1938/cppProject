#include "window.h"
#include <cstdarg>
#include <ncurses.h>

Window::Window(float xw, float yw, float x, float y) {
  int w = COLS * xw;
  int h = LINES * yw;
  int startx = (COLS * x) - (w / 2);
  int starty = (LINES * y) - (h / 2);
  win = newwin(h, w, starty, startx);
}

Window::Window(int xw, int yw, float x, float y) {
  int w = COLS * xw;
  int h = LINES * yw;
  int startx = (COLS * x) - (xw / 2);
  int starty = (LINES * y) - (yw / 2);
  win = newwin(yw, xw, starty, startx);
}

Window::Window(int xw, int yw, int x, int y) { win = newwin(yw, xw, y, x); }

WINDOW *Window::get() { return win; }

void Window::box() { ::box(win, 0, 0); }

void Window::refresh() { ::wrefresh(win); }

void Window::kill() { ::delwin(win); }

void Window::print(int y, int x, const char *text) {
  ::mvwprintw(win, y, x, "%s", text);
}
