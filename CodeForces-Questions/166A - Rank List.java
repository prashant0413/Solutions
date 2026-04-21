// Approach 1
// TC = O(nlog(n))
// SC = O(n)
import java.util.Arrays;
import java.util.Scanner;

public class Problem166A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int arr[][] = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = sc.nextInt();
            arr[i][1] = sc.nextInt();
        }
        Arrays.sort(arr, (a, b) -> {
            if (a[0] != b[0])
                return Integer.compare(b[0], a[0]);
            return Integer.compare(a[1], b[1]);
        });

        int[] t1 = arr[k - 1];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (t1[0] > arr[i][0])
                break;
            if (arr[i][0] == t1[0] && arr[i][1] == t1[1])
                cnt++;
        }
        System.out.println(cnt);
    }
}
