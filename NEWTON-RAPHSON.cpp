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

/**
 * Calculates the polynomial value
 * 
 * @param   poly    Vector of coefficients
 * @param   x       Value to calculate, independent variable
 * @param   degree  Order of equation
 * @param   exp     expression
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
 * Function to calculates roots using newtonraphson method
 * 
 * @param  poly      Vector of coefficients
 * @param  a         Starting of interval
 * @param  b         ending of interval
 * @param  degree    Order of equation
 * @param  exp       expression
 */
 double newtonraphson(vector<double> poly,vector<double> polydir, double a, double b,int degree, double exp)
 {

   double root;

   double c = b- ( (func(poly, b, degree, exp))/func(polydir, b, degree-1, exp));

   // if((func(poly, mid, degree, exp)*func(poly, a, degree, exp))>0)
   // {
    //a=mid;
    iteration++;
    cout<<std::setprecision(20)<<"Iteration number : "<<iteration<<"The root is : "<<c<<"     The function value is f(mid): "<<func(poly, c, degree, exp)<<endl;
    if((abs(a-b))<epsilon)
    {
      cout<<"the absolute difference value is :"<<abs(a-b)<<endl;
      root = a;
      cout<<"The root is : "<<root<<" in "<<iteration<<"iterations"<<endl;
      return root;
    }
    else
    {
      newtonraphson(poly,polydir, b, c,degree,exp);
    }


  //}
  // else
  // {
  //   b=mid;
  //   iteration++;
  //   cout<<std::setprecision(20)<<"Iteration number : "<<iteration<<"The root is : "<<mid<<"     The function value is f(mid): "<<func(poly, mid, degree, exp)<<endl;
  //   if((abs(a-b))<epsilon)
  //   {
  //     root = b;
  //     cout<<"The root is : "<<root<<" in "<<iteration<<"iterations"<<endl;
  //     return root;
  //   }
  //   else
  //   {
  //     newtonraphson(poly, a, b,degree,exp);
  //     iteration++;
  //   }
  // }                
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
    vector<double> poly, polydir;
    cout<<"Enter the degree of polynomial\n";
    cin>>degree;
    degree++;
    cout<<"Enter coefficient\n";
    while(poly.size()<degree)  // input the coefficients
    {
     cin>>n;
     poly.push_back(n);
   }

   cout<<"Enter the derivative of polynomial\n";
    while(polydir.size()<degree-1)  // input the coefficients
    {
     cin>>n;
     polydir.push_back(n);
   }
   cout<<"Your entered equation is : \n";
   for(int i=0; i<degree;i++)   //  display the equation
   {
    if(i!= (degree-1))
      cout<<poly.at(i)<<"x^"<<(degree-i-1)<<" + ";
    else
      cout<<poly.at(i)<<endl;
  }
  cout<<"The derivative of the entered equation is : \n";
  for(int i=0; i<degree-1;i++)   //  display the equation
   {
    if(i!= (degree-2))
      cout<<polydir.at(i)<<"x^"<<(degree-i-2)<<" + ";
    else
      cout<<polydir.at(i)<<endl;
  }

  cout<<"Enter intervals\n";
  cin>>a>>b;
  cout<<"Value at a is : "<<func(poly, a, degree, exp)<<endl;
  cout<<"Value at b is : "<<func(poly, b, degree, exp)<<endl;

  cout<<"Value of dir at a is : "<<func(polydir, a, degree-1, exp)<<endl;
  cout<<"Value of dir at b is : "<<func(polydir, b, degree-1, exp)<<endl;

  
  newtonraphson(poly,polydir, a,b,degree,exp);

  cout<<"Want to solve more equations\n Press 'y' or 'Y' for yes and any other key for no\n";
  cin>>y;
}while(y=='y' || y=='Y');
}
