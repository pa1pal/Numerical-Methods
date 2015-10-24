/**
 *
 * C++ code for Guass elimination method ( without pivoting)
 * @author : Pawan Pal (pa1pal)
 * @Date : 24 Oct 2015
 * 
 */

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long int64; 
typedef vector<int> VI;
typedef vector<double> VD;

#define MP(A,B) make_pair(A,B)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define gc getchar_unlocked	// In windows use only getchar
#define debug
#define input	

/**
 * Used for fast input but it makes program thread unsafe
 */
int fast_in() 
{
	char c = gc();
	while(c<'0' || c>'9') c = gc();
	int ret = 0;
	while(c>='0' && c<='9') 
	{
		ret = 10 * ret + c - 48;
		c = gc();
	}
	return ret;
}

/**
 * Prints the vector
 * 
 * @param	matrix   2D vector
 * @param	number of equation
 * @param	number of unknowns
 */
void print_mat(vector<VD> matrix, int eq, int uk)
{
	FOR(i,0,eq)
	FOR(j,0,uk) 
	{ 
		cout<<std::setprecision(4)<<matrix[i][j]<<"\t"; 
		if (j==uk-1)
			cout<<"\n\n";
	}
}

/**
 * Guass elimination method
 * 
 * @param	matrix   2D vector
 * @param	number of equation
 * @param	number of unknowns
 */
VD guass(vector<VD> matrix, int eq, int uk)
{
	FOR(i,0,eq)
	FOR(j,i+1,eq)
	{
		double t = -matrix[j][i]/matrix[i][i];

		FOR(k,i,uk)
		{
			if (i==k) {
				matrix[j][k] = 0;
			} else {
				matrix[j][k] += t * matrix[i][k];
			}
		}
	}

	cout<<"Upper triangular matrix\n";
	print_mat(matrix,eq,uk);

	VD roots(eq);

	for (int i=eq-1; i>=0; i--) 
	{
		roots[i] = matrix[i][eq]/matrix[i][i];
		for (int k=i-1;k>=0; k--) 
		{
			matrix[k][eq] -= matrix[k][i] * roots[i];
		}
	}
	return roots;
}

int main()
{
	#ifdef input
	freopen("input.txt","r",stdin);
	#endif
	int eq, uk;
	cout<<"Enter the number of equations and unknowns\n";
	cin>>eq>>uk;uk++;
	vector<VD> matrix;	//equation matrix
	VD roots(eq);		//roots matrix
	matrix.resize(eq);

	for (int i = 0; i < eq; ++i)
		matrix[i].resize(uk);
	for (int i = 0; i < eq; i++) 
		for (int j = 0; j < uk; j++)
			matrix[i][j] = fast_in();

		cout<<"Your Matrix\n";
		print_mat(matrix,eq,uk);

	#ifdef debug
		roots = guass(matrix,eq,uk);
	#endif 
		for (int i = 0; i < eq; ++i)
			{cout<<"The roots are : ";cout<<roots[i]<<"\t"<<endl;}

	#ifdef debug
		cout<<"TIME:"<<(double)clock()/(CLOCKS_PER_SEC)<<"  sec\n"; // Execution time
    #endif
	
	return 0;
}// end main