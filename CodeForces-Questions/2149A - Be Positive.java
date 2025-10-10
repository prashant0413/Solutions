import java.util.Scanner;
 
public class bePositive {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int j = 0; j < t; j++) {
			int n = sc.nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = sc.nextInt();
			
			int zero = 0;
			int minusOne = 0;
			for (int i = 0; i < n; i++) {
				if (arr[i] == 0) {
					zero++;
				} else if (arr[i] == -1) {
					minusOne++;
				}
			}
			
			int minOp = zero + (minusOne % 2) * 2;
			System.out.println(minOp);
		}
		sc.close();
	}
}
