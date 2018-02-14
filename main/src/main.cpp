#include<iostream>
#include<string>
#include<vector>
using namespace std;


class shiftregister {

	public :
	int shiftingmethod(int argc,char *argv[]);
};

int  shiftregister::shiftingmethod(int argc,char * argv[]) {

	string str,x, s,r,l,v;
    int y=0;

    for( int m=1;m<argc;m++)
  	{
            x=argv[m];

  	           if(x=="-s")
  		    {
  			     s=argv[m+1];

  		     }
  	           else if(x=="-i")
		      {
		         str=argv[m+1];
		       }
  	           else if(x=="-l")

  	           {
			      l=argv[m+1];
                }
  	           else if(x=="-r")
	           {

  	        	   r=argv[m+1];
		        }
  	           else if(x=="-v")
		     {
			    v=argv[m+1];

		}
  	           else  if(x=="-p")
		{


		}
  	           else
  	           {
  	        	   cout<<"-1";

  	           }



  		m++;

 }



	vector<char>i(str.begin(), str.end());
	int k = atoi(s.c_str());

	int w = atoi(r.c_str());
	int c = atoi(l.c_str());
	int u = atoi(v.c_str());


	for(int p=0;p<k;p++)
	    {
	    	cout<<i[p];


	    }
     cout<<endl;
     int temp=k;
     		 if(temp>i.size())
     		    for( int m=1;m<=(temp-i.size());m++ )
     		     {

     		   	 for(int j=i.size();j>=1;j--)
     		   	 {
     		    		 i[j]=i[j-1];
     		    	 }
     		   	 i[0]='0';


     		    }
     		   else if(temp==i.size())
     		    {


     		    }
     		    else
     		{
     		   	 for(int j=0 ;j<(i.size()-temp);j++)
     		   	 {
     		 		 i.pop_back();

     		  	 }
     		}

   for( int j=1;j<=w;j++)
     	{

    	      for(y=(k-1);y>=0;y--)
    	    	i[y]=i[y-1];
    	      if(u==1)
               i[0]='1';
    	      else i[0]='0';
     }

	for( int j=1;j<=c;j++)
		{

		      for(y=1;y<=(k-1);y++)
		    	  i[y-1]=i[y];
		      if(u==1)
	             i[k-1]='1';
		      else
		    	  i[k-1]='0';

		  }


     if(x=="-p")
     {
    	 for(int m=0;m<k;m++)
    		 cout<<i[m];
     }


    return 0;
};

int main(int argc ,char * argv[])
{
	shiftregister sr;
	sr.shiftingmethod(argc,argv);

	return 0;
}
