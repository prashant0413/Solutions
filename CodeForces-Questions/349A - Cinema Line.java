import java.util.*;

public class Problem349A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        int cash25 = 0;
        int cash50 = 0;
        int cash100 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 100) {
                cash100++;
                if (cash50 != 0 && cash25 != 0) {
                    cash50--;
                    cash25--;
                } else if ((cash50 != 0 && cash25 == 0) || (cash50 == 0 && cash25 < 3)) {
                    System.out.println("NO");
                    return;
                } else {
                    cash25 -= 3;
                }
            } else if (arr[i] == 50) {
                cash50++;
                if (cash25 == 0) {
                    System.out.println("NO");
                    return;
                } else {
                    cash25--;
                }
            } else {
                cash25++;
            }
        }
        System.out.println("YES");
        sc.close();
    }
}
