import java.util.*;

class Solution {
	
	static int[] apeach;
	static int[] ans = {-1};
	static int N, max, lionPoint, apeachPoint, diff;
	
    public int[] solution(int n, int[] info) {
        
        apeach = info;
        N = n;
        max = Integer.MIN_VALUE;
        combination(new int[11], 0, 0);
        
        System.out.println(Arrays.toString(ans));
        return ans;
    }
    
    public static void combination(int[] comb, int arrow, int idx) {
    	if (arrow == N) {
    		getPoints(comb);
    		if (lionPoint > apeachPoint) {
    			if (max <= lionPoint - apeachPoint) {
    				ans = comb.clone();
    				max = Math.max(lionPoint - apeachPoint, max);
    			}
    		}
    		return ;
    	}
    	
    	
    	for (int i = 0; i < 11 && comb[i] <= apeach[i]; i++) {
    		comb[i]++;
    		combination(comb, arrow + 1, i);
    		comb[i]--;
    	}
    	
    }
    
    public static void getPoints(int[] comb) {
    	lionPoint  = 0;
		apeachPoint = 0;
		for (int i = 0; i < 11; i++) {
			if (apeach[i] != 0 || comb[i] != 0) {
				if (apeach[i] < comb[i])
					lionPoint += 10 - i;
				else
					apeachPoint += 10 - i;
			}
		}
    }
}