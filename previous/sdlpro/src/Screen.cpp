#include "Screen.h"

namespace baris
{
Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL)
{

}

Screen::~Screen()
{
    //dtor
}

bool Screen::init()
{
    int sdl_init_var = SDL_Init(SDL_INIT_VIDEO);
    if( sdl_init_var < 0)
    {
        //cout << "SDL Init Failed." << endl;
        return false;
    }
    //cout << "SDL Init Succeeded." << endl;

    m_window =
        SDL_CreateWindow("Particle Explosion", 100, 100,
                         SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (m_window == NULL)
    {
        //cout << SDL_GetError() << endl;
        SDL_Quit();
        return false;
    }

    m_renderer =
        SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

    m_texture =
        SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
                          SDL_TEXTUREACCESS_STATIC,SCREEN_WIDTH,SCREEN_HEIGHT);

    if(m_renderer == NULL)
    {
        //cout << "Renderer cannot be created" << endl;
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    if(m_texture == NULL)
    {
        //cout << "Texture cannot be created" << endl;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    m_buffer1 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
    m_buffer2 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

    memset(m_buffer1, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
    memset(m_buffer2, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));


//    //memset(buffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
//    //memset(buffer, 0xAA, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32)/2);
//
//    memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
//
//    m_buffer[30000] = 0xFFFFFFFF;
//
//    for (int i=0; i<SCREEN_HEIGHT*SCREEN_WIDTH; i++)
//    {
//        m_buffer[i] = 0xFF00FFFF;
//    }

    return true;
}

void Screen::boxBlur()
{
    Uint32 *temp = m_buffer1;
    m_buffer1 = m_buffer2;
    m_buffer2 = temp;

    for (int y=0; y<SCREEN_HEIGHT; y++)
    {
        for (int x=0; x<SCREEN_WIDTH; x++)
        {
            int redTotal = 0;
            int greTotal = 0;
            int bluTotal = 0;
            for (int row=-1; row<=1; row++)
            {
                for (int col=-1; col<=1; col++)
                {
                    int currentX = x + col;
                    int currentY = y + row;

                    if (currentX >=0 && currentX < SCREEN_WIDTH &&
                        currentY >=0 && currentY < SCREEN_HEIGHT)
                    {
                        Uint32 color = m_buffer2[currentY*SCREEN_WIDTH + currentX];

                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;

                        redTotal += red;
                        greTotal += green;
                        bluTotal += blue;

                    }
                }
            }
            Uint8 red = redTotal/9;
            Uint8 green = greTotal/9;
            Uint8 blue = bluTotal/9;

            setPixel(x,y,red,green,blue);
        }
    }

}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
    if(x< 0 || x >= SCREEN_WIDTH || y < 0 || y>= SCREEN_HEIGHT)
    {
        return;
    }

    Uint32 color = 0;

    color += red;
    color <<=8;
    color += green;
    color <<=8;
    color += blue;
    color <<=8;
    color += 0xFF;

    //RGBA
    m_buffer1[(y * SCREEN_WIDTH) + x] = color;

}

void Screen::update()
{
    SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}


bool Screen::processEvents()
{
    SDL_Event m_event;
    while(SDL_PollEvent(&m_event))
    {
        if(m_event.type == SDL_QUIT)
        {
            return false;
        }
    }
    return true;

}

void Screen::close()
{
    delete [] m_buffer1;
    delete [] m_buffer2;
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Screen::clean()
{
    memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

}
