package sorting;

class InsertionSort implements Sort{
    @Override
    public void sort(int[] array) {
        for (int j=1; j<array.length; ++j) {//The outer loop controls the size of the unsorted part of the array.
            int key=array[j];               //Value of the current number that has to be placed in the correct position               
            int i=j-1;                      //This index is the max limit for the set of sorted numbers
            while (i >= 0 && array[i] > key) {  //Iterate through the sorted numbers to find the position of the 'key'
                array[i+1] = array[i];      //Shifting a value to the right
                --i;
            }
            array[i+1] = key;               //The place that becomes vacant after shifting numbers to the right is filled with the 'key'
        }
    }
}