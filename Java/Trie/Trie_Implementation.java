import java.util.Scanner;

public class Trie_Implementation {

	static final int size = 26; 
    
    // Trie Node class
    static class TrieNode 
    { 
        TrieNode[] children = new TrieNode[size]; 
       
        boolean Terminating; 
          
        TrieNode(){ 
        	Terminating = false; 
            for (int i = 0; i <size; i++) 
                children[i] = null; 
        } 
    }; 
       
    static TrieNode root;  
      
    // If not present, inserts key into trie 
    // If the key is prefix of trie node,  
    // just marks leaf node 
    static void insert(String key) 
    { 
        TrieNode node = root; 
       
        for (int i = 0; i < key.length(); i++) 
        { 
            int index = key.charAt(i) - 'a'; 
            if (node.children[index] == null) 
                node.children[index] = new TrieNode(); 
       
            node = node.children[index]; 
        } 
       
        
       node.Terminating = true; // marks last node as leaf node
    } 
       
    // function that returns true if key is present in trie
    static boolean search(String key) 
    { 
        TrieNode node = root; 
       
        for (int i = 0; i < key.length(); i++) 
        { 
            int index = key.charAt(i) - 'a'; 
       
            if (node.children[index] == null) 
                return false; 
       
            node = node.children[index]; 
        } 
       
        return (node != null && node.Terminating); 
    } 
       
    // main function 
    public static void main(String args[]) 
    { 
    	Scanner s = new Scanner(System.in);
        root = new TrieNode(); 
       
        char c;
        System.out.println("--Trie Implementation--");
        
        // do-while loop to take input from user
        do {
        System.out.println("(a)Insert word\n(b)Search word");
        System.out.print("Option (a/b) : ");
        char ch = s.next().charAt(0);
        s.nextLine();
        
        if(ch== 'a')
        {	
        	System.out.print("Enter word to be inserted : ");
        	String str = s.nextLine();
        	insert(str);
        	System.out.println("Inserted");
        }	
        else if(ch=='b')
        {	System.out.print("Enter word to be searched : ");
        	String str = s.nextLine();
			if(search(str)==true)
				System.out.println("Word is present!");
			else
				System.out.println("Word is not present!");
        }
        else
		{	System.out.println("Invalid option!");
        }
        
        System.out.print("Continue? (y/n) : ");
        c = s.next().charAt(0);
    }while(c =='y');
        	
         
    } 
}
