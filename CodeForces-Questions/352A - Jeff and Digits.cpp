import java.util.*;

public class problem352A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        int cnt5 = 0;
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 5) {
                cnt5++;
            } else {
                cnt0++;
            }
        }
        if (cnt0 == 0) {
            System.out.println("-1");
            return;
        }
        while (true) {
            if (fsum(cnt5 * 5) % 9 == 0)
                break;
            cnt5--;
        }

        StringBuilder str = new StringBuilder();
        for (int i = 0; i < cnt5; i++) {
            str.append("5");
        }
        for (int i = 0; i < cnt0; i++) {
            if (str.length() == 0) {
                str.append("0");
                break;
            }
            str.append("0");
        }
        System.out.println(str);
    }

    static int fsum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
}
