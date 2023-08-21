package Sorting;
import java.util.Scanner;
public class Main {
    public static void main(String args[]) {
        int n=10;
        int[] a = new int[n];
        Scanner obj = new Scanner(System.in);
        for (int i=0; i<n; ++i) {
            a[i] = Integer.parseInt(obj.next());
        }
        System.out.println(a);
        InsertionSort(a);
        obj.close();

    }
}
