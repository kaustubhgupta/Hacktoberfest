package fastIO;

import java.io.IOException;
import java.util.Arrays;

public class WriterTest {
	
	public static void main(String[] args) throws IOException {
		
		// writes a string to a file and then gets it again
		
		String before = "Fast IO for Java #91";
		String file = "Java/fastIO/writeTest.txt";
		
		Writer w = new Writer(file);
		w.writeOnce(before);
		
		Reader r = new Reader(file);
		String after = r.readEntire();
		
		System.out.println(Arrays.toString(before.getBytes()));
		System.out.println(Arrays.toString(after.getBytes()));
		
		System.out.println(before.equals(after));
		
	}

}
