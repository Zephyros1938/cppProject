#pragma once
#include <ncurses.h>
#include <string>

/*
    An adapter for the ncurses.h WINDOW struct.
*/
class Window {
  WINDOW *win;

public:
  /*
    Makes a new window at (x%, y%) of the terminal.
    Size is xw% by yw% of terminal size.
  */
  Window(float xw, float yw, float x, float y);
  /*
    Makes a new window at (x%, y%) of the terminal.
    Size is xw by yw.
  */
  Window(int xw, int yw, float x, float y);
  /*
    Makes a new window at (x, y).
    Size is xw by yw.
  */
  Window(int xw, int yw, int x, int y);
  /*
    Returns the window.
  */
  WINDOW *get();
  /*
    Boxes the window.
  */
  void box();
  /*
    Refreshes the window.
  */
  void refresh();
  /*
    Deletes the window.
  */
  void kill();
  /*
    Prints text to the window at position (x,y)
  */
  void print(int y, int x, const char *text);
};
