/* 
File: main.cpp
Author: david serrano
Email: davids2016@student.vvc.edu
Description: creates a concordance using alice.txt as a reference. prints stats of every word in text file.
*/
#include "concordance.h"

int main()
{
   Concordance con("alice.txt");
   con.parse();   
   con.print();
   return 0;
}
