#include "../include/window.h"
#include <cstdarg>
#include <format>
#include <iostream>
#include <ncurses.h>

Window::Window(float px, float py, float xw, float yw) {
  int ywi = (LINES * yw) < 3 ? 3 : (LINES * yw);
  int xwi = (COLS * xw) < 3 ? 3 : (COLS * xw);
  int pyi = py < 0.0f ? LINES * (1.0f - py) : LINES * py;
  int pxi = px < 0.0f ? COLS * (1.0f - px) : COLS * px;
  xpos = pxi;
  ypos = pyi;
  width = xwi;
  height = ywi;
  win = ::newwin(ywi, xwi, pyi, pxi);
}

Window::Window(int px, int py, float xw, float yw) {
  win = ::newwin((LINES * yw), (COLS * xw), py, px);
}

Window::Window(int px, int py, int xw, int yw) {
  win = ::newwin(yw, xw, py, px);
}

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
