#ifndef STUDENT_H
#define STUDENT_H


class student
{
    public:
        student(int=22, int=33);
        virtual ~student();
        int giveidno() const;
        int givegrade() const;
        void copyinst(const student&);

    protected:

    private:
        int idno;
        int grade;
        static int countt;
};
#endif // STUDENT_H
