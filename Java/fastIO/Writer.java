package fastIO;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Writer implements AutoCloseable {
	
	private File outputFile;
	private FileWriter fw;
	

	/**
	 * 
	 * @param outputFile The file to write to.
	 * @throws RuntimeException Wrapped IOException. Error writing to the file.
	 * 
	 */
	
	public Writer(File outputFile) {
		this.outputFile = outputFile;
		try {
			this.fw = new FileWriter(this.outputFile);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	
	/**
	 * 
	 * @param outputFile The file to write to.
	 * @throws IOException Error writing to the file.
	 * 
	 */
	
	public Writer(String outputFile) {
		this(new File(outputFile));
	}
	
	
	/**
	 * @param out The String to write.
	 * @throws RuntimeException Wrapped IOException. Error writing to the file.
	 */
	
	public void write(String out) {
		try {
			fw.write(out);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	
	/**
	 * Writes a String and then closes the writer
	 * @param The String to write
	 * 
	 */
	public void writeOnce(String out) {
		write(out);
		close();
	}
	
	/**
	 * 
	 * Closes the Writer
	 * 
	 */ 
	
	public void close() {
		try {
			fw.close();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	
}
