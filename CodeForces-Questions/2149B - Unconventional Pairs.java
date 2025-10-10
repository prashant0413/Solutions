import java.util.Arrays;
import java.util.Scanner;
 
public class unconventionalPairs {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int K = 0; K < t; K++) {
			int n = sc.nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = sc.nextInt();
			int maxDiff = Integer.MIN_VALUE;
			Arrays.sort(arr);
			for (int i = 0; i < n; i += 2) {
				int diff = Math.abs(arr[i] - arr[i + 1]);
				if (diff > maxDiff)
					maxDiff = diff;
			}
			System.out.println(maxDiff);
		}
		sc.close();
	}
}
