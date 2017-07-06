// Author: JVKetchup
#include <windows.h>
#include <string>
#include "CmdGraphics.h"

CmdGraphics::CmdGraphics()
{
    cursor     = (CONSOLE_CURSOR_INFO){1, false};
    output     = (HANDLE) GetStdHandle(STD_OUTPUT_HANDLE);
    resolution = (COORD){80, 80};
    region     = (SMALL_RECT){0, 0, 80-1, 80-1};

    SetConsoleTitle("App");
    SetConsoleWindowInfo(output, true, &region);
    SetConsoleCursorInfo(output, &cursor);
    SetConsoleScreenBufferSize(output, resolution);
    WriteConsoleOutput(output,(CHAR_INFO*) buffer, resolution, (COORD){0, 0}, &region);
}

void CmdGraphics::Clear()
{
    for(int row = 0; row < resolution.Y; row++)
        for(int column = 0; column < resolution.X; column++)
        {
            buffer[row][column].Char.AsciiChar = char(219);
            buffer[row][column].Attributes = 255;
        }
    WriteConsoleOutput(output, (CHAR_INFO*) buffer, resolution, (COORD){0, 0}, &region);
}

void CmdGraphics::Save()
{
    ReadConsoleOutput(output, (CHAR_INFO*) buffer, resolution, (COORD){0, 0}, &region);
}

void CmdGraphics::Update()
{
    WriteConsoleOutput(output, (CHAR_INFO*) buffer, resolution, (COORD){0, 0}, &region);
}

void CmdGraphics::Draw(SMALL_RECT image, std::string *sprite)
{
    std::string pixel = {char(219), char(178), char(177), char(176)};
    std::string ascii = {'#', 'B', 'G', 'A', 'R', 'P', 'Y', ';', '+', 'b', 'g', 'a', 'r', 'p', 'y', '.'};
    int colorID[16]   = {240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255};

    int row, column;
    for(row = 0; row < image.Bottom; row++)
        for(column = 0; column < image.Right; column++)
            if(sprite[row].at(column) != '?' && row+image.Top >= 0 && row+image.Top < resolution.Y && column+image.Left >= 0 && column+image.Left < resolution.X)
            {
                buffer[row + image.Top][column + image.Left].Attributes = colorID[ascii.find(sprite[row].at(column))];
                buffer[row + image.Top][column + image.Left].Char.AsciiChar = pixel.at(0);
            }
}
