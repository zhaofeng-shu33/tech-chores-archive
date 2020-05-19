#include <iostream>
#include <float.h>
using namespace std;

template <typename numT>
struct fp_traits { };

template<>
struct fp_traits<float> {
	typedef float fp_type;
	enum { max_exponent = FLT_MAX_EXP };
	static inline fp_type epsilon()
	{ return FLT_EPSILON; }
};

template<>
struct fp_traits<double> {
	typedef double fp_type;
	enum { max_exponent = DBL_MAX_EXP };
	static inline fp_type epsilon()
	{ return DBL_EPSILON; }
};

template <typename numT>
class matrix {
public:
	typedef numT num_type;
	typedef fp_traits<num_type> num_type_info;
	inline num_type epsilon()
	{return num_type_info::epsilon();}
	inline num_type max_exponent()
	{return num_type_info::max_exponent;}

	//...
};

int main()
{

  typedef int* arrayType[10];
  arrayType myType;
  int a1=1;
  myType[0]=&a1;
  std::cout<<*myType[0]<<endl;
	matrix <float>  fm;
	matrix <double> dm;
	cout << "float  matrix: " << fm.max_exponent() << endl;
	cout << "double matrix: " << dm.max_exponent() << endl;
	
}
