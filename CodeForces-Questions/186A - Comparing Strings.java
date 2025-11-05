import java.util.Scanner;

public class Problem186A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		sc.close();
		if (s1.length() != s2.length()) {			
			System.out.println("NO");
			return;			
		}
		int[] arr = new int[26];
		for (int i = 0; i < s1.length(); i++) {
			arr[s1.charAt(i) - 'a']++;
		}
		for (int i = 0; i < s2.length(); i++) {
			arr[s2.charAt(i) - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] != 0) {
				System.out.println("NO");
				return;	
			}
		}
		int cnt = 0;
		for (int i = 0; i < s1.length(); i++) {
			if (s1.charAt(i) != s2.charAt(i))
				cnt++;
		}
		System.out.println((cnt / 2 == 1) ? "YES" : "NO");
	}
}
