#ifndef PERSON_H
#define PERSON_H

class Person
{
    public:
        /** Default constructor */
        Person();

        /** Access Name
         * \return The current value of Name
         */
        std::string GetName();
        /** Set Name
         * \param val New value to set
         */
        void SetName(std::string val) { name = val; }

    protected:

    private:
        std::string name; //!< Member variable "Name"
};

#endif // PERSON_H
