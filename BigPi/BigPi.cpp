/*
 * BIgPiNonic.cpp
 *
 *  Created on: Sep 18, 2017
 *      Author: mahesh saripalli
 */




#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAX_ITERATIONS = 100;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/**
 * Compute the cube root of a positive integer.
 * @param x where to store the result.
 * @param a the number whose cube root to compute.
 */
void cube_root(mpf_t& x, const mpf_t a);

void print(const mpf_t& pi);



/***** Add more functions as necessary. *****/

/**
 * The main.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION); // precision in bits

    mpf_t a,r,s,t,u,v,w;
    mpf_t t1,t2,t3;
    mpf_t one,two,three;
    mpf_t pi;
    mpf_init(a);
    mpf_init(r);
    mpf_init(s);
    mpf_init(t);
    mpf_init(u);
    mpf_init(v);
    mpf_init(w);
    mpf_init(t1);
    mpf_init(t2);
    mpf_init(t3);
    mpf_init(pi);



    mpf_init_set_d(one,1.0);
    mpf_init_set_d(two,2.0);
    mpf_init_set_d(three,3.0);



    // setting a,r,s

    mpf_div(a,one,three); //a= 1/3
//    mpf_out_str(NULL,10,0,a);
//    cout<<endl;

    mpf_sqrt(t1,three);
    mpf_sub(t1,t1,one);
    mpf_div(r,t1,two);  // r


    mpf_pow_ui(t1,r,3);
    mpf_sub(t1,one,t1);
    cube_root(s,t1); // s



   for(int i=0;i<100;i++)
    {

    	//t value
    	mpf_mul(t1,two,r);

    	mpf_add(t,t1,one);
//    	gmp_printf ("value a:%.Ff\n",t);
//    	cout<< endl;





    	// u value


    	mpf_add(t1,r,one);

    	mpf_mul(t2,r,r);

    	mpf_add(t1,t1,t2);

    	mpf_mul_ui(t2,r,9);

    	mpf_mul(t3,t1,t2);
    	cube_root(u,t3);






    	// v value
    	mpf_t vt,vp;
    mpf_init(vt);
    	mpf_init(vp);

    	mpf_mul(vp,t,t);
    	mpf_mul(vt,t,u);
    	mpf_add(vp,vp,vt);
    	mpf_mul(vt,u,u);
    	mpf_add(v,vp,vt);
//       	gmp_printf ("value a:%.Ff\n",v);
//    		cout<< endl;


    	// w value
    	mpf_t wt,wp;
    mpf_init(wt);
    	mpf_init(wp);

    	mpf_add(wt,one,s);
    	mpf_mul(wp,s,s);
    	mpf_add(wt,wt,wp);
    	mpf_mul_ui(wt,wt,27.0);
    	mpf_div(w,wt,v);
//    	gmp_printf ("value w:%.Ff\n",w);
//        		cout<< endl;

//
    	//a value



    	mpf_sub(t1,one,w);
    if(i==0)
    	{
    	mpf_div(t2,one,three);

    	}
    else
    {
    	mpf_pow_ui(t2,three,(2*i-1));
    }

    //	mpf_pow_ui(ap,three,);

    	mpf_mul(t3,t1,t2);
    	mpf_mul(t1,a,w);
    	mpf_add(a,t1,t3);

//    	gmp_printf ("value a:%.Ff\n",a);
//        		cout<< endl;



    	// s value


    	mpf_mul_ui(t1,u,2);
    	mpf_add(t2,t1,t);
    	mpf_mul(t3,t1,v);
    	mpf_sub(t1,one,r);
    	mpf_pow_ui(t2,t1,3);
    	mpf_div(s,t2,t3);
//    	gmp_printf ("value s:%.Ff\n",s);
//        		cout<< endl;

    	//r value

    mpf_pow_ui(t1,s,3);
    mpf_sub(t2,one,t1);
    cube_root(r,t2);
//	gmp_printf ("value r:%.Ff\n",r);
//        		cout<< endl;

    }

    mpf_div(pi,one,a);
    print(pi);



    return 0;
}


void cube_root(mpf_t& x, const mpf_t a)
{
	//xn = x(x3 + 2a)/ (2.x3 + a)

	mpf_set_d(x,1.0);
	mpf_t temp_1,temp_2,temp_4,temp_3;


	mpf_init(temp_1);
	mpf_init(temp_2);
	mpf_init(temp_3);
	mpf_init(temp_4);

	for(int i=0;i<100;i++)
	{
	mpf_pow_ui(temp_1,x,3); //b=pow(xn,3)
	mpf_mul_ui(temp_2,a,2);  //a=2q
	mpf_add(temp_3,temp_1,temp_2); // n=x3+2a
	mpf_mul(temp_3,x,temp_3); // numerator term

	mpf_mul_ui(temp_4,temp_1,2);
	mpf_add(temp_4,a,temp_4); //denomiantor

	mpf_div (x,temp_3,temp_4);

	}




}

void print(const mpf_t& pi)
{
	int count=0;
	char* pi_str;
	mp_exp_t exp;

	pi_str= mpf_get_str(NULL,&exp,BASE,PRECISION,pi);
	cout<<pi_str[count]<<".";
	count++;
	for(int i=1;i<=LINE_COUNT;i++){
		for(int j=1;j<=LINE_SIZE;j++){
			cout<<pi_str[count];
			count++;
			if((count-1)%BLOCK_SIZE==0)
				cout<<" ";
		}
		if((i)%GROUP_SIZE==0)
			cout<<endl;
		cout<<endl<<"  ";
	}
	return;
}
