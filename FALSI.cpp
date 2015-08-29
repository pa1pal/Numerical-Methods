/**
 *
 * @author : Pawan Pal
 * @Date : 28 Aug 2015
 * 
 */
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

 using namespace std;

#define epsilon 9.16978e-005

 long iteration = 0;
 
 // Last two iterations.
 double pn = 0, pn1 = 0, pn2 = 0, error = 0;

/**
 * Calculates the polynomial value
 * 
 * @param   poly    Vector of coefficients
 * @param   x       Value to calculate, independent variable
 * @param   degree  Order of equation
 * @param   exp     Expression
 * @return  exp     Polynomial Value, dependent variable
 */
 double func(vector<double> poly, double x,int degree,double exp)
 {
   for(int i=0; i<degree; i++)
   {
     exp += ((poly.at(i))*(pow(x,(degree-i-1))));
   }
   return exp;
 }

/**
 * To calculate the value of x intercept
 * 
 * @param  a  starting interval
 * @param  b  ending interval
 * @param  va function value at a
 * @param  vb function value at b
 * @return    intercept value
 */
 double xintercept(double a, double b, double va, double vb)
 {return  ((a*vb - b*va)/ (vb-va));}


/**
 * To calculate error
 */
 void calculate_error()
 {
	// Check if 
   if (++iteration> 3)
   {
    error = (pn - pn1) / (pn1 - pn2);
    error = (abs(error)/abs(error-1))*abs(pn-pn1);
  }
}

/**
 * Function to calculates roots using falsi method
 * 
 * @param  poly      Vector of coefficients
 * @param  a         Starting of interval
 * @param  b         ending of interval
 * @param  degree    order of equation
 * @param  exp       expression
 */
 double falsi(vector<double> poly, double a, double b,int degree, double exp)
 {

  calculate_error();
  double root;
  int start=0;

  pn2 = pn1;
  //cout<<pn2<<endl;
  pn1 = pn;
  //cout<<pn1<<endl;

  double intercept = xintercept( a,b,func(poly, a, degree, exp),func(poly, b, degree, exp));
  pn=intercept;
  
  cout<<std::setprecision(10)<<"Iteration number : "<<iteration<<", Root : "<<intercept<<", Error : "<<error<<"\t a : "<<a<<", b : "<<b<<endl;

// Checking the stoping condition
  if(abs(func(poly, intercept, degree, exp)) < epsilon)
  {
    cout<<std::setprecision(10)<<"Iteration number : "<<iteration<<", Root : "<<intercept<<", Error : "<<error<<"\t a : "<<a<<", b : "<<b<<endl;
      //cout<<"The root is : "<<intercept<<" in "<<iteration<<"iterations"<<"The error is : "<<error<<endl;
    return root;
  }
  else //shrinking the interval
  {
    if(func(poly, intercept, degree, exp) * func(poly, a, degree, exp) < 0)
    {
      b= intercept;
      falsi(poly, a, b,degree,exp);
    }
    else
    {
      a=intercept;
      falsi(poly, a, b,degree,exp);
    }
  }
}
/**
 * Main function
 */
 int main()
 {
   char y;
   do
   {

    int degree;
    double exp=0.0,x,n,a,b,temp;
    vector<double> poly;
    cout<<"Enter the degree of polynomial\n";
    cin>>degree;
    degree++;
    cout<<"Enter coefficient\n";
    while(poly.size()<degree)  // input the coefficients
    {
     cin>>n;
     poly.push_back(n);
   }
   for(int i=0; i<degree;i++)   //  display the equation
   {
    if(i!= (degree-1))
      cout<<poly.at(i)<<"x^"<<(degree-i-1)<<" + ";
    else
      cout<<poly.at(i)<<endl;
  }

  cout<<"Enter intervals\n";
  cin>>a>>b;
  cout<<"Value at a is : "<<func(poly, a, degree, exp)<<endl;
  cout<<"Value at b is : "<<func(poly, b, degree, exp)<<endl;

  if(func(poly, a, degree, exp)>0 && func(poly, b, degree, exp)<0) // to make a must be negative and b positive
    {a=temp;a=b;b=temp;}

  falsi(poly, a,b,degree,exp);

  cout<<"Want to solve more equations\n Press 'y' or 'Y' for yes and any other key for no\n";
  cin>>y;
}while(y=='y' || y=='Y');
}
