class Main {
	public static void main(String[] args) {
		String name ="Hello World";//String to printed n times
		String str = "x"; //Dummy variabale used to define the number n to be printed

		str = str.replaceAll("x", "xxxxxxxxxx"); // first substition to get 10 prints
		// str = str.replaceAll("x", "xxxxxxxxxx"); // second substition to get 100 prints
		// str = str.replaceAll("x", "xxxxxxxxxx"); // Third substition to get 1000 prints
		str = str.replaceAll("x", name + "\n"); // Substituting all the 'x' by the value in 'name'
		System.out.println(str);
	}
}