/*
 * Word.h
 *
 *  Created on: Nov 5, 2017
 *      Author: maheshsaripalli
 */

#ifndef WORD_H_
#define WORD_H_

#include <string>
using namespace std;



/**
 * A word entry consisting of a word text and a frequency count
 * for a concordance.
 */
class Word
{
public:
    /**
     * Default constructor.
     */
    Word();

    /**
     * Constructor.
     * Create a word entry with the given text. Initialize the count to 1.
     * @param text the text of the word.
     */
    Word(string text);

    /**
     * Destructor.
     */
    virtual ~Word();

    string get_text() const;

    void inc_count();

    int get_count();

    friend bool operator!=(Word w1, Word w2);



private:
    string text;
    int count;
};

#endif /* WORD_H_ */

