import java.io.*;
import java.util.*;

class Solution {
    static List<int[]> result = new ArrayList<>();
	static int[] apeach, ryan;
	static int N;
	static int max = 0;
	static int[] staticAnswer;
    
    public int[] solution(int n, int[] info) {
        apeach = info;
    	N = n;
    	ryan = new int[11];
        int[] answer = {};
        
  
        backtracking(0,0);
        
        if(max != 0) answer = getAnswer();
        else return new int[] {-1};
        
        return answer;
    }
    
    static int[] getAnswer() {
    	int[] arr = new int[11];
    	for(int i=10;i>-1;i--) {
    		for(int j=0;j<result.size();j++) {
    			if(result.get(j)[i] > arr[i]) return result.get(j);
    		}
    	}
    	return arr;
    }
    
    static void search(int[] ryan) {
    	int score = calculation();
    	if(score>0 && score >= max) {
            if(score>max) result.clear();
    		max = score;
    		// System.out.println(score+"@@@@@@@@@@@@@@@@@@@@@@@@@2");
    		result.add(ryan.clone());
    	}
    }
    
    static int calculation() {
    	int ryanScore = 0;
    	int apeachScore = 0;
    	
    	for(int i=0;i<11;i++) {
    		if(ryan[i]>apeach[i]) ryanScore += 10-i;
    		else if(apeach[i]!=0 && apeach[i]>=ryan[i]) apeachScore += 10-i;
    	}
    	
    	return ryanScore - apeachScore;
    }
    
    static void backtracking(int start, int cnt) {
    	if(cnt==N) {
    		// System.out.println(Arrays.toString(ryan));
    		search(ryan);
    		return;
    	}
    	
    	for(int i=start;i<10;i++) {
//    		System.out.println(N-cnt+"//"+apeach[i]);
    		
    		if(N-cnt>apeach[i]) {
    			ryan[i] = apeach[i]+1;
    			cnt += apeach[i]+1;
    			backtracking(i+1,cnt);
    			cnt -= apeach[i]+1;
    			ryan[i] = 0;
    		}
    	}
    	ryan[10] = N-cnt;
		cnt = N;
		backtracking(11,cnt);
		cnt -= ryan[10];
		ryan[10] = 0;
    	
    }
}