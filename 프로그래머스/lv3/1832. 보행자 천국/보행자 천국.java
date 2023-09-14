import java.io.*;
import java.util.*;

class Solution {
    int MOD = 20170805;
    static int[] di = {};
    static int[] dj = {};
    
    public int solution(int m, int n, int[][] cityMap) {
        int answer = 0;
        
        int[][][] dp = new int[2][m + 1][n + 1];
        
        dp[0][0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (cityMap[i][j] == 0) { // 다음 진행방향이 두가지를 수용 가능
                    
                    // 위에서 오던거랑 왼쪽에서 오던거 경우의 수를 합쳐버리면 됨
                    dp[0][i][j + 1] += (dp[0][i][j] + dp[1][i][j]) % MOD;
                    dp[1][i + 1][j] += (dp[0][i][j] + dp[1][i][j]) % MOD;
                    
                } else if (cityMap[i][j] == 2) { // 오던 방향으로만 수용 가능
                    
                    // 가로는 가로만 수용
                    dp[0][i][j + 1] += (dp[0][i][j]) % MOD;
                    // 세로는 세로만 수용
                    dp[1][i + 1][j] += (dp[1][i][j]) % MOD;
                    
                }
                
            }
        }
        
        answer = (dp[0][m - 1][n - 1] + dp[1][m - 1][n - 1]) % MOD;
        
        return answer;
    }
}