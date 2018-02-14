#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAX_ITERATIONS = 100;
const int PLACES     	= 100000;    	// desired decimal places
const int PRECISION  	= PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE   	= 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;            	// print digits in blocks
const int LINE_SIZE  = 100;           	// digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;             	// line grouping size

/**
 * Compute the cube root of a positive integer.
 * @param x where to store the result.
 * @param a the number whose cube root to compute.
 */
void cube_root(mpf_t& x, const mpf_t a);

/**
 *To compute the pi value using mpir library upto precision on thousand decimals
 *@param pi(call by refernce value) returns the pi value
 *
 */
void nonic(mpf_t& pi);

/**
 * To compute u value used for iteration value
 * u=(9*r(1+r+r^2))^1/3
 * @param u(call by refernce value) return the value of u after iteration
 * @param r constant mpf variable taken from previous iteration value
 *
 */
void u_value(mpf_t &u, const mpf_t r);

/**
 * To compute v value used for iteration value
 * v=t^2 +t*u + u^2
 * @param v(call by refernce value) return the value of v after iteration
 * @param t constant mpf variable taken from previous iteration value
 * @param u constant mpf variable taken from previous iteration value
 *
 */
void v_value(mpf_t &v, const mpf_t t, const mpf_t u);

/**
  * To compute w value used for iteration value
 * w= 27(1+ s + s^2)/v
 * @param w(call by refernce value) return the value of w after iteration
 * @param w constant mpf variable taken from previous iteration value
 * @param v constant mpf variable taken from previous iteration value
 */
void w_value(mpf_t &w, const mpf_t s, const mpf_t v);

/**
  * To compute a value used for iteration value
 * a= w*a + 3^(2n-1)* (1-w)
 * @param a(call by refernce value) return the value of a after iteration
 * @param w constant mpf variable taken from previous iteration value
 * @param i constant int  variable taken from for loop
 */
void a_value(mpf_t & a,const mpf_t w,const int i );

/**
  * To compute s value used for iteration value
 * s=(1-r^3)/ (t+2u)v
 * @param s(call by refernce value) return the value of s after iteration
 * @param r constant mpf variable taken from previous iteration value
 * @param t constant mpf variable taken from previous iteration value
 * @param u constant mpf variable taken from previous iteration value
 * @param v constant mpf variable taken from previous iteration value
 */
void s_value(mpf_t &s,const mpf_t r,const mpf_t t,const mpf_t u,const mpf_t v);

/**
  * To compute r value used for iteration value
 * r = (1-s^3) ^1/3
 * @param r(call by refernce value) return the value of r after iteration
 * @param s constant mpf variable taken from previous iteration value

 */
void r_value(mpf_t & r, const mpf_t s);

/**
 * to print the computed pi upto 1000 precisons given in program
 * @param pi(call by refernce value) return the value of r after iteration
 *
 */
void print(const mpf_t& pi);


int main()
{
	int start_s=clock();
	mpf_set_default_prec(BIT_COUNT*PRECISION*2);  // precision in bits

	mpf_t pi;
	mpf_init(pi);


nonic(pi);
print( pi);

int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) <<" sec"<< endl;

return 0;
}

void nonic(mpf_t& pi)
{
	//decalation of mpf variables
mpf_t a,r,s,t,u,v,w;
mpf_t one,two,three;
mpf_t temp_1,prev_a;


// initilization of mpf variables
mpf_init(a);
mpf_init(r);
mpf_init(s);
mpf_init(t);
mpf_init(u);
mpf_init(v);
mpf_init(w);
mpf_init(temp_1);
mpf_init(prev_a);

//initilization and setting mpf variable to int
mpf_init_set_d(one,1.0);
mpf_init_set_d(three,3.0); //
mpf_init_set_d(two,2.0);


// setting a ,r , s

// a value
mpf_div(a,one,three); //a =1/3


// r value
mpf_sqrt(temp_1,three);
mpf_sub(r,temp_1,one);// (root3)-1
mpf_div(r,r,two);// r value=((root3)-1)/2

//s value

mpf_pow_ui(temp_1,r,3);
mpf_sub(temp_1,one,temp_1);
cube_root( s, temp_1);// s= (1-r^3) ^ 1/3

// iteration from 1 to max_iterations

int j=0;
do
{
	mpf_set(prev_a, a);
	mpf_div(temp_1, one, prev_a);

//t val
mpf_mul(t,two,r); //2r
mpf_add(t,t,one); //1+2r

// u val
u_value(u,r); //function to find u value


// v value
v_value(v,t,u); // function to find v value


// w value
w_value(w,s,v); //function to find w value


//a value
a_value(a,w,j); // function to find a value


//s value
s_value(s,r,t,u,v); //function to find s value


// r value
r_value(r,s); //function to find r value
j++;


}while ( ((j < 2) || (mpf_eq(a, prev_a , PRECISION) == 0) ) && (j < MAX_ITERATIONS));
mpf_set_d(pi,1);
mpf_div(pi,pi,a);

}

void print(const mpf_t& pi)
{
    int count=0;
    char* pi_val;
    mp_exp_t exp;

    pi_val= mpf_get_str(NULL,&exp,BASE,PRECISION,pi);
    cout<<pi_val[count]<<".";
    count++;
    for(int i=1;i<=LINE_COUNT;i++){
   	 for(int j=1;j<=LINE_SIZE;j++){
   		 cout<<pi_val[count];
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

void cube_root(mpf_t& x, const mpf_t a)
{
	//xn = x(x3 + 2a)/ (2.x3 + a)

	mpf_set_d(x,1.0);
	mpf_t xn,b,c,d,n,x_prev;

	mpf_init(xn); //xn
	mpf_init(b);
	mpf_init(c);
	mpf_init(n);
	mpf_init(d);
	mpf_init(x_prev);
	int count=0;

	do
	{
	mpf_set(x_prev,x);
	mpf_pow_ui(b,x,3); //b=pow(xn,3)
	mpf_mul_ui(c,a,2);  //a=2q
	mpf_add(n,b,c); // n=x3+2a
	mpf_mul(n,x,n); // numerator term

	mpf_mul_ui(d,b,2);
	mpf_add(d,a,d); //denomiantor

	mpf_div (x,n,d);
	count++;

	}while ((mpf_cmp(x, x_prev) != 0) && (count < MAX_ITERATIONS));
}


void u_value(mpf_t &u, const mpf_t r)
{
	mpf_t temp_1,temp_2,temp_3;
	mpf_init(temp_1);
	mpf_init(temp_2);
	mpf_init(temp_3);

	mpf_add_ui(temp_1,r,1.0);
	mpf_mul(temp_2,r,r);
	mpf_add(temp_1,temp_1,temp_2);
	mpf_mul_ui(temp_2,r,9);
	mpf_mul(temp_3,temp_1,temp_2);
	cube_root(u,temp_3);

}

void v_value(mpf_t &v, const mpf_t t, const mpf_t u)
{
	mpf_t temp_1,temp_2;
	mpf_init(temp_1);
	mpf_init(temp_2);

	mpf_mul(temp_1,t,t);
	mpf_mul(temp_2,t,u);
	mpf_add(temp_1,temp_1,temp_2);
	mpf_mul(temp_2,u,u);
	mpf_add(v,temp_1,temp_2);

}

void w_value(mpf_t &w, const mpf_t s, const mpf_t v)
{
	mpf_t temp_1,temp_2;
	mpf_init(temp_1);
	mpf_init(temp_2);

	mpf_add_ui(temp_1,s,1.0);
	mpf_mul(temp_2,s,s);
	mpf_add(temp_1,temp_1,temp_2);
	mpf_mul_ui(temp_1,temp_1,27.0);
	mpf_div(w,temp_1,v);
}

void s_value(mpf_t &s,const mpf_t r,const mpf_t t,const mpf_t u,const mpf_t v)
{
	mpf_t temp_1,temp_2,temp_3,one,two;
	mpf_init(temp_1);
	mpf_init(temp_2);
	mpf_init(temp_3);
	mpf_init_set_d(one,1.0);
	mpf_init_set_d(two,2.0);

	mpf_sub(temp_1,one,r);
	mpf_pow_ui(temp_2,temp_1,3);
	mpf_mul(temp_1,u,two);
	mpf_add(temp_3,temp_1,t);
	mpf_mul(temp_3,temp_3,v);
	mpf_div(s,temp_2,temp_3);
}

void a_value(mpf_t & a,const mpf_t w,const int i )
{
	mpf_t temp_1,temp_2,temp_3,one,two,three;
	mpf_init(temp_1);
	mpf_init(temp_2);
	mpf_init(temp_3);
	mpf_init_set_d(one,1.0);
	mpf_init_set_d(two,2.0);
	mpf_init_set_d(three,3.0);

	mpf_sub(temp_1,one,w);
	if(i==0)
	{
	mpf_div(temp_2,one,three);
	}
	else
	{
	mpf_pow_ui(temp_2,three,(2*i-1));
	}

	mpf_mul(temp_3,temp_1,temp_2);
	mpf_mul(temp_1,a,w);
	mpf_add(a,temp_1,temp_3);
}
void r_value(mpf_t & r, const mpf_t s)
{
	mpf_t temp_1,temp_2,one;
	mpf_init(temp_1);
	mpf_init(temp_2);
	mpf_init_set_d(one,1.0);

	mpf_pow_ui(temp_1,s,3);
	mpf_sub(temp_2,one,temp_1);
	cube_root(r,temp_2);

}
