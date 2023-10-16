import java.io.*;
import java.util.*;

class Solution {
    static class Node {
        Node prev = null;
        Node next = null;
        boolean removed;

        public Node movePrev(int movement) {
            Node node = this;
            for (int i = 0; i < movement; i++) {
                node = node.prev;
            }
            return node;
        }
        public Node moveNext(int movement) {
            Node node = this;
            for (int i = 0; i < movement; i++) {
                node = node.next;
            }
            return node;
        }
        public Node delete() { // 삭제 후 재연결
            this.removed = true;
            Node prev = this.prev;
            Node next = this.next;

            if (prev != null) {
                prev.next = next;
            }
            if (next != null) {
                next.prev = prev;
                return next;
            }
            return prev;
        }
        public void restore() {
            this.removed = false;
            Node prev = this.prev;
            Node next = this.next;

            if (prev != null) {
                prev.next = this;
            }
            if (next != null) {
                next.prev = this;
            }
        }
    }
    public String solution(int n, int k, String[] cmd) {
        Stack<Node> deleteRows = new Stack<>();
        Node[] nodes = new Node[n];

        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();

            if (i == 0) {
                continue;
            }

            nodes[i - 1].next = nodes[i];
            nodes[i].prev = nodes[i - 1];
        }

        Node current = nodes[k];

        for (String command : cmd) {
            char operation = command.charAt(0);

            if (operation == 'U') {
                int movement = Integer.parseInt(command.split(" ")[1]);
                current = current.movePrev(movement);
            }
            if (operation == 'D') {
                int movement = Integer.parseInt(command.split(" ")[1]);
                current = current.moveNext(movement);
            }
            if (operation == 'C') {
                deleteRows.add(current); // delete 스택에 추가
                current = current.delete();
            }
            if (operation == 'Z') {
                Node node = deleteRows.pop(); // delete 스택에서 빼서 붙이기
                node.restore();
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (nodes[i].removed) {
                sb.append("X");
                continue ;
            }
            sb.append("O");
        }

        return sb.toString();
    }
}