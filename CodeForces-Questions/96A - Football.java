import java.util.Scanner;

public class problem96A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		char c = s.charAt(0);
		int cnt = 1;
		int maxCnt = Integer.MIN_VALUE;
		for (int i = 1; i < s.length(); i++) {
			if (c == s.charAt(i)) {
				cnt++;
				maxCnt  = Integer.max(maxCnt, cnt);
			}
			else {
				cnt = 1;
				c = (c == '1') ? '0' : '1';
			}
		}
		if (maxCnt >= 7)
			System.out.println("YES");
		else
			System.out.println("NO");
		sc.close();
	}
}
