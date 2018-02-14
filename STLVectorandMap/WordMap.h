/*
 * WordMap.h
 *
 *  Created on: Nov 5, 2017
 *      Author: maheshsaripalli
 */

#ifndef WORDMAP_H_
#define WORDMAP_H_


#include <map>
#include "TimedContainer.h"
#include "Word.h"

using namespace std;

/**
 * A map implementation for the concordance that inherits a timer.
 **/
class WordMap : public TimedContainer
{
public:
    /**
     * Default constructor.
     */
    WordMap();

    /**
     * Destructor.
     */
    virtual ~WordMap();

    /**
     * Insert a new word into the map,
     * or increment the count of an existing word.
     * @param text the text of the word to insert or increment.
     * @return a pointer to the word entry.
     */
    Word *insert(const string text);

    /**
     * Search the map for a word entry with the given text.
     * @param text the text of the word to find.
     * @return a pointer to the word entry if found, nullptr if not.
     */
    Word *search(const string text);
    int get_size();
    map<string, Word>& get_data();

private:
    map<string, Word> data;
};

#endif /* WORDMAP_H_ */
