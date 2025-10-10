import java.util.Scanner;

public class problem165A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] arr = new int[n][2];
		for (int i = 0; i < n; i++) {
			arr[i][0] = sc.nextInt();
			arr[i][1] = sc.nextInt();
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int x = arr[i][0];
			int y = arr[i][1];
			boolean upper = findUpper(arr, x, y);
			boolean lower = findLower(arr, x, y);
			boolean left = findLeft(arr, x, y);
			boolean right = findRight(arr, x, y);
			if (upper && lower && left && right)
				cnt++;
		}
		System.out.println(cnt);
		sc.close();
	}

	public static boolean findUpper(int[][] arr, int x, int y) {
		for (int i = 0; i < arr.length; i++) {
			if (x == arr[i][0] && y < arr[i][1])
				return true;
		}
		return false;
	}

	public static boolean findLower(int[][] arr, int x, int y) {
		for (int i = 0; i < arr.length; i++) {
			if (x == arr[i][0] && y > arr[i][1])
				return true;
		}
		return false;
	}

	public static boolean findLeft(int[][] arr, int x, int y) {
		for (int i = 0; i < arr.length; i++) {
			if (x < arr[i][0] && y == arr[i][1])
				return true;
		}
		return false;
	}

	public static boolean findRight(int[][] arr, int x, int y) {
		for (int i = 0; i < arr.length; i++) {
			if (x > arr[i][0] && y == arr[i][1])
				return true;
		}
		return false;
	}
}
