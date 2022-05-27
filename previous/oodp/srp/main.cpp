#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;

class Journal
{
public:
    string title;
    vector<string> entries;

    Journal (const string& title): title(title) {}

    void add_entry(const string& entry)
    {
        static int count = 1;
        entries.push_back(boost::lexical_cast<string>(count++) + ": " + entry);
    }

    void save(const string& fname)
    {
        ofstream ofs(fname);
        for (auto& e: entries)
            ofs << e << endl;
    }
};

class PersistanceManager
{
public:
    static void save(const Journal j, const string& fname)
    {
        ofstream ofs(fname);
        for (auto& e: j.entries)
            ofs << e << endl;
    }

};


int main()
{
    Journal journal{"My diary"};
    journal.add_entry("Today is a beatiful day");
    journal.add_entry("Today is rainy and I am happy");

    journal.save("mydiary.txt");

    PersistanceManager pm;

    pm.save(journal, "myotherdiary.txt");

    return 0;
}

