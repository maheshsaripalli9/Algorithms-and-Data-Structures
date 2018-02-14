/*
       File name: WatteringPlans.cpp
       Author: mahesh saripalli
       Student id: 011476218
       Mail id: mahesh.saripalli@sjsu.edu

 */


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*  Main program */

int main()
{
    const int UNITS_PER_CAN = 3;
    const string INPUT_FILE_NAME = "counts.txt";
    int plant_count;
    int wtr_amt;
    int current_position;
    int cum_steps;
    int unwatered_plant;
    int near_cum_step_unit;
    int far_cum_step_unit;

    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    // Loop once for each number of plants read from the input file.


    do
    {
        input >> plant_count;

        // Stop when the number of plants is 0 or less.
        if(plant_count <= 0) return 0;


        // During each loop, simulate Plan Near and Plan Far.
        // Watering Plan Near

         current_position=0,
        	 cum_steps=0;
         unwatered_plant=1,
         near_cum_step_unit=0;
         wtr_amt=UNITS_PER_CAN;

        cout << endl;
        cout << "==========================" << endl;
        cout << " Plan Near with " << plant_count << " plants" << endl;
        cout << "==========================" << endl;
        cout << endl;

        cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
        cout << "---------  ----------  ----------  ---------------" << endl;


        while(current_position!=plant_count)// excute untill watering  all plants complete
        {

           cum_steps += (unwatered_plant - current_position) ;
           near_cum_step_unit += (unwatered_plant - current_position)*wtr_amt ;

           // Display the result in a form of table using setw(),setfill()
           cout << left    << setfill(' ') << setw(8)<< "Plant"<<unwatered_plant ;
           cout << internal<< setfill(' ') << setw(8) << cum_steps;
           cout << internal<< setfill(' ') << setw(11) << wtr_amt;
           cout << internal<< setfill(' ') << setw(15) << near_cum_step_unit <<endl;


           current_position = unwatered_plant;
           unwatered_plant++;
           wtr_amt--;


           if( current_position == plant_count) // to check the completion of wattering plants
           {
              cum_steps += current_position ;
              near_cum_step_unit += current_position*wtr_amt;

              cout << left    << setfill(' ') << setw(9)<< "FAUCET" ;
              cout << internal<< setfill(' ') << setw(8) << cum_steps;
              cout << internal<< setfill(' ') << setw(11) << wtr_amt;
              cout << internal<< setfill(' ') << setw(15) << near_cum_step_unit <<endl;
              cout<<" "<< endl;
              cout << "Plan Near: Total steps = " << cum_steps;
              cout << ", total step-units = "<<near_cum_step_unit << endl;
           }
           else if( wtr_amt==0) // checking whether can is empty or not. if empty refill at faucet
           {
              cum_steps += current_position ;
              near_cum_step_unit += current_position*wtr_amt;
              cout << left    << setfill(' ') << setw(9)<< "FAUCET" ;
              cout << internal<< setfill(' ') << setw(8) << cum_steps;
              cout << internal<< setfill(' ') << setw(11) << wtr_amt;
              cout << internal<< setfill(' ') << setw(15) << near_cum_step_unit <<endl;
              wtr_amt=3;
              current_position=0;
           }

        }






        //  Watering Plan Far

         current_position=0,
        		cum_steps=0,
				unwatered_plant=plant_count,
				far_cum_step_unit=0;
        wtr_amt=3;

        cout << endl;
        cout << "=========================" << endl;
        cout << " Plan Far with " << plant_count << " plants" << endl;
        cout << "=========================" << endl;
        cout << endl;
        cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
        cout << "---------  ----------  ----------  ---------------" << endl;


        while(current_position!=1)//execute untill watering the plants complete
        {

           cum_steps += abs(unwatered_plant - current_position) ;
           far_cum_step_unit += abs(unwatered_plant - current_position)*wtr_amt ;

           cout << left    << setfill(' ') << setw(8)<< "Plant"<< unwatered_plant ;
           cout << internal<< setfill(' ') << setw(10) << cum_steps;
           cout << internal<< setfill(' ') << setw(10) << wtr_amt;
           cout << internal<< setfill(' ') << setw(10) << far_cum_step_unit <<endl;


           current_position = unwatered_plant;
           unwatered_plant--;
           wtr_amt--;


           if( current_position == 1)// check for completion of plan
           {
              cum_steps += current_position ;
              far_cum_step_unit += current_position*wtr_amt;
              cout << left    << setfill(' ') << setw(8)<< "FAUCET" ;
              cout << internal<< setfill(' ') << setw(11) << cum_steps;
              cout << internal<< setfill(' ') << setw(10) << wtr_amt;
              cout << internal<< setfill(' ') << setw(10) << far_cum_step_unit <<endl;
              cout << endl;
              cout << "Plan Far: Total steps = " << cum_steps;
              cout << ", total step-units = "<<far_cum_step_unit << endl;

           }
           else if(wtr_amt==0 )// check if can is empty if fill at faucet
           {
              cum_steps += current_position ;
              far_cum_step_unit += current_position*wtr_amt;
              cout << left    << setfill(' ') << setw(8)<< "FAUCET" ;
              cout << internal<< setfill(' ') << setw(11) << cum_steps;
              cout << internal<< setfill(' ') << setw(10) << wtr_amt;
              cout << internal<< setfill(' ') << setw(10) << far_cum_step_unit <<endl;
              wtr_amt=3;
              current_position=0;
           }

        }

        // checking which  plan is better by comparing steps units
        cout << endl;
        cout << "*** With " << plant_count << " plants, ";
        if(near_cum_step_unit < far_cum_step_unit)
        {
           cout << "Plan Near is better with ";
           cout << (far_cum_step_unit- near_cum_step_unit)<<" fewer step-units."<<endl;
        }
        else if(near_cum_step_unit > far_cum_step_unit)
        {
           cout << "Plan far is better with ";
           cout << abs(far_cum_step_unit- near_cum_step_unit)<<" fewer step-units."<<endl;
        }
        else
        {
           cout << "Both plans have same step-units ";
        }





    } while (plant_count > 0);

    return 0;
}
