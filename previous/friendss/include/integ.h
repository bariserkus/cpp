#include <integer.h>

#ifndef INTEG_H
#define INTEG_H

class integ
{
    friend int sum(const integer&, const integ&);
    public:
        /** Default constructor */
        integ(int = 0);
        /** Default destructor */
        virtual ~integ();

    protected:

    private:
        int numb;
};
#endif // INTEG_H
