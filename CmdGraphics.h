// Author: JVKetchup
#ifndef CMDGRAPHICS_H
#define CMDGRAPHICS_H

class CmdGraphics
{
    public:
        CmdGraphics();
        void Clear();
        void Save();
        void Update();
        void Draw(SMALL_RECT image, std::string *sprite);

    private:
        CONSOLE_CURSOR_INFO cursor;
        HANDLE output;
        COORD resolution;
        SMALL_RECT region;
        CHAR_INFO buffer[80][80];
};

#endif
