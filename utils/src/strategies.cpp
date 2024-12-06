#include "strategies.h"

void N(int &ix, int &iy)
{
  ix--;
}

void NE(int &ix, int &iy)
{
  ix--;
  iy++;
}

void E(int &ix, int &iy)
{
  iy++;
}

void SE(int &ix, int &iy)
{
  ix++;
  iy++;
}

void S(int &ix, int &iy)
{
  ix++;
}

void SW(int &ix, int &iy)
{
  ix++;
  iy--;
}

void W(int &ix, int &iy)
{
  iy--;
}

void NW(int &ix, int &iy)
{
  ix--;
  iy--;
}