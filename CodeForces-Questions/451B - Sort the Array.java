// Approach 1
// TC = O(nlog(n))
// SC = O(1)

import java.util.*;

public class Main {
    public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int[] arr = new int[n];
      for (int i = 0; i < n; i++)
        arr[i] = sc.nextInt();
      
      int st = -1;
      int en = -1;
      for (int i = 1; i < n; i++) {
        if (st != -1 && arr[i] > arr[i - 1])
          break;

        if (arr[i] < arr[i - 1]) {
          if (st == -1)
            st = i - 1;
          en = i;
        }
      }

      if (st == -1) {
        System.out.println("yes\n" + 1 + " " + 1);
        return;
      }

      Arrays.sort(arr, st, en + 1);
      boolean isSorted = true;
      for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
          isSorted = false;
          break;
        }
      }

      System.out.println((isSorted) ? "yes\n" + (st + 1) + " " + (en + 1) : "no");
    }
}
