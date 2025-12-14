import java.util.Scanner;

public class Problem304A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        int cnt = 0;
        for (long a = 1; a < n; a++) {
            for (long b = a; a * a + b * b <= (long) n * n; b++) {
                long cSquare = a * a + b * b;
                double c = Math.sqrt(cSquare);
                if ((long) c * c == cSquare)
                    cnt++;
            }
        }
        System.out.print(cnt);
    }
}
