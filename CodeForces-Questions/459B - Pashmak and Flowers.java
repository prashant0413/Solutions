import java.util.Arrays;
import java.util.Scanner;

public class program459B {
    
    // Find first occurrence of x
    public static int firstOccurrence(int x, int[] arr, int n) {
        int res = -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int m = (left + right) >> 1;
            if (arr[m] == x) {
                res = m;
                right = m - 1; // keep searching left
            } else if (arr[m] < x) {
                left = m + 1;
            } else {
                right = m - 1;
            }
        }
        return res;
    }
    
    // Find last occurrence of x
    public static int lastOccurrence(int x, int[] arr, int n) {
        int res = -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int m = (left + right) >> 1;
            if (arr[m] == x) {
                res = m;
                left = m + 1; // keep searching right
            } else if (arr[m] < x) {
                left = m + 1;
            } else {
                right = m - 1;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        sc.close();
        
        Arrays.sort(arr);
        int diff = arr[n - 1] - arr[0];

        int firstMin = firstOccurrence(arr[0], arr, n);
        int lastMin = lastOccurrence(arr[0], arr, n);
        int cntMin = lastMin - firstMin + 1;

        int firstMax = firstOccurrence(arr[n - 1], arr, n);
        int lastMax = lastOccurrence(arr[n - 1], arr, n);
        int cntMax = lastMax - firstMax + 1;

        long ways;
        if (diff == 0) {
            ways = (long) n * (n - 1) / 2;
        } else {
            ways = (long) cntMin * cntMax;
        }

        System.out.println(diff + " " + ways);
    }
}
