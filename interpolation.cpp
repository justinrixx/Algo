#include <iostream>
#include <cstdlib>   // for random
#include <time.h>    // for random
#include <algorithm> // for sort

#define NUMITEMS 10000
#define TARGET 40 // the number to look for

using namespace std;

/* The binary search algorithm */
int searchBinary(int needle, int * haystack, int size, bool interpolation = false);

/* The only difference between binary search and interpolation
   search is the choice of 'midpoint' or where to look next. */
int getMidpointB(int iLeft, int iRight);
int getMidpointI(int iLeft, int iRight, int * haystack, int needle);

int main()
{
   int * numbers = new int[NUMITEMS];

   srand(time(NULL));

   // create some random numbers
   for (int i = 0; i < NUMITEMS; i++)
      numbers[i] = rand() % NUMITEMS + 1;

   int target = numbers[rand() % NUMITEMS];

   // sort the numbers
   sort(numbers, numbers + NUMITEMS);

   // do a binary search
   int result = searchBinary(target, numbers, NUMITEMS);

   cout << "Binary search completed in " << result << " iterations" << endl;

   // now interpolation search
   result = searchBinary(target, numbers, NUMITEMS, true);

   cout << "Interpolation search completed in " << result << " iterations" << endl;

   return 0;
}

int searchBinary(int needle, int * haystack, int size, bool interpolation)
{
   // keep track of the number of iterations
   int numIterations = 1;

   int iLeft = 0;
   int iRight = size - 1;

   while (iLeft <= iRight)
   {
      // binary search or interpolation?
      int iMid = ((interpolation) ? getMidpointI(iLeft, iRight, haystack, needle) 
         : getMidpointB(iLeft, iRight));
      cerr << iMid << endl;

      if(haystack[iMid] == needle)
        return numIterations; 

      else if (haystack[iMid] < needle)
        iLeft = iMid + 1;
      else
        iRight = iMid - 1;

     numIterations++;
   }

   // not found
   return numIterations;
}

/* The middle is just the average */
int getMidpointB(int iLeft, int iRight)
{
   return (iRight + iLeft) / 2;
}

/* Extrapolate where the value should be, assuming a linear
   spread of numbers */
int getMidpointI(int iLeft, int iRight, int * haystack, int needle)
{
   return iLeft + (((needle - haystack[iLeft]) * (iRight - iLeft)) / (haystack[iRight] - haystack[iLeft]));
}
