import java.util.*;

public class problem227B {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr1 = new int[n];
		for (int i = 0; i < n; i++) {
			arr1[i] = sc.nextInt();
		}
		int m = sc.nextInt();
		int[] arr2 = new int[m];
		for (int i = 0; i < m; i++) {
			arr2[i] = sc.nextInt();
		}
		HashMap<Integer, Integer> mpp = new HashMap<>();
		for (int i = 0; i < n; i++) {
			mpp.put(arr1[i], i);
		}
		long cntF = 0l;
		long cntB = 0;
		for (int i = 0; i < m; i++) {
			long v = mpp.get(arr2[i]) + 1;
			long p = n - mpp.get(arr2[i]);

			cntF += v;
			cntB += p;
		}
		System.out.println(cntF + " " + cntB);
		sc.close();
	}
}
