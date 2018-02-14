#ifndef DATAGENERATOR_H_
#define DATAGENERATOR_H_

#include <string>
#include <vector>
#include "Element.h"

using namespace std;

/**
 * Abstract base class of the data generator subclasses.
 */
class DataGenerator
{
public:
    DataGenerator(string name);
    virtual ~DataGenerator();

    virtual string get_name();
    virtual void generate_data(vector<Element>& data, int size) = 0;

private:
    string name;
};

#endif /* DATAGENERATOR_H_ */
