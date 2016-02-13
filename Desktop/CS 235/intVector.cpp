#include <iostream>
#include "intVector.h" // header file name
using namespace std;

IntVector::IntVector() {  // Constructor for vector class
    maxSize = 10; // This will be the default size of the array created in the next line
    dArray = new int[maxSize]; // Creates a dynamic array using our private pointer dArray
    currentSize = -1; // Set to -1 as the array is empty as of now. Not set to 0 because array[0] means there is a variable.
}

void IntVector::push_back(int data) { // push_back function definition
      if (currentSize<(maxSize-1)) // Checks if the array is full or not
    {
        currentSize++; // records this push_back to keep track of the current size of the array
        dArray[currentSize] = data; // Now inserts the user provided data into the first empty paramater in the array
    }

      else // if array is full, it calls the resizeArray() function
       {
         resizeArray();  // array gets resized
         currentSize++; // records this push_back to keep track of the current size of the array
         dArray[currentSize] = data; // Now inserts the user provided data into the first empty paramater in the array
       }
}

void IntVector::resizeArray() { // Function definition for resizing the array

      int *resized = new int[maxSize * 2]; // a new dynamic array is created as a temporary array to hold the information in the current array. This array is double the size of the current array
      for (int i = 0; i < maxSize; i++) // For loop tranfers the information from the current array to this new temporary array
          resized[i] = dArray[i];
      delete [] dArray; // Now the current array will get deleted
      dArray = new int [maxSize*2]; // The new array will be created with double the size of the original
      for (int i = 0; i < maxSize*2; i++) // For loops transgers the informaiton from the temporary array to the newly created array
          dArray[i] = resized[i];
      maxSize *= 2; // the maxSize gets doubled, as now the new array can hold double the amount as the original array
      delete [] resized; // the temporary array is now deleted
}


int IntVector::pop_back() { // function definition for pop_back

     if (currentSize > -1) // Checks if the array is empty
        {
             currentSize--; // Records that an element was "removed" and the array shrunk by 1. I did not actually remove anything, but the user does not need to know that :)
             return dArray[currentSize+1]; // Returns the "removed" element
        }
     else throw-1 ; // If the array is empty, it will do this
}

int IntVector::at(int pos)  { // Function definition for at
    if (pos <= (currentSize)) // checks if pos is within the current size of the array
         return dArray[pos];
    else throw -1; // if pos is not within the size of the current array, it returns this
}

int IntVector::size() { // size functon definition
  return (currentSize+1); // returns the amount of elements that are currently in the array
}

int IntVector::capacity() { // capacity funciton definition
  return maxSize; // returns the maximize size the current array is capable of holding
}

bool IntVector::empty() { // empty function definition
  if (currentSize == -1) // Checks if the array is empty
     return 1; // returns true if the array is empty

  else
    return 0; // If the array is not empty, it will return false
}

void IntVector::insert(int data, int pos) { // insert function definiton
  if (currentSize == (maxSize-1)) // Checks if the array has space for an additional element
     {
        resizeArray(); // Calls the resizeArray() function to resize the array
     }

  if (pos == 0)  // If data is being placed at the begining
    {
        for (int i=currentSize;i>-1;i--) // this for loop shifts everything in the array to one space to the right to make room for the new data being inserted at the beginning of the array
            {
              dArray[i+1] = dArray[i];
            }
        dArray[0] = data; // Places the provided data into the first position of the array
        currentSize++; // Records this insert to keep track of the array size
    }

  else if (pos == currentSize+1) // If data is being placed at the end
             {
               dArray[pos] = data; // places the provided data at the provided position
               currentSize++;
             }

  else // If it's being placed in the middle
    {
       for (int i=currentSize;i>pos;i--)
           {
              dArray[i+1] = dArray[i]; // shifts all data one space to the right of the provided Position
           }
              dArray[pos] = data; // Places the provided data at the provided positon
              currentSize++; // Records this placement of data to keep track of the size of the array
    }
}

int IntVector::remove(int pos) { // remove function definiton

 if (pos< maxSize-1) // Checks if Position is valid
    {
      int returnInt; // This will store the integer that this function will return
      if (pos == 0)  // If it's the first number being removed
      {
          returnInt = dArray[0]; // Stores the first integer of the array in returnInt
          for (int i=0;i<currentSize-1;i++) // for loop shifts the entire array left, removing the first integer
              {
                dArray[i] = dArray[i+1];
              }
          currentSize--; // Records this removal of the integer to keep track of the size of the array
      }

      else if (pos == currentSize) // If it's being placed at the end
                 {
                   returnInt = dArray[pos]; // Stores the last integer in returnInt
                   dArray[pos] = NULL; // Sets the last integer to NULL
                   currentSize--; // Records this removal of the integer to keep track of the size of the array
                 }

      else // If it's being placed in the middle
           {
              returnInt = dArray[pos]; // Stores the integer at pos to returnInt
              for (int i=pos;i<currentSize+1;i--) // Shifts the array starting at positon pos to the left, removing the original value at positon pos
                  {
                     dArray[i] = dArray[i+1];
                  }
                     currentSize--; //Records this removal of the integer to keep track of the size of the array
           }
       return returnInt; // Now it returns returnInt which has the desired value stored
  }
  else throw-1; // If the submitted pos is out of range, function will return this
}

int IntVector::count(int data) { // count function definiton
    int counter=0; // Will keep track of how many times data apears in the array

    for (int i = 0; i <= currentSize; i++) { // this for loop will go through the array, and will record in int counter the number of times the submitted data appeared in the array
        {
           if (dArray[i] == data)
              {
                 counter++; // If there is a match, increase the counter to keep track of how many times data appeared in the array
              }
            else continue; // if not, continue with the for loop
        }
    }
    return counter; // After the for loop searches the array and records the number of times data apeared in the array, the function will return the counter
}
