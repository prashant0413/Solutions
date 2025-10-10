import java.util.Scanner;

public class problem214A {

	public static void main(String[] args) {
		// input section
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		sc.close();
		
		// output section
		int cnt = 0;
		for (int i = 0; i <= Math.max(n,m) + 1; i++) {
			int j = n - i * i;
			if (j >= 0 && (i + j * j) == m)
				cnt++;
		}
		System.out.println(cnt);
	}
}
