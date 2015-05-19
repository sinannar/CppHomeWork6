#include <iostream>
#include <cmath>
#include "091044005P03.h"

//#define TESTINGNAMESPACEGLOBAL
//#define TESTINGNAMESPACESPECIFIC
//#define TESTINGNAMESPACEUSINGSCOPERESULATION
//#define TESTINGNAMESPACEINSCOPE
#define TESTINGOPERATOROVERLOADINGANDFUNCTIONS

#ifdef TESTINGOPERATOROVERLOADINGANDFUNCTIONS
#ifndef TESTINGNAMESPACEGLOBAL
#define TESTINGNAMESPACEGLOBAL
#endif
#endif

using namespace std;


#ifdef TESTINGNAMESPACEGLOBAL
using namespace PolyNar;
#endif

#ifdef TESTINGNAMESPACESPECIFIC
using PolyNar::Polinomial;
#endif


int main(void)
{

#ifdef TESTINGNAMESPACEGLOBAL
	Polinomial pol;
#endif

#ifdef TESTINGNAMESPACESPECIFIC
	Polinomial pol;
#endif

#ifdef TESTINGNAMESPACEUSINGSCOPERESULATION
	PolyNar::Polinomial pol;
#endif

#ifdef TESTINGNAMESPACEINSCOPE
	using namespace PolyNar;
	Polinomial pol;
#endif

#ifdef TESTINGOPERATOROVERLOADINGANDFUNCTIONS
	pol=5+3;
	cout<<pol<<endl;

	pol[3]=5;
	cout<<pol<<endl;

	pol[3]=-5;
	cout<<pol<<endl;

	pol=-pol;
	cout<<pol<<endl;

	pol=pol*pol;
	cout<<pol<<endl;

	pol=pol*5;
	cout<<pol<<endl;

	pol=pol-5;
	cout<<pol<<endl;

	pol=pol+5;
	cout<<pol<<endl;


	cout<<"enter the polinomial"<<endl;	
	cin>>pol;
	cout<<pol<<endl;

	pol.printPolinomial();
	pol.isThatQuadratic();
	cout<<pol.evaluate(2)<<endl;

	cout<<"calculating most power"<<endl;	
	cout<<Polinomial::getMostPower()<<endl;

	int a[9];
	a[8]=1;
	cout<<"calculating most power"<<endl;	
	Polinomial pol2(a,9);
	cout<<Polinomial::getMostPower()<<endl;
	
#endif
	
	return 1;
}



