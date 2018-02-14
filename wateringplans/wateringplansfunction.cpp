/*
 *Assignment 2: wateringplansfunction.cpp
 * CMPE 180-92
 * Fall 2017
 *
 *  Created on: Sep 3, 2017
 *     Author: Mahesh Saripalli
 *     Student id: 011476218
       Mail id: mahesh.saripalli@sjsu.edu
 */
#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>


using namespace std;

// Functions Declarations

int farplan(int plant_count,int UNITS_PER_CAN);           //Far plan Implementation Function
int nearplan(int plant_count, int UNITS_PER_CAN);         // Near plan Implementation Function
void printtitles(string s, int plant_count);             // Function to display titles
void betterplan(int plant_count,int near_cum_step_unit, int far_cum_step_unit); // To dertermine better plan
void printstats(string s,int unwatered_plant,int cum_steps, int water_amount, int near_cum_step_unit);// to print stats


 int main()
 {

	 const int UNITS_PER_CAN = 3;
	 const string INPUT_FILE_NAME = "counts.txt";

	 int plant_count;          //Count of plants
	 int near_cum_step_unit;  // cumulative step-units for Plan Near
	 int far_cum_step_unit;   // cumulative step-units for Plan Far

	 ifstream input;
	 input.open(INPUT_FILE_NAME);
	 if (input.fail())
	 {
		 cout << "Failed to open " << INPUT_FILE_NAME << endl;
		 return -1;
	 }

	// Loop once for each number of plants read from the input file.
	// Stop when the number of plants is 0 or less.
	// During each loop, simulate Plan Near, Plan Far and determine better plan

	 do
	 {
		 input >> plant_count;

		 if(plant_count <= 0) return 0;

		 // plan Near
		 near_cum_step_unit = nearplan(plant_count,UNITS_PER_CAN);

		 // Plan Far
		 far_cum_step_unit = farplan(plant_count,UNITS_PER_CAN);

		 // To determine better plan
		 betterplan(plant_count, near_cum_step_unit, far_cum_step_unit);

	 }while(plant_count > 0);

		 return 0;
 }



// FUNCTION DEFINATIONS

 // Plan Near

int nearplan(int plant_count,int UNITS_PER_CAN)
{
	int water_amount ;         // amount of water in the watering can
	int  unwatered_count;      // count of unwatered plants
	int plant_number;          // plant #1, #2, #3, ...
	int steps;                 // number of steps taken
	int cum_steps ;            // cumulative number of steps taken for a plan
	int cum_step_units_near;   // cumulative step-units for Plan Near
	bool trip_done;            // true if a trip is done

	//To display headings for paln Near
	printtitles("Near",plant_count);

	unwatered_count = plant_count;
	cum_steps = 0;
	cum_step_units_near = 0;

	// Loop once per trip from the faucet until all the plants are watered.
	// During each loop, fill the can, water plants according to plan,
	// and return to the faucet.

	while (unwatered_count > 0)
	{
		// Fill the can.
		water_amount = UNITS_PER_CAN;

		// Walk to the nearest unwatered plant with a full can.
		plant_number = (plant_count - unwatered_count) + 1;
		steps = plant_number;
		cum_steps += steps;
		cum_step_units_near += steps*water_amount;

		// Water plants while walking away from the faucet.
		// Loop once per plant until either the can is empty
		// or all the plants have been watered.
		// During each loop, water one plant.
		do
		{
			//Function to dispay result after watering 1 plant
			printstats( "plants",plant_number, cum_steps,  water_amount, cum_step_units_near);

			water_amount--;
			unwatered_count--;
			trip_done = (water_amount == 0) || (unwatered_count == 0);

			if (!trip_done)
			{
				// Walk away from the faucet to the next unwatered plant.
				plant_number++;
				cum_steps++;
				cum_step_units_near += water_amount;
			}
		} while (!trip_done);

		// Walk back to the faucet with an empty or partially filled can.
		steps = plant_number;
		cum_steps += steps;
		cum_step_units_near += steps*water_amount;

		// to display result after going back to faucet
		printstats("faucet",plant_number,cum_steps,  water_amount,  cum_step_units_near);
	}

		cout << endl;
		cout << "Plan Near: Total steps = " << cum_steps
				<< ", total step-units = " << cum_step_units_near << endl;
		return cum_step_units_near;
}

int farplan(int plant_count,int UNITS_PER_CAN)
{

	int water_amount ;         // amount of water in the watering can
    int  unwatered_count;      // count of unwatered plants
    int plant_number;          // plant #1, #2, #3, ...
    int steps;                 // number of steps taken
    int cum_steps ;            // cumulative number of steps taken for a plan
    int cum_step_units_far;   // cumulative step-units for Plan Far
    bool trip_done;            // true if a trip is done

    //To display headings for Far Plan
    printtitles("Far",plant_count);

    unwatered_count = plant_count;
    cum_steps = 0;
    cum_step_units_far = 0;

	// Loop once per trip from the faucet until all the plants are watered.
	// During each loop, fill the can, water plants according to plan,
	// and return to the faucet.
	while (unwatered_count > 0)
	{
		// Fill the can.
		water_amount = UNITS_PER_CAN;

		// Walk to the farthest unwatered plant with a full can.
		plant_number = unwatered_count;
		steps = plant_number;
		cum_steps += steps;
		cum_step_units_far += steps*water_amount;

		// Water plants while walking back towards the faucet.
		// Loop once per plant until either the can is empty
		// or all the plants have been watered.
		// During each loop, water one plant.
		do
		{
			printstats("plants", plant_number, cum_steps,  water_amount, cum_step_units_far);

			water_amount--;
			unwatered_count--;
			trip_done = (water_amount == 0) || (unwatered_count == 0);

			if (!trip_done)
			{
				// Walk towards the faucet to the next unwatered plant.
				plant_number--;

				cum_steps++;
				cum_step_units_far += water_amount;
			}
		} while (!trip_done);

		// Walk back to the faucet with an empty or partially filled can.
		steps = plant_number;
		cum_steps += steps;
		cum_step_units_far += steps*water_amount;

		printstats("faucet",plant_number,cum_steps,  water_amount,  cum_step_units_far);
	}

            cout << endl;
            cout << "Plan Far: Total steps = " << cum_steps
                 << ", total step-units = " << cum_step_units_far << endl;
            return cum_step_units_far;

}

void betterplan(int plant_count,int near_cum_step_unit, int far_cum_step_unit)
{
	// To decide better plan Better means fewer step-units.
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
}

void printtitles(string s, int plant_count)
{
	cout << endl;
	if(s=="Far")
	{
         cout << "==========================" << endl;
         cout << " Plan Far with " << plant_count << " plants" << endl;
         cout << "==========================" << endl;

	}
	else
	{
        cout << "==========================" << endl;
        cout << " Plan Near with " << plant_count << " plants" << endl;
        cout << "==========================" << endl;
	}
	cout << endl;

         cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
         cout << "---------  ----------  ----------  ---------------" << endl;
 }

void printstats(string s,int unwatered_plant,int cum_steps, int water_amount, int near_cum_step_unit)
{

			 if(s=="plants"){
				 cout << left    << setfill(' ') << setw(7)<< "Plant"<<unwatered_plant ;
			 }
			 else
			 {
				 cout << left    << setfill(' ')<< setw(8)<< "FAUCET" ;
			 }

	 cout << internal<< setfill(' ') << setw(8) << cum_steps;
	 cout << internal<< setfill(' ') << setw(11) << water_amount;
	 cout << internal<< setfill(' ') << setw(15) << near_cum_step_unit <<endl;
}




