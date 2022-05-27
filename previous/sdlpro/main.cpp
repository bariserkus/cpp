#include <iostream>
#include <math.h>
#include "SDL.h"
#include "Screen.h"
#include "Swarm.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace baris;

int WinMain()
{
    srand(time(NULL));

    Screen screen;

    if(screen.init() == false)
    {
        cout << "Error initializing SDL" << endl;
    }

    Swarm swarm;

//    int maxc = 0;

    while(true)
    {
        //Update particles
        //Draw particles
        int elapsed = SDL_GetTicks();

        //screen.clean();
        swarm.update(elapsed);
		
		unsigned char green = (unsigned char)((1 + sin(elapsed *.0001)) * 128);
        unsigned char red = (unsigned char)((1 + sin(elapsed *.0002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed *.0004)) * 128);

        const Particle * const pParticles = swarm.getParticles();
        for (int i=0; i<Swarm::NPARTICLES; i++)
        {
            Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
            int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

            screen.setPixel(x,y,red,green,blue);
        }

/*        int elapsed = SDL_GetTicks();
        unsigned char red = (unsigned char)((1 + cos(elapsed *.0005)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed *.00075)) * 128);
        unsigned char blue = (unsigned char)((1 + cos(elapsed *.001)) * 128);

        //if (green> maxc) maxc = green;

        //cout << green << endl;

        for (int y=0; y < Screen::SCREEN_HEIGHT; y++)
        {
            for (int x=0; x < Screen::SCREEN_WIDTH; x++)
            {
                screen.setPixel(x,y,red,green,blue);
            }
        }*/

        //screen.setPixel(400,300,255,255,255);

        screen.boxBlur();

        // Draw the screen
        screen.update();

        //Check for messages/events
        if(screen.processEvents() == false)
        {
            break;
        }
    }

    //cout << "Max: " << maxc << endl;

    screen.close();


    return 0;
}
