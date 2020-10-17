def strreverse(s): 
	if len(s) == 0: 
		return s 
	else: 
		return strreverse(s[1:]) + s[0] 

s = "Mustafa"

print ("The original string is : ",end="") 
print (s) 

print ("The reversed string(using recursion) is : ",end="") 
print (strreverse(s)) 
