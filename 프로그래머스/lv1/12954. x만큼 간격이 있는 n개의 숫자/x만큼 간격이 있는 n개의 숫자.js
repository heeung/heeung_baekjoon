function solution(x, n) {
    let answer = [];
    let num = x;
    for (let i = 0 ; i < n ; i++) {
        answer[i] = x;
        x += num;
    }
    return answer;
}