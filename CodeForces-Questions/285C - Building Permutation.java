import java.util.*;

public class Problem285C {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLong();
        }
        sc.close();
        long mini = 0;
        Arrays.sort(arr);
        for (int i = 0; i < n; i++) {
            mini += Math.abs(arr[i] - (i + 1));
        }
        System.out.println(mini);
    }
}
