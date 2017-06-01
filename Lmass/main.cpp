#include "ListMass.h"
#include <iostream>

int main()
{
   SpisokMass<int> a(200);
   a.add1(0);
   a.add1(1);
   a.add2(0);
   a.del2();
   a.add2(3);
   a.add2(4);
   a.del2();
   a.add2(5);
   a.add1(6);
   a.add1(7);
   a.add1(8);
   a.add1(9);
   a.add1(10);
   a.add1(10);
   a.add1(12);
   a.add1(12);
   a.add1(14);
   a.add2(1);
   a.add1(16);
   a.add1(17);
   a.add2(18);
   a.del2();

   for(int i=a.get1();!a.end0(i);i=a.get2(i))
   {
	   std:: cout<<a.get0(i)<<" ";
   }
   std::cout << std::endl;
   a.printDoblication();

   std:: cin.get();
};