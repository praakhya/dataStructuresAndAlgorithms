package sorting;
import java.util.Scanner;
public class Main {
    public static void displayArr(int[] arr) {
        System.out.print("[ ");
        for (int i=0; i<arr.length; ++i) {
            System.out.print(arr[i]+" ");
        }
        System.out.println("]");
    }
    public static void main(String args[]) {
        int n=10;
        int[] a = new int[n];
        Scanner obj = new Scanner(System.in);
        for (int i=0; i<n; ++i) {
            a[i] = Integer.parseInt(obj.next());
        }
        InsertionSort sorter = new InsertionSort();
        displayArr(a);
        sorter.sort(a);
        displayArr(a);
        obj.close();
    }
}
