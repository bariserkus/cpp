#ifndef STUDENT_H
#define STUDENT_H


class student
{
    public:
        /** Default constructor */
        student(int = 0, const char* = " ");
        student(const student &);
        /** Default destructor */
        virtual ~student();
        int getid() const;
        int getidref() const;
        const char* getname() const;

    protected:

    private:
        const int id;
        const int & idref;
        char * name;
};

#endif // STUDENT_H
