#include"091044005P03.h"
#include<iostream>
#include<cmath>

int PolyNar::Polinomial::largestDegree=0; //static variable initializing

namespace PolyNar{	//PolyNar namespace starting


	/*
	inputs	: two input polinomial objects for adding them
	effects	: return the result as const
	*/
	const Polinomial operator +(const Polinomial& param1,const Polinomial& param2)
	{

		if(param1.degree>param2.degree)
		{
			Polinomial sum(param1.degree);
			for(int i=0;i<param2.size;++i)
				sum.coefficients[i]=param1.coefficients[i]+param2.coefficients[i];
			for(int i=param2.size;i<param1.size;++i)
				sum.coefficients[i]=param1.coefficients[i];
			return sum;
		}
		if(param1.degree<param2.degree)
		{
			Polinomial sum(param2.degree);
			for(int i=0;i<param1.size;++i)
				sum.coefficients[i]=param2.coefficients[i]+param1.coefficients[i];
			for(int i=param1.size;i<param2.size;++i)
				sum.coefficients[i]=param2.coefficients[i];
			return sum;
		}
		if(param1.degree==param2.degree)
		{			
			Polinomial sum(param1.degree);
			for(int i=0;i<param2.size;++i)
				sum.coefficients[i]=param2.coefficients[i]+param1.coefficients[i];
			return sum;
		}
				
	}

	/*
	inputs	: two input polinomial objects calculating differences
	effects	: return the sum as const
	*/
	const Polinomial operator -(const Polinomial& param1,const Polinomial& param2)
	{
		if(param1.degree>param2.degree)
		{
			Polinomial sum(param1.degree);
			for(int i=0;i<param2.size;++i)
				sum.coefficients[i]=param1.coefficients[i]-param2.coefficients[i];
			for(int i=param2.size;i<param1.size;++i)
				sum.coefficients[i]=param1.coefficients[i];
			return sum;
		}
		if(param1.degree<param2.degree)
		{
			Polinomial sum(param2.degree);
			for(int i=0;i<param1.size;++i)
				sum.coefficients[i]=-param2.coefficients[i]+param1.coefficients[i];
			for(int i=param1.size;i<param2.size;++i)
				sum.coefficients[i]=-param2.coefficients[i];
			return sum;
		}
		if(param1.degree==param2.degree)
		{			
			Polinomial sum(param1.degree);
			for(int i=0;i<param2.size;++i)
				sum.coefficients[i]=-param2.coefficients[i]+param1.coefficients[i];
			return sum;
		}	
	}

	/*
	inputs	: two input polinomial objects for multplying them
	effects	: return the result as const
	*/
	const Polinomial operator *(const Polinomial& param1,const Polinomial& param2)
	{
		Polinomial sum(param1.degree+param2.degree,0);
		for(int i=0;i<param1.size;++i)
			for(int j=0;j<param2.size;++j)
				sum.coefficients[i+j]=sum.coefficients[i+j]+(param1.coefficients[i]*param2.coefficients[j]);
		return sum;
	}

	/*
	inputs	: one polinomial object as const
	effects	: return the negative form of it as const
	*/
	const Polinomial operator -(const Polinomial& param)
	{
		Polinomial sum(param.degree);
		for(int i=0;i<param.size;++i)
			sum.coefficients[i]=-param.coefficients[i];
		return sum;
	}

	/*
	inputs	: access to index
	effects	: RETURN WITH REFERENCE
	*/
	int& Polinomial::operator [](int pwr)
	{	if(pwr<=degree)
		return coefficients[pwr];
		else
		{
			for(int i=pwr-degree;i>0;--i)
			addElement(pwr,0);
			return coefficients[pwr];
		}
		
	}

	/*
	inputs	:get output stream and const polinomial objects
	effects	:send to ouput stream element of objects
	*/
	ostream& operator <<(ostream& outputStream,const Polinomial& parameter)
	{
		for(int i=0;i<parameter.size;++i){
			if(parameter.coefficients[i]!=0)
			outputStream <<parameter.coefficients[i]<<"x^"<<i;		
		}		
		return outputStream;
	}

	/*
	inputs	:get intput stream and polinomial objects
	effects	:send things from to element of objects
	*/
	istream& operator >>(istream& inputStream,Polinomial& parameter) 
	{
		for(int i=0;i<parameter.size;++i)
			inputStream>>parameter.coefficients[i];
		return inputStream;
	}

	/*
	inputs	: no input but can access the Polinomial objects
	effects	: print polinomial all elements on screen
	*/
	void Polinomial::printPolinomial()const
	{
		cout<<"F(x)=";
			for(int i=0;i<=degree;++i)
			{
				if(coefficients[i]!=0)
					cout<<coefficients[i]<<"x^"<<i<<"+";
			}
		cout<<endl;
	}

	/*
	inputs	: no input but can access the Polinomial objects
	effects	:calculate the positive roots of polinomials with descartes rules and return it
	*/
	int Polinomial::descartSignRule()
	{
		int numOfPositiveRoots=0;

		for(int i=0;i<degree;++i)
			if( !((coefficients[i]==0) && (coefficients[i+1]==0)) )
				if( ( (coefficients[i]<0) && (coefficients[i+1]>0) ) ||
					( (coefficients[i]>0) && (coefficients[i+1]<0) ) )
					  ++numOfPositiveRoots;
	
	
		return numOfPositiveRoots;
	}

	/*
	inputs	:no parameter constructor
	effects	:work as default constructor 
	*/
	Polinomial::Polinomial()
	{
		do {coefficients=new int[1];
		}while(coefficients==NULL);

		coefficients[0]=0;
		degree=0;
		size=1;
		if(degree>largestDegree)
			largestDegree=degree;
	}

	/*
	inputs	:array parameter constructor
	effects	:creating new object with this array
	*/
	Polinomial::Polinomial(int* iPtrCoefficints,unsigned int sizeIptr)
	{
		do {coefficients=new int[sizeIptr];
		}while(coefficients==NULL);

		for(int i=0;i<sizeIptr;++i)
		coefficients[i]=iPtrCoefficints[i];
		degree=sizeIptr-1;
		size=sizeIptr;
		if(degree>largestDegree)
			largestDegree=degree;
	}
	/*
	inputs	:one parameter constructor also used for type conversion and in this case;overloaded +,-,* operators as friend to access first parameter
	effects	:creating new objects of polinomial class
	ALSO IT WORKS FOR TYPE CONVERSION as like "pol + 5"
	*/
	Polinomial::Polinomial(int coefficient)
	{

		do {coefficients=new int;
		}while(coefficients==NULL);

		coefficients[0]=coefficient;
		degree=0;
		size=1;
		if(degree>largestDegree)
			largestDegree=degree;
	}

	/*
	inputs	:get the power and coefficient of this power
	effects	:initialize the object with it
	*/
	Polinomial::Polinomial(int power,int coef)
	{
		do {coefficients=new int[power+1];
		}while(coefficients==NULL);


		for(int i=0;i<power;++i)
		coefficients[i]=0;
		coefficients[power]=coef;
		degree=power;
		size=power+1;
		if(degree>largestDegree)
			largestDegree=degree;
	}

	/*
	inputs	:power and no coef parameter here
	effects	:adding element with memory alloc
	*/
	void Polinomial::addElement(int power)
	{
		if(power>degree){
		for(int i=power-degree;i>1;--i)
		addElementOnArray(0);
		addElementOnArray(1);
		}
	}

	/*
	inputs	:power and coef parameter 
	effects	:adding element with memory allocation
	*/
	void Polinomial::addElement(int power,int coef)
	{
		if(power>degree){
		for(int i=power-degree;i>1;--i)
		addElementOnArray(0);
		addElementOnArray(coef);	
		}
	}
	 
	/*
	inputs	:deleting element in whic power...
	effects	:deleting it
	*/
	void Polinomial::deleteElement(int power)
	{
		if(power<degree)
		for(int i=degree-power;i>0;--i)
		deleteElementFromArray();

	}

	/*
	inputs	:overloded form uf one parameter function
	effects	:same work just difference is signatures
	*/
	void Polinomial::deleteElement(int power,int coef)
	{
		if(power<degree)
		for(int i=degree-power;i>0;--i)
		deleteElementFromArray();
	}

	/*
	inputs	: no input but can access the Polinomial objects
	effects	: return is taht quadratic
	*/
	bool Polinomial::isThatQuadratic()const
	{
		if(degree==2)
			return true;
		return false;
	}

	/*
	inputs	: value is input that should be x and it can access the Polinomial objects
	effects	: return the sum of x
	*/
	int Polinomial::evaluate(int x)
	{
		int sum(0);

		for(int i=0;i<degree+1;++i)
		{
			sum+=(coefficients[i] * pow(x,i));
		}

		return sum;
	}

	/*
	inputs	:no input
	effects	:return most power that has been created
	*/
	int Polinomial::getMostPower()
	{
		return largestDegree;
	}


	
	//the big three
	/*
	assignment operator overloading
	i overload this,cause there is pointers...
	*/
	Polinomial& Polinomial::operator =(const Polinomial& rightSide)
	{
		if(size != rightSide.size)
		{
			delete[] coefficients;
			coefficients=new int[rightSide.size];
		}
		size=rightSide.size;
		degree=rightSide.degree;
		for(int i=0;i<size;++i)
		coefficients[i]=rightSide.coefficients[i];
	
		return *this;
	}

	/*
	copy constructor
	its the one of big three if i overload,so i do,one of them,its good the overload others
	*/		
	Polinomial::Polinomial(const Polinomial& polinomialObject):size(polinomialObject.size),degree(polinomialObject.size)
	{
		coefficients = new int[size];
		for(int i=0;i<size;++i)
		coefficients[i]=polinomialObject.coefficients[i];
	}
	/*
	destructor overloaded cause of coefficients are type of pointer integer
	and someone should give free space to back
	*/
	Polinomial::~Polinomial()
	{
		if(coefficients!=NULL)
		delete[] coefficients;
	}

	/*
	i need a function to have access and adding element on array also i do it cause of allocation operations
	normally i should not to access members,but here i should have access to make them things more eaiser...
	i did this private,i consider to make them member of unnamednamespace but it was come to me more easir.
	*/
	void Polinomial::addElementOnArray(int element)
	{
		int *intPtr;

		intPtr=new int[size+1];

		for(int i=0;i<size;++i)
		intPtr[i]=coefficients[i];

		intPtr[size]=element;

		delete[] coefficients;

		coefficients=intPtr;
		size=size+1;
		degree=degree+1;
	}

	/*
	i need a function to have access and deleting element from array also i do it cause of allocation operations
	normally i should not to access members,but here i should have access to make them things more eaiser...
	i did it private,i consider to make them member of unnamednamespace but it was come to me more easier.
	*/
	void Polinomial::deleteElementFromArray()
	{
		int *intPtr;

		intPtr=new int[size-1];

		for(int i=0;i<size-1;++i)
		intPtr[i]=coefficients[i];

		delete[] coefficients;

		coefficients=intPtr;
		size=size-1;
		degree=degree-1;
	}


}		//PolyNar namespace finishing




