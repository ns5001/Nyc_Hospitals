#ifndef intVector_h
#define intVector_h

class IntVector { // The vector class

    private:
    int *dArray; // pointer
    int maxSize; // the maximum number of variables the array can hold
    int currentSize; // the position in the array of the last variable in the array
    void resizeArray(); // Create new array double the size of the current array

    public:
      IntVector(); // Constructor
      void push_back(int data); // Add a new element "data" at the end of the array
      int pop_back(); // Removes and returns the last element in the array
      int at(int pos); // Returns the element at position pos in the array
      int size(); // Returns the current number of elements in the array
      int capacity(); //Returns the maximum number of variables the array can hold
      bool empty(); // Returns whether the array is empty or not
      void insert(int data, int pos); // Adds a new element "Data" to the array at position "Pos"
      int remove(int pos); // Removes and returns the element at position "pos"
      int count(int data); // Returns the number of times "Data" exists in the array
};


#endif
