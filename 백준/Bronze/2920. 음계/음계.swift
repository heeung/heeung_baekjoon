let input = readLine()!.split(separator: " ")

if input == input.sorted()
{
    print("ascending")
}
else if input == input.sorted(by: >)
{
    print("descending")
}
else
{
    print("mixed")
}