#pragma once
#include <ncurses.h>
#include <string>

struct Dimensions {
  int xpos;
  int ypos;
  int width;
  int height;
};

/*
    An adapter for the ncurses.h WINDOW struct.
*/
class Window {
  WINDOW *win;
  int xpos;
  int ypos;
  int width;
  int height;

public:
  /*
    Makes a new window at (x%, y%) of the terminal.
    Size is xw% by yw% of terminal size.
  */
  Window(float px, float py, float xw, float yw);
  /*
    Makes a new window at (x%, y%) of the terminal.
    Size is xw by yw.
  */
  Window(int px, int py, float xw, float yw);
  /*
    Makes a new window at (x, y).
    Size is xw by yw.
  */
  Window(int px, int py, int xw, int yw);
  /*
    Returns the window.
  */
  WINDOW *get();
  /*
    Returns the windows dimensions
  */
  Dimensions getDimensions() { return Dimensions{xpos, ypos, width, height}; }

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
  /*
    Prints text to the window at position (x,y)
  */
  void print(int y, int x, std::string text);
};
