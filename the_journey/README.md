
#one_block
Valid One Block Partitions

You are part of the resource distribution team in your company, where resource values are analyzed in contiguous groups. A One Block is defined as a continuous segment of the array whose total sum is exactly 1.

You are given an afray Arr of size N, where each element may be positive,negative, or zero, Your task is to determine how many ways the entire array can be partitioned into continuous, non-overlapping blocks such that every block is a One Block.

Each partition must satisfy the following:
• Every element of the array must belong to exactly one block
• Blocks must be contiguous
• The sum of each block must be exactly 1
If no such valid partition exists, return -1.

Function Description:
Complete the function 'OneBlock().
This function takes the following 2 parameters and returns the required answer.
Parameters
• N: Inteder renresentina the number of resources, Arr: Vector of integers representing the value of resources
Return Value
• Return an integer iépresenting the number of ways to divide the afray into continuous non overlapping blocks such that every block is a One Block To
• Return -1 if no such partition is possible

Input Format
• The first line contains an integer N, denoting the number of resources
• The second line contains N space-separated integers denoting the values in Arr

Output Format
• Print a sinale integer representing the number of valid ways to partition the array into One Block
• Print -1 if no valid partition exists

Constraints:
• 1 ≤ N ≤ 1000
• -500 ≤ Arr[i] ≤ 500

Sample Input 1
6
2 -1 0 1 -1 2
Sample Output 1
2

Explanation
[2,-1] + [0,1] + [-1,2] = [1] + [1] + [1] [USE]
[2,-1,0] + [1] + [-1,2] = [1] + [1] + [1] [USE]
[2] + [-1, 0, 1] + [-1, 2] = [2] + [0] + [1] [CANNOT USE]
[2, - 1, 0, 1] + [-1, 2] = [2] + [1] [CANNOT USE]
[2, -1, 0, 1, -1] + [2] = [1] + [2]  [CANNOT USE]

Note: Your code must be able to print the sample output from the provided sample input.However, your code is run against multiple hidden test cases. Therefore, your code must pass these hidden test cases to solve the problem statement.

Limits
Time Limit: 1.0 sec(s) for each input file
Memory Limit: 256 MB
Source Limit: 1024 KB