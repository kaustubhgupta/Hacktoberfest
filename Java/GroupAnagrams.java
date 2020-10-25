
//https://leetcode.com/problems/group-anagrams
import java.util.*;

class GroupAnagrams {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> list = new ArrayList<>();
        Map<Integer, List<String>> map = new HashMap<Integer, List<String>>();
        for (String a : strs) {
            int abc = getHash(a);
            if (map.containsKey(abc)) {
                map.get(abc).add(a);
            } else {
                List<String> b = new ArrayList<String>();
                b.add(a);
                list.add(b);
                map.put(abc, b);
            }
        }
        return list;
    }

    private final int[] PRIMES = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
            83, 89, 97, 101 };

    private int getHash(String str) {
        int hash = 1;
        for (char a : str.toCharArray()) {
            hash *= PRIMES[a - 'a'];
        }
        return hash;
    }

    public static void main(String args[]) {
        GroupAnagrams obj = new GroupAnagrams();
        String strs[] = new String[] { "eat", "tea", "tan", "ate", "nat", "bat" };
        System.out.print(obj.groupAnagrams(strs));
    }
}