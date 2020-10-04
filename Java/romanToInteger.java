//A simple java code using hashmap to convert roman numbers given in string format to integer number system

class Solution {
    public int romanToInt(String s) 
    {
        String roman=new String(s);
        int i,sum=0;
        String I="1" , V="5" , X="10" , L="50", C="100",D="500", M="1000" ;
        
       Map <Character, Integer> num = new HashMap<>();
        num.put('I',1);
        num.put('V',5);
        num.put('X',10);
        num.put('L',50);
        num.put('C',100);
        num.put('D',500);
        num.put('M',1000);
        
        for(i=0;i<s.length();i++)
        {
            if( i<s.length()-1 && num.get(s.charAt(i))<num.get(s.charAt(i+1)) )
            {
                sum=sum - num.get(s.charAt(i)) + num.get(s.charAt(i+1)) ;
                ++i;
            }
            else
            {
                sum=sum+num.get(s.charAt(i));
            }
        }
        
        return sum;
    }
}
