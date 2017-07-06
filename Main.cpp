// Author: JVKetchup
#include <windows.h>
#include <string>
#include "CmdGraphics.h"
#include "CmdImageArrays.h"

int main()
{
    CmdGraphics graphics;
    graphics.Clear();
    graphics.Save();
    graphics.Draw((SMALL_RECT){0, 0, 80, 80}, LOGO);
    graphics.Update();
    system("PAUSE>NUL");
    return 0;
}
