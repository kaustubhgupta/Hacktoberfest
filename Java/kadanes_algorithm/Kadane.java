package kadanes_algorithm;

public class Kadane {

	public static void main(String[] args) {
		System.out.println(solution("2,3,-2,-1,10"));
	}
	
	static int solution(String str) {
		
		String[] numbers = str.split(",");
        int maxSoFar = 0;
        int maxEndingHere = 0;
        
        for (int i = 0; i < numbers.length; i++) {
             maxEndingHere = maxEndingHere + Integer.parseInt(numbers[i]);
             
             if (maxEndingHere < 0) {
            	 maxEndingHere = 0;
             }
             
             if (maxSoFar < maxEndingHere) {
            	 maxSoFar = maxEndingHere;
             }
        }
		
		return maxSoFar;
	}
}

