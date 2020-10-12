#author Matteo Messmer https://github.com/matteomessmer

#to simplify the function
def strSubsets(original):
    return strSubsetsRecursive(original, '', [''])

def strSubsetsRecursive(original, accumulator, subsets):
    if len(original) > 0:
        currentChar = original[0]

        #go to the next char and add it to the accumulator
        strSubsetsRecursive(original[1:], accumulator + currentChar, subsets)
        
        #go to the next char and compute the subset without the accumulator
        strSubsetsRecursive(original[1:], accumulator, subsets)
        
        subsets.append(accumulator + currentChar)
    return subsets

subsets = strSubsets("ABC")
print(subsets)