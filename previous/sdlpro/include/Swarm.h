#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace baris
{
class Swarm
{
private:
    Particle * m_pParticles;
    int lastTime;

public:
    const static int NPARTICLES = 5000;

    Swarm();
    virtual ~Swarm();
    void update(int elasped);

    const Particle * const getParticles()
    {
        return m_pParticles;
    }

protected:

};
}
#endif // SWARM_H
