/*Problem Statement : 

Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, 
obeying the following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is
the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.

Time complexity : O(2^n)

*/

public class TowerOfHanoi {
    public static void HanoiProblem(int n,char rodFrom,char middleRod,char rodTo)
    {
        if(n==1)
        {
            System.out.println("Transfer rod "+n+" from "+rodFrom+" to "+rodTo);
            return;
        }
         HanoiProblem(n-1,rodFrom,rodTo ,middleRod);
         System.out.println("Transfer rod "+n+" from "+rodFrom+" to "+rodTo);
         HanoiProblem(n-1,middleRod,rodFrom,rodTo);
    }
    public static void main(String x[])
    {
        HanoiProblem(3,'A','B','C');
    }
    
}
