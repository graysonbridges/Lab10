#include "Hybrid.h"
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;

#include <iostream>
using namespace std;

void addCDs(ListArray<CD>* list, Hybrid<CD>* h)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      h->enqueue(cd);
   }

   delete iter;
}

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");

   Hybrid<CD>* h = new Hybrid<CD>(&CD::compare_items, &CD::compare_keys);
   addCDs(cds, h);

   ListDoublyLinkedIterator<CD>* iter = h->iterator();
   int counter = 0;
   while(iter->hasNext())
   {
      CD* cd = iter->next();
      cd->displayCD();
	  counter++;
   }
   cout << "\n\n\n Counter: " << counter << "\n\n\n" << endl;
   delete iter;
   counter = 0;
   while(!(h->isEmpty()))
   {
      CD* cd = h->dequeue();
      cd->displayCD();
	  counter++;
   }
   cout << "\n\n\n Counter: " << counter << "\n\n\n" << endl;
   deleteCDs(cds);
   cout << "1" << endl;
   delete cds;
   cout << "2" << endl;
   delete h;
   cout << "3" << endl;
   return 0;
}

