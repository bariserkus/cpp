#ifndef INTEGER_H
#define INTEGER_H

class integ;
class integer
{
    friend int sum(const integer&, const integ&);
    public:
        /** Default constructor */
        integer(int = 0);
        /** Default destructor */
        virtual ~integer();

    protected:

    private:
        int number;
};

#endif // INTEGER_H
