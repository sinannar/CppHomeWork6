#ifndef POLINOMIAL_H_INCLUDED
#define POLINOMIAL_H_INCLUDED

#include <iostream>

using namespace std;

namespace PolyNar
{
	class Polinomial
	{
		public:


			//operator overloading
		    friend const Polinomial operator +(const Polinomial&,const Polinomial&);
		    friend const Polinomial operator -(const Polinomial&,const Polinomial&);
		    friend const Polinomial operator *(const Polinomial&,const Polinomial&);
		    friend const Polinomial operator -(const Polinomial&);
			friend ostream& operator <<(ostream&,const Polinomial&);
			friend istream& operator >>(istream&,Polinomial&);
			int& operator [](int power);

			//functional things work on member
		    void printPolinomial()const;
			int descartSignRule();
			bool isThatQuadratic()const;
		    int evaluate(int x);
		    
			//constructors
		    Polinomial();
		    Polinomial(int*,unsigned int);
		    Polinomial(int coef);
		    Polinomial(int power,int coef);

			//helper functions
		    void addElement(int power);
		    void addElement(int power,int coef);
		    void deleteElement(int power);
		    void deleteElement(int power,int coef);
		    
			//function that is not need any object to work
			static int getMostPower();
		
			//the big three
			Polinomial& operator =(const Polinomial& rightSide);		
			Polinomial(const Polinomial& rightSide);
			~Polinomial();

		private:
			//variables of class objects
		    int* coefficients;
			unsigned int size;
		    unsigned int degree;
			
			//variables of class
		    static int largestDegree;

			//programmer helper functions,and also work on array for programmer
			void addElementOnArray(int);
			void deleteElementFromArray();

	};
}
#endif // POLINOMIAL_H_INCLUDED
