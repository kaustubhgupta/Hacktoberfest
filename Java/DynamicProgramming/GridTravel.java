import java.util.Scanner;

public class GridTravel {
    
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);

        int rows=sc.nextInt();
        int cols=sc.nextInt(); //rows and columns input

        int arr[][]=new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j]=0;
            }
        }
        int way[][]=new int[rows+1][cols+1]; //DP array

		//initializing with 0
        for (int i = 0; i < rows+1; i++) {
            for (int j = 0; j < cols+1; j++) {
                way[i][j]=0;
            }
        }

        int result=gridTravel(rows, cols, way);

        System.out.println(result);
        sc.close();
    }
    
    static int gridTravel(int rows,int cols,int [][] way){
		//if row and column==1 then only one way can be there
        if(rows==1 && cols==1){
            return 1;
        }
		//if row and column==0then no way can be there
        else if(rows==0 || cols==0){
            return 0;
        }

		//if array has previous entries then return it
        if(way[rows][cols]>0){
            return way[rows][cols];
        }

		//calculate current from previous cells
        way[rows][cols]=gridTravel(rows-1, cols, way) + gridTravel(rows, cols-1, way);
        return way[rows][cols];
    }
}
