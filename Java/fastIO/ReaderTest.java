package fastIO;

import java.io.IOException;

public class ReaderTest {
	
	public static void main(String[] args) throws IOException {
		
		// reads the specified file
		Reader reader2 = new Reader("Java/fastIO/text.txt", 2048);
		while(reader2.hasNextLine()) {
			System.out.println(reader2.readLine());
		}
		
	}

}
