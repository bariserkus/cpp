#ifndef SCREEN_H
#define SCREEN_H

#include "SDL.h"

namespace baris
{

class Screen
{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 800;

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer1;
    Uint32 *m_buffer2;

public:
    /** Default constructor */
    Screen();
    /** Default destructor */
    virtual ~Screen();

    bool init();
    void close();
    bool processEvents();
    void update();
    void clean();
    void boxBlur();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

protected:

private:
};

}
#endif // SCREEN_H
