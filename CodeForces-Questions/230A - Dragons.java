import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class program230A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int s = sc.nextInt();
		int n = sc.nextInt();
		int dragons[][] = new int[n][2];
		for (int i = 0; i < n; i++) {
			dragons[i][0] = sc.nextInt();
			dragons[i][1] = sc.nextInt();
		}
		Arrays.sort(dragons, new Comparator<int []>() {
			@Override
			public int compare(int[] r1, int [] r2) {
				return r1[0] - r2[0];
			}
		});
		boolean flag = true;
		for (int i = 0; i < n; i++) {
			if (s > dragons[i][0]) {
				s += dragons[i][1];
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag)
			System.out.println("YES");
		else
			System.out.println("NO");
		sc.close();
	}
}
