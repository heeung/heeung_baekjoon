function solution(n)
{
    let answer = 0;
    
    while (n)
    {
        answer = (n % 10) + answer;
        n = parseInt(n / 10);
    }
    return answer;
}