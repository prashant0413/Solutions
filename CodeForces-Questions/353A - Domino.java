import java.util.Scanner;

public class Problem353A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[][] = new int[n][2];
        long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            arr[i][0] = sc.nextInt();
            arr[i][1] = sc.nextInt();
            sum1 += arr[i][0];
            sum2 += arr[i][1];
        }
        sc.close();
        if ((sum1 & 1) == 0 && (sum2 & 1) == 0) {
            System.out.println(0);
            return;
        }
        if (((sum1 & 1) != 0 && (sum2 & 1) == 0) || ((sum1 & 1) == 0 && (sum2 & 1) != 0)) {
            System.out.println(-1);
            return;
        } else {
            for (int i = 0; i < n; i++) {
                if (arr[i][0] % 2 != 0 && arr[i][1] % 2 == 0) {
                    System.out.println(1);
                    return;
                }
                if (arr[i][0] % 2 == 0 && arr[i][1] % 2 != 0) {
                    System.out.println(1);
                    return;
                }
            }
        }
        System.out.println(-1);
    }
}
