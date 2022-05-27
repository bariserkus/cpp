#ifndef MYSTRING_H
#define MYSTRING_H


class MyString
{
    public:
        /** Default constructor */
        MyString(const char* = "");
        bool operator==(const MyString&);
        const void print()const;
        /** Default destructor */
        virtual ~MyString();
    private:
        char name[50];
};

#endif // MYSTRING_H
