import java.util.*;
import java.io.*;

class Solution {
    // static HashMap<String, Integer> map1, map2;
        
//     public int[] solution(String[] gems) {
//         int[] answer = {};
        
//         map1 = new HashMap<>();
//         map2 = new HashMap<>();
//         for (int i = 0; i < gems.length; i++){
//             if (!map1.containsKey(gems[i])) {
//                 map1.put(gems[i], 1);
//                 map2.put(gems[i], 1);
//             } else {
//                 map1.put(gems[i], map1.get(gems[i]) + 1);
//                 map2.put(gems[i], map2.get(gems[i]) + 1);
//             }
//         }
        
//         int left = 0;
//         int right = gems.length - 1;
        
//         int[] fromLeft = new int[2];
//         int[] fromRight = new int[2];
        
//         while (left < right) {
//             if (map1.get(gems[right]) > 1) {
//                 map1.put(gems[right], map1.get(gems[right]) - 1);
//                 right--;
//             } else if (map1.get(gems[left]) > 1) {
//                 map1.put(gems[left], map1.get(gems[left]) - 1);
//                 left++;
//             } else {
//                 // return new int[]{left + 1, right + 1};
//                 fromRight[0] = left + 1;
//                 fromRight[1] = right + 1;
//                 break ;
//             }
//         }
        
//         left = 0;
//         right = gems.length - 1;
        
//         while (left < right) {
//             if (map2.get(gems[left]) > 1) {
//                 map2.put(gems[left], map2.get(gems[left]) - 1);
//                 left++;
//             } else if (map2.get(gems[right]) > 1) {
//                 map2.put(gems[right], map2.get(gems[right]) - 1);
//                 right--;
//             } else {
//                 // return new int[]{left + 1, right + 1};
//                 fromLeft[0] = left + 1;
//                 fromLeft[1] = right + 1;
//                 break ;
//             }
//         }
//         System.out.println(fromLeft[0] + " " + fromLeft[1]);
//         System.out.println(fromRight[0] + " " + fromRight[1]);
        
//         if (fromRight[1] == 0) {
//             return new int[]{1, 1};
//         }
        
//         if (fromLeft[1] - fromLeft[0] == fromRight[1] - fromRight[0]) {
//             if (fromLeft[0] < fromRight[0]) {
//                 return fromLeft;
//             } else {
//                 return fromRight;
//             }
//         }
        
//         if (fromLeft[1] - fromLeft[0] > fromRight[1] - fromRight[0]) {
//             return fromRight;
//         } else {
//             return fromLeft;
//         }
//         // return new int[]{1, 1};
//     }
    static HashMap<String, Integer> map;
    static HashSet<String> sample;
    
    public int[] solution(String[] gems) {
        sample = new HashSet<>();
        map = new HashMap<>();
        
        for (int i = 0; i < gems.length; i++) {
            sample.add(gems[i]);
        }
        
        int[] answer = new int[2];
        
        int left = 0;
        int min = Integer.MAX_VALUE;
        for (int right = 0; right < gems.length; right++) {
            if (!map.containsKey(gems[right])) {
                map.put(gems[right], 1);
            } else {
                map.put(gems[right], map.get(gems[right]) + 1);
            }
            
            while (map.get(gems[left]) > 1) {
                map.put(gems[left], map.get(gems[left]) - 1);
                left++;
            }
            
            // 다 들어있다는 뜻
            if (map.size() == sample.size() && min > (right - left)) {
                min = Math.min(min, right - left);
                answer[0] = left + 1;
                answer[1] = right + 1;
            }
        }
        
        return answer;
    }
}