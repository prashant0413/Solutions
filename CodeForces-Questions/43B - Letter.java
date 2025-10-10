import java.util.Scanner;

public class problem43B {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s1 = sc.nextLine();
		String s2 = sc.nextLine();
		sc.close();
		
		int[] lowCnt = new int[26];	
		int[] upCnt = new int[26];	
		
		for (int i = 0; i < s1.length(); i++) {
			char c = s1.charAt(i);
			if (c >= 'a' && c <= 'z') {
				lowCnt[c - 'a']++;
			} else if (c >= 'A' && c <= 'Z') {
				upCnt[c - 'A']++;
			}
		}
		
		boolean isPossible = true;
		for (int i = 0; i < s2.length(); i++) {
			char c = s2.charAt(i);
			if (c >= 'A' && c <= 'Z') {
				if (upCnt[c - 'A'] < 1) {
					isPossible = false;
					break;
				} else {
					upCnt[c - 'A']--;
				}
			} else if (c >= 'a' && c <= 'z') {
				if (lowCnt[c - 'a'] < 1) {
					isPossible = false;
					break;
				} else {
					lowCnt[c - 'a']--;
				}
			}
		}
		System.out.println((isPossible) ? "YES" : "NO");
	}
}
