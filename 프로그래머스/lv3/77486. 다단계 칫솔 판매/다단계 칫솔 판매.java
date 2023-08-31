import java.io.*;
import java.util.*;

class Solution {
    static class Node {
        int index, parent, money;
        String name;
        public Node(int index, int parent, int money, String name) {
            this.index = index;
            this.parent = parent;
            this.money = money;
            this.name = name;
        }
    }
    static Node[] people;
    static HashMap<String, Integer> map;
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        
        people = new Node[enroll.length + 1];
        people[0] = new Node(0, -1, 0, "minho");
        map = new HashMap<>();
        for (int i = 1; i <= enroll.length; i++) {
            String name = enroll[i - 1];
            
            map.put(name, i);
            people[i] = new Node(i, 0, 0, name);
        }
        
        for (int i = 1; i <= enroll.length; i++){
            String name = referral[i - 1];
            if (!name.contains("-")) {
                int parent = map.get(name);
                people[i].parent = parent;
            }
        }
        
        for (int i = 0; i < seller.length; i++) {
            int money = amount[i] * 100;
            int index = map.get(seller[i]);
            // System.out.println(index);
            while (true) {
                int parentMoney = money / 10;
                int myMoney = money - parentMoney;
                
                if (people[index].parent == -1) {
                    break ;
                }
                
                // people[people[index].parent].money += parentMoney;
                people[index].money += myMoney;
                index = people[index].parent;
                money = parentMoney;
            }
        }
        
        for (int i = 0; i < enroll.length; i++) {
            answer[i] = people[i + 1].money;
        }
        
        return answer;
    }
}