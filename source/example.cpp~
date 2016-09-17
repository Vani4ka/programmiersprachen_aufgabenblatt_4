#include "window.hpp"
#include <utility>
#include <cmath>
#include <vector>
#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  Rectangle r2{{0.4, 0.2}, 0.4, 0.5, {0.0, 0.0, 0.0}};
  Rectangle r{{0.5, 0.5}, 0.2, 0.3, {0.5,0.7,0.2}};

  std::vector<Rectangle> rects;
  rects.push_back(r);
  rects.push_back(r2);

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }

    auto t = win.get_time();
    float x1{0.5f + 0.5f * std::sin(t)};
    float y1{0.5f + 0.5f * std::cos(t)};

    float x2{0.5f + 0.5f * std::sin(2.0f*t)};
    float y2{0.5f + 0.5f * std::cos(2.0f*t)};

    float x3{0.5f + 0.5f * std::sin(t-10.f)};
    float y3{0.5f + 0.5f * std::cos(t-10.f)};

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    win.draw_line(0.1f, 0.1f, 0.8f,0.1f, 1.0,0.0,0.0);

    win.draw_line(0.0f, m.second, 0.01f, m.second, 0.0, 0.0, 0.0);
    win.draw_line(0.99f, m.second,1.0f, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0.0f, m.first, 0.01f, 0.0, 0.0, 0.0);
    win.draw_line(m.first, 0.99f,m.first, 1.0f, 0.0, 0.0, 0.0);


    Vec2 m_pos{win.mouse_position().first, win.mouse_position().second};

    for (int i = 0; i < rects.size(); ++i)
    {
      rects[i].draw(win);
      if(rects[i].is_inside(m_pos)) {
        rects[i].setColor({0.0,0.0,1.0});
      }
      else rects[i].resetColor();
    }

    win.update();
  }

  return 0;
}
