import java.util.Scanner;

public class countmasepath {

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();

		int[][] strg = new int[n+1][n+1];
		System.out.println(countMazepath(n, n, 0, 0, strg));
		for(int i=0;i<strg.length;i++) {
			for(int j=0;j<strg.length;j++) {
				if(strg[i][j]/10==0) {
				System.out.print(strg[i][j]+"   ");
				}else {
					System.out.print(strg[i][j]+"  ");
					
				}
			}
			System.out.println();
		}
	}

	public static int countMazepath(int er, int ec, int cr, int cc, int[][] strg) {
		if (er == cr && ec == cc) {
			return 1;
		}

		if (cr > er || cc > ec) {
			return 0;
		}
		if (strg[cr][cc] != 0) {
			return strg[cr][cc];
		}
		int mycount = 0;
		mycount = countMazepath(er, ec, cr, cc + 1, strg) + countMazepath(er, ec, cr + 1, cc, strg);
		strg[cr][cc] = mycount;
		
		return mycount;
		}
	

}
