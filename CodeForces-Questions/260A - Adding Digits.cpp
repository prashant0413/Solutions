// Approach 1
// TC = O(N)
// SC = O(N)
import java.util.Scanner;

public class Problem260A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int n = sc.nextInt();

        boolean exits = false;
        for (int i = 0; i <= 9; i++) {
            if ((a * 10 + i) % b == 0) {
                exits = true;
                System.out.print(a * 10 + i);
                StringBuilder str = new StringBuilder();
                str.repeat('0', n - 1);
                System.out.println(str);
                break;
            }
        }

        if (!exits)
            System.out.println(-1);
    }
}
