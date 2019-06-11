package combination;

public class combination {

	public static void main(String[] args) {
		int stair = 5;
		int jump = 2;
		System.out.println("Differant ways you can climb a stair with " + stair + " steps while climbing 1 or " +jump + " stairs at a time is: "  + calculateN(stair,jump));
		
		

	}
	// for 1 and 2 , n basamak 
	
	public static int calculateN (int n, int step) {
		
		int placeholder=0;
		int a = n / step ;
		
		while(a >= 0) {
			int pay =factorial((n-(step*a))+a);
			int payda =  factorial(a) * factorial((n-(step*a)));
			int result = pay/payda;
			placeholder = placeholder+ result;
			a--;
		}
		return placeholder;
	}
	
	
	
	
		
	public static int factorial(int number) {
		int result = 1;

	    for (int factor = 2; factor <= number; factor++) {
	    	result *= factor;
	    }

	    return result;
	}
	
	
	
}
