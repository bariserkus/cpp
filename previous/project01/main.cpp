#include <iostream>
#include <algorithm>

using namespace std;

struct Book
{
    int m_id;
    string m_name;
    int m_quantity;
    int m_borrowed;

    Book() : m_id(0), m_name(""), m_quantity(0), m_borrowed(0) {}
    Book(int id, string name, int quantity) :
        m_id(id), m_name(name), m_quantity(quantity), m_borrowed(0) {}
    Book(int id, string name, int quantity, int borrowed) :
        m_id(id), m_name(name), m_quantity(quantity), m_borrowed(borrowed) {}

    void setBookData(int id, string name, int quantity)
    {
        m_id = id;
        m_name = name;
        m_quantity = quantity;
    }

    void setBookData(int id, string name, int quantity, int borrowed)
    {
        m_id = id;
        m_name = name;
        m_quantity = quantity;
        m_borrowed = borrowed;
    }

    bool borrowBook()
    {
        if (m_borrowed != m_quantity)
        {
            ++m_borrowed;
            return true;
        }
        else
        {
            cout << "Zero book left to borrow" << endl;
            return false;
        }
    }

    bool borrowBook(int i)
    {
        if ( (m_quantity - m_borrowed) >= i)
        {
            m_borrowed += i;
            return true;
        }
        else
        {
            cout << "Not enough books to borrow. Books left: " << i << endl;
            return false;
        }
    }

    void printBook()
    {
        cout << "ID: " << m_id
             << ", Name: " << m_name
             << ", Quantity: " << m_quantity
             << ", Borrowed: " << m_borrowed
             << ", Available: " << m_quantity - m_borrowed << endl;
    }

};

struct User
{
    int m_id;
    string m_name;
    static const int m_maxBook = 10;
    int m_borrowedBooks[m_maxBook] = {};
    int m_nBorrowed;

    User() : m_id(0), m_name(""), m_nBorrowed(0) {}
    User(int id, string name) : m_id(id), m_name(name), m_nBorrowed(0) {}

    void setUserData(int id, string name)
    {
        m_id = id;
        m_name = name;
    }

    void printUser()
    {
        cout << "User ID: " << m_id
             << ", User Name: " << m_name
             << ", Borrowed Books: ";

        if (m_nBorrowed == 0)
            cout << "None";
        else
            for (int i = 0; i < m_nBorrowed; ++i)
                cout << m_borrowedBooks[i] << " ";
        cout << endl;
    }

    void borrowBook(int id)
    {
        if (checkBookId(id))
        {
            m_borrowedBooks[m_nBorrowed] = id;
            ++m_nBorrowed;
        }
        else
            cout << "Book with ID " << id << " is already borrowed. You cannot borrow the same book" << endl;
    }

    bool checkBookId(int id)
    {
        for (int i = 0; i < m_nBorrowed; ++i)
        {
            if (id == m_borrowedBooks[i])
                return false;
        }
        return true;
    }
};

bool cmpBookID(Book& a, Book& b)
{
    return a.m_id < b.m_id;
}

bool cmpBookName(Book& a, Book& b)
{
    return a.m_name < b.m_name;
}


struct Library
{
    int m_nBooks;
    int m_nUsers;

    static const int m_nMaxBook = 10;
    Book m_books[m_nMaxBook] = {};

    static const int m_nMaxUser = 10;
    User m_users[m_nMaxUser] = {};

    Library() : m_nBooks(0), m_nUsers(0) {}

    void run()
    {
        int selection {1};
        while(selection != 10)
        {
            selection = menu();
            if (selection == 1)
                readBook();
            else if (selection == 2)
                printLibrary();
            else if (selection == 3)
                readBorrowInfo();
        }
    }

    int menu()
    {
        int selection;

        cout << "Library menu " << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Print Library" << endl;
        cout << "3. Borrow Book" << endl;
        cout << "10. END" << endl;
        cin >> selection;
        return selection;
    }


    void readBook()
    {
        int t_id;
        string t_name;
        int t_quantity;

        cout << "Enter Book Info: Book ID, Book Name (without spaces) and Total Quantity: ";
        cin >> t_id >> t_name >> t_quantity;

        addBook(t_id, t_name, t_quantity);
    }

    void readBorrowInfo()
    {
        int t_id;
        string t_name;

        cout << "Books and Users:" << endl;
        printLibrary();

        cout << "Enter User Name and Book ID: ";
        cin >> t_name >> t_id;

        borrowBook(t_name, t_id);
    }



    void addBook(const Book& b)
    {
        if (checkBookId(b.m_id))
        {
            m_books[m_nBooks] = b;
            ++m_nBooks;
        }
        else
            cout << "ID : " << b.m_id << " exists. Please change the id and try again." << endl;
    }

    void addBook(int id, string name, int quantity)
    {
        if (checkBookId(id))
        {
            m_books[m_nBooks].setBookData(id, name, quantity);
            ++m_nBooks;
        }
        else
            cout << "ID : " << id << " exists. Please change the id and try again." << endl;
    }



    void addUser(const User& u)
    {
        if (checkUserId(u.m_id))
        {
            m_users[m_nUsers] = u;
            ++m_nUsers;
        }
        else
            cout << "ID : " << u.m_id << " exists. Please change the id and try again." << endl;
    }

    void addUser(int id, string name)
    {
        if (checkUserId(id))
        {
            m_users[m_nUsers].setUserData(id, name);
            ++m_nUsers;
        }
        else
            cout << "ID : " << id << " exists. Please change the id and try again." << endl;

    }

    bool checkBookId(int id)
    {
        for (int i = 0; i < m_nBooks; ++i)
        {
            if (id == m_books[i].m_id)
                return false;
        }
        return true;
    }

    bool checkUserId(int id)
    {
        for (int i = 0; i < m_nUsers; ++i)
        {
            if (id == m_users[i].m_id)
                return false;
        }
        return true;
    }

    void printBooksByID()
    {
        sort(m_books, m_books + m_nBooks, cmpBookID);

        cout << "Books in the Library:" << endl;
        for (int i = 0; i < m_nBooks; ++i)
        {
            cout << i + 1 << ": ";
            m_books[i].printBook();
        }
        cout << endl;

    }

    void printBooksByName()
    {
        sort(m_books, m_books + m_nBooks, cmpBookName);

        cout << "Books in the Library:" << endl;
        for (int i = 0; i < m_nBooks; ++i)
        {
            cout << i + 1 << ": ";
            m_books[i].printBook();
        }
        cout << endl;

    }

    void printLibrary()
    {
        cout << "Books in the Library:" << endl;
        for (int i = 0; i < m_nBooks; ++i)
        {
            cout << i + 1 << ": ";
            m_books[i].printBook();
        }
        cout << endl;

        cout << "Users in the Library:" << endl;
        for (int i = 0; i < m_nUsers; ++i)
        {
            cout << i + 1 << ": ";
            m_users[i].printUser();
        }
        cout << endl;
    }

    bool borrowBook(string name, int id)
    {
        int i_book = findBookID(id);
        int i_user = findUserName(name);

        if (i_book == -1 || i_user == -1)
            return false;
        else
        {
            m_books[i_book].borrowBook();
            m_users[i_user].borrowBook(id);
            return true;
        }
    }

    int findBookID(int id)
    {
        for (int i = 0; i < m_nBooks; ++i)
        {
            if(id == m_books[i].m_id)
                return i;
        }
        cout << "Book ID: " << id << " is not found in the library."<< endl;
        return -1;
    }

    int findUserName(string name)
    {
        for (int i = 0; i < m_nUsers; ++i)
        {
            if(name == m_users[i].m_name)
                return i;
        }
        cout << "User Name: " << name << " is not found in the library." << endl;
        return -1;
    }

};

int main()
{
    Library l;

    l.run();


    return 0;
}
