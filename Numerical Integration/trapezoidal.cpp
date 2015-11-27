#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;

double func(vector<double> poly, double x,int degree,double exp)
{
 for(int i=0; i<degree; i++)
 {
   exp += ((poly.at(i))*(pow(x,(degree-i-1))));
 }
 return exp;
}

int main()
{
 char y;
 do
 {

  int degree;
  double exp=0.0,x,n,a,b,temp,val=0,h,segments,answer=0;
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

  cout<<"enter the limits and number of segments \n";
  cin>>a>>b>>segments;
  h= (b-a)/segments;
  cout<<"The value of h is : "<<h<<endl;
  // cin>>a>>b;
  cout<<"Value at a is : "<<func(poly, a, degree, exp)<<endl;
  cout<<"Value at b is : "<<func(poly, b, degree, exp)<<endl;

  answer += func(poly, a, degree, exp) + func(poly, b, degree, exp);
  
  if (segments > 0)
  {

    for (int i = 0; i < segments-1; ++i)
    {
      val += h;
      answer += 2*func(poly, val, degree, exp);
      //cout<<"Now the answer value is : "<<answer<<endl;
    }
  }
  //cout<<"Before dividing : "<<answer<<endl;
  answer *= (b-a)/(2*segments);
  cout<<"Final answer is  : "<<answer<<endl;
  cout<<"Want to solve more equations\n Press 'y' or 'Y' for yes and any other key for no\n";
  cin>>y;
}while(y=='y' || y=='Y');
}

/**
  Sample Output
 pa1pal@pa1pal:~/Documents/Codes/Numerical-Methods$ ./trapezoidal < input.txt 
Enter the degree of polynomial
Enter coefficient
2x^4 + 0x^3 + 3x^2 + 25x^1 + 0.2
enter the limits and number of segments 
The value of h is : 0.5
Value at a is : 0.2
Value at b is : 94.2
Final answer is  : 72.775
Want to solve more equations
 Press 'y' or 'Y' for yes and any other key for no

 */
