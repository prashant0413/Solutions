// Approach 1
// TC = O(N)
// SC = O(1)
import java.util.Scanner;

public class Problem327A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int num;
        int maxi = Integer.MIN_VALUE;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            num = sc.nextInt();
            if (num == 0)
                sum++;
            else {
                cnt++;
                sum--;
            }
            maxi = Integer.max(sum, maxi);
            if (sum < 0)
                sum = 0;
        }
        System.out.println(maxi + cnt);
        sc.close();
    }
}
