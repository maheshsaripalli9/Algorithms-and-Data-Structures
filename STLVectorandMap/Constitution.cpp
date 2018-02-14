/*
 * Constitution.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: maheshsaripalli
 */


//SAMPLE

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include "Word.h"
#include "WordVector.h"
#include "WordMap.h"

using namespace std;

const string INPUT_FILE_NAME = "USConstitution.txt";
const int    MAX_SEARCHES    = 100000;

/**
 * Insert words into the concordances.
 * Time this operation.
 * @param in the input stream.
 * @param v the vector concordance.
 * @param m the map concordance.
 */
void time_word_insertions(ifstream& in, WordVector& v, WordMap& m);

/**
 * Perform spot checks of some words.
 * Make sure the vector and map concordances agree with each other.
 * Throw an exception if they don't agree.
 */
void make_spot_checks(WordVector& v, WordMap& m) throw(string);

/**
 * Iterate over the vector and map concordances in parallel and
 * ensure that both agree over all the entries and in the same order.
 * Throw an exception if they don't agree.
 * @param v the vector concordance.
 * @param m the map concordance.
 */
void check_concordances(WordVector& v, WordMap& m) throw(string);

/**
 * Perform random searches of words in the concordances.
 * Time this operation.
 * Throw an exception if a word isn't found.
 * @param v the vector concordance.
 * @param m the map concordance.
 */
void time_word_searches(WordVector& v, WordMap& m) throw(string);

/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(const long n);

/**
 * The main.
 */
int main()
{
    ifstream in;
    in.open(INPUT_FILE_NAME);
    if (in.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    WordVector v;  // the concordance based on an STL vector
    WordMap    m;  // the concordance based on an STL map

    try {
        time_word_insertions(in, v, m);
        make_spot_checks(v, m);
        check_concordances(v, m);
        time_word_searches(v, m);
    }
    catch (string& msg)
    {
        cout << endl << endl << "***** " << msg << endl;
    }

    cout << endl << "Done!" << endl;
    return 0;
}

void time_word_insertions(ifstream& in, WordVector& v, WordMap& m)
{
    cout << "Timed insertions" << endl;
    cout << "----------------" << endl;

    string line;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;

    TimedContainer *tv = &v;
    TimedContainer *tm = &m;

    tv->reset_elapsed_time();
    tm->reset_elapsed_time();

    // Loop once per line of the input file.
    while (getline(in, line))
    {
        ++line_count;

        int i = 0;
        int length = line.length();
        string text = "";

        character_count += length;

        // Loop once per character of the line.
        while (i < length)
        {
        	     if (isalpha(line[i]))
        	     {

					while(isalpha(line[i]))
					{
						text += tolower(line[i]);
						i++;
					}
					word_count++;
					tv->timed_insert(text);
					tm->timed_insert(text);
					text = "";
        	     }
             i++;
        }
    }



    cout << "      Lines: " << setw(6) << commafy(line_count) << endl;
    cout << " Characters: " << setw(6) << commafy(character_count) << endl;
    cout << "      Words: " << setw(6) << commafy(word_count) << endl;
    cout << endl;
    cout << "Vector size: " << commafy(v.get_size()) << endl;
    cout << "   Map size: " << commafy(m.get_size()) << endl;
    cout << endl;
    cout << "Vector total insertion time: " << setw(6)
         << commafy(tv->get_elapsed_time()) << " usec" << endl;
    cout << "   Map total insertion time: " << setw(6)
         << commafy(tm->get_elapsed_time()) << " usec" << endl;
}

void make_spot_checks(WordVector& v, WordMap& m) throw(string)
{
    cout << endl;
    cout << "Spot checks of word counts" << endl;
    cout << "--------------------------" << endl;

    // Words to check.

    vector<string> texts = {
        "amendment", "article", "ballot", "citizens", "congress",
        "constitution", "democracy", "electors", "government", "law",
        "legislature", "people", "president", "representatives",
        "right", "trust", "united", "vice", "vote"
    };

    // Loop over each word.
    for (string text : texts)
    {
        cout << text << ": " ;
        // Search both concordances.
        Word *vword = v.search(text);
        Word *mword = m.search(text);

        int vcount = 0;
        int mcount = 0;

        // If the word exists, get the counts from both concordances.
        if (vword != nullptr) vcount = vword->get_count();
        if (mword != nullptr) mcount = mword->get_count();



        cout << "vector:";
        if (vcount > 0) cout << vcount;
        else            cout <<"(not found)";

        cout << " map:";
        if (mcount > 0) cout << mcount;
        else            cout << "(not found)";

        // Do the counts match?
        if (vcount != mcount) throw(string("Count mismatch: ") + text + " "
                                              + to_string(vcount) + ":"
                                              + to_string(mcount));
        cout << endl;
    }
}

void check_concordances(WordVector& v, WordMap& m) throw(string)
{
    cout << endl;
    cout << "Checking concordances" << endl;
    cout << "---------------------" << endl;

    vector<Word>       vdata = v.get_data();
    map<string, Word>& mdata = m.get_data();

    int vsize = vdata.size();
    int msize = mdata.size();

    if (vsize == 0) throw("Empty vector.");
    if (msize == 0) throw("Empty map.");

    // Do the number of unique words agree?
    if (vsize != msize ) throw(string("Size mismatch: ") + to_string(vsize) +
                                                 " and " + to_string(msize));

    vector<Word>::iterator      itv = vdata.begin();
    map<string, Word>::iterator itm = mdata.begin();

    // Iterate over both concordance versions in parallel.
    while (itv != vdata.end())
    {
        // Does each word agree?
        if (*itv != itm->second)
        {
            throw string(string("Data mismatch: ")
                    + itv->get_text() + ":" + to_string(itv->get_count())
                    + " and " + itm->second.get_text() + ":"
                    + to_string(itm->second.get_count()));
        }

        ++itv;
        ++itm;
    }

    cout << "Both match!" << endl;
}

void time_word_searches(WordVector& v, WordMap& m) throw(string)
{
    cout << endl;
    cout << "Timed searches (" << commafy(MAX_SEARCHES)
         << " searches)" << endl;
    cout << "--------------" << endl;

    vector<Word> vdata = v.get_data();
    int size = vdata.size();
    srand(time(NULL));

    TimedContainer *tv = &v;
    TimedContainer *tm = &m;

    tv->reset_elapsed_time();
    tm->reset_elapsed_time();

    // Loop to perform searches.
    for (int i = 1; i <= MAX_SEARCHES; i++)
    {
        // Pick a random word in the concordance.
        int index = rand()%size;
        string text = vdata[index].get_text();


        tv->timed_search(text);
        tm->timed_search(text);


    }

    cout << "Vector total search time: " << setw(6)
         << commafy(v.get_elapsed_time()) << " usec" << endl;
    cout << "   Map total search time: " << setw(6)
         << commafy(m.get_elapsed_time()) << " usec" << endl;
}

string commafy(const long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}


