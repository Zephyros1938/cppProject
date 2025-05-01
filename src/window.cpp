#include "window.h"
#include <cstdarg>
#include <ncurses.h>

Window::Window(float xw, float yw, float x, float y) {
  win = newwin(LINES * yw, COLS * xw, LINES * y, COLS * x);
}

Window::Window(int xw, int yw, float x, float y) {
  win = newwin(LINES * yw, COLS * xw, LINES * y, COLS * x);
}

Window::Window(int xw, int yw, int x, int y) { win = newwin(yw, xw, y, x); }

WINDOW *Window::get() { return win; }

void Window::box() { ::box(win, 0, 0); }

void Window::refresh() { ::wrefresh(win); }

void Window::kill() { ::delwin(win); }

void Window::print(int y, int x, const char *text) {
  ::mvwprintw(win, y, x, "%s", text);
}

void Window::print(int y, int x, std::string text) {
  ::mvwprintw(win, y, x, "%s", text.c_str());
}
