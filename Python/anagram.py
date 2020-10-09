CHARS=26
def remAnagram(str1, str2): 
    count1 = [0]*CHARS 
    count2 = [0]*CHARS 
    i = 0
    while i < len(str1): 
        count1[ord(str1[i])-ord('a')] += 1
        i += 1
  
    i =0
    while i < len(str2): 
        count2[ord(str2[i])-ord('a')] += 1
        i += 1
  
    result = 0
    for i in range(26): 
        result += abs(count1[i] - count2[i]) 
    return result 
  
# Driver program to run the case 
if __name__ == "__main__": 
    str1 = "bcadeh"
    str2 = "hea"
    print(remAnagram(str1, str2)) 
