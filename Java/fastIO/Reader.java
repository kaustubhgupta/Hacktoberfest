package fastIO;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;


public class Reader implements AutoCloseable {
	
	private File inputFile;
	private FileReader fr;
	private final int chunkSize; 
	private char[] currentChunk;
	private int parserAt = 0;
	private boolean hasStarted = false;
	private int bytesRead = -1; 
	private boolean isDone = false;
	
	/**
	 * 
	 * @param inputFile The file to read from.
	 * @throws FileNotFoundException If the file could not be found.
	 */
	
	public Reader(File inputFile) throws FileNotFoundException {
		this.chunkSize = 2048;
		this.inputFile = inputFile;
		this.fr = new FileReader(this.inputFile);
		this.currentChunk = new char[chunkSize];
	}
	
	/**
	 * 
	 * @param inputFile The file to read from.
	 * @throws FileNotFoundException If the file could not be found.
	 * 
	 */
	public Reader(String inputFile) throws FileNotFoundException {
		this(new File(inputFile));
	}
	
	/**
	 * 
	 * @param inputFile The file to read from.
	 * @param chunkSize The size of chunks that is used internally. Default is 2048. Bigger chunks will be faster for big files.
	 * @throws FileNotFoundException If the file could not be found.
	 * 
	 */
	
	public Reader(File inputFile, int chunkSize) throws FileNotFoundException {
		this.chunkSize = chunkSize;
		this.inputFile = inputFile;
		this.fr = new FileReader(this.inputFile);
		this.currentChunk = new char[chunkSize];

	}
	
	/**
	 * 
	 * @param inputFile The file to read from.
	 * @param chunkSize The size of chunks that is used internally. Default is 2048. Bigger chunks will be faster for big files.
	 * @throws FileNotFoundException If the file could not be found.
	 * 
	 */
	public Reader(String inputFile, int chunkSize) throws FileNotFoundException {
		this(new File(inputFile), chunkSize);
	}
	
	/**
	 * 
	 * @return Returns the entire file as String. More efficient than readLine();
	 * @throws IOException If there is an error reading the File.
	 * 
	 */
	public String readEntire() throws IOException {
		StringBuilder sb = new StringBuilder();
		currentChunk = new char[chunkSize];
		int charsRead;
		while((charsRead = fr.read(currentChunk)) != -1) {
			if(charsRead != chunkSize) {
				currentChunk = Arrays.copyOfRange(currentChunk, 0, charsRead);
			}
			sb.append(String.valueOf(currentChunk));
		}
		close();
		return sb.toString();
	}
	
	/**
	 * 
	 * @return Reads on line as String.
	 * @throws IndexOutOfBoundsException If there is no next line. Check with hasNextLine().
	 * @throws IOException If there is an error reading the File.
	 * 
	 */
	public String readLine() throws IndexOutOfBoundsException, IOException {
		if(isDone) throw new IndexOutOfBoundsException();
		
		if(!hasStarted) {
			bytesRead = readNewChunk(); 
			hasStarted = true;
		}
		
		// if a new chunk has to be read not, do it
		if(parserAt >= chunkSize-1) {
			bytesRead = readNewChunk(); 
			parserAt=0;
		}
		
		// if that chunk was exactly the first with no bytes, end reading
		if(bytesRead == -1) {
			isDone = true; 
			return "";
		}
		
		StringBuilder sb = new StringBuilder();
		// read loop
		while(true) {
			// as long as a chunk has to be read, read it
			for(; parserAt<bytesRead; parserAt++) {
				char currentChar = currentChunk[parserAt];
				// stop reading at each new line
				if(currentChar == '\n' || currentChar == '\r') {
					parserAt+= 2; 
					return sb.toString(); 
				}
				sb.append(currentChar);
			}
			// if chunk done, read new chunk
			bytesRead = readNewChunk();
			if(bytesRead == -1) {
				isDone = true; 
				close(); 
				return sb.toString();
			}
			parserAt=0;
		}
	}

	// internal method, reads new chunk
	private int readNewChunk() throws IOException {
		return fr.read(currentChunk);
	}
	
	/**
	 * 
	 * @return If the Reader has a next Line.
	 * 
	 */
	public boolean hasNextLine() {
		return !isDone;
	}
	
	
	/**
	 * 
	 * Closes the Reader
	 * 
	 */ 
	
	@Override
	public void close() {
		try {
			fr.close();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	
	
	
}
