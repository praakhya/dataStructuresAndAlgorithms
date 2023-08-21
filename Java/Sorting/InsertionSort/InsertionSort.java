package Sorting.InsertionSort;

class InsertionSort {
    private int[] array;
    public InsertionSort(int[] a) {
        array = a;
        for (int j=2; j<a.length-1; ++j) {
            int key=this.array[j];
            int i=j-1;
            while (i > 0 && this.array[i] > key) {
                this.array[i+1] = this.array[i];
                --i;
            }
            this.array[i] = key;
        }
        System.out.println(this.array);
    }
}