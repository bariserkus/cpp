#ifndef PARTICLE_H
#define PARTICLE_H

namespace baris
{
class Particle
{
public:
    double m_x;
    double m_y;

//    double m_xspeed;
//    double m_yspeed;
private:
    double m_speed;
    double m_direction;

private:
    void init();

public:
    /** Default constructor */
    Particle();
    /** Default destructor */
    virtual ~Particle();
    void update(int interval);

protected:

};
}
#endif // PARTICLE_H
