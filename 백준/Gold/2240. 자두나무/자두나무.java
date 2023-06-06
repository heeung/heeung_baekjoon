import java.io.*;
import java.util.*;

public class Main {
	static int T, W;
	static int[] treeNums;
	static int[][] dp;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		T = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());
		
		treeNums = new int[T + 1];
		dp = new int[T + 1][W + 1];
		
		for (int i = 1; i <= T; i++) {
			treeNums[i] = Integer.parseInt(br.readLine());
		}
		
		solve();
		
		int ret = 0;
		for (int i = 0; i <= W; i++) {
			ret = Math.max(ret, dp[T][i]);
		}
		
		System.out.println(ret);
	}

	static void solve() {
		for (int i = 1; i <= T; i++) {
			dp[i][0] = (treeNums[i] == 1) ? dp[i - 1][0] + 1 : dp[i - 1][0];
			
			int possibleMove = (i < W) ? i : W;
			for (int j = 1; j <= possibleMove; j++) {
				int plum = 0;
				if ((treeNums[i] == 2 && j % 2 == 1) || (treeNums[i] == 1 && j % 2 == 0)) {
					plum = 1;
				}
				
				int change = dp[i - 1][j - 1] + plum;
				int notChange = dp[i - 1][j] + plum;
				dp[i][j] = Math.max(change, notChange);
			}
		}
	}
}