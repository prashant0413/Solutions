import java.util.*;

public class problem34B {

	public static void main(String[] args) {
		// input section
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int sets[] = new int[n];
		for (int i = 0; i < n; i++)
			sets[i] = sc.nextInt();

		// output section
    	Arrays.sort(sets);
		int earn = 0;
		for (int i = 0; i < n; i++) {
			if (sets[i] < 0) {
				earn += Math.abs(sets[i]);
				m--;
				if (m == 0)
					break;
			}
		}
		System.out.println(earn);
		sc.close();
	}
}
