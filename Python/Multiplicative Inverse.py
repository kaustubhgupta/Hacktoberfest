def extended_euclidean(p, q):
    """(int, int) -> list

    Return the list : [greatest_common_divisor, multiplicative_inverse(1), multiplicative_inverse (if multiplicative_inverse(1) is negative)]

    >>> extended_euclidean(10, 23)
    [1, [7]]

    >>> extended_euclidean(11, 2)
    [1, [-5, -3]]
    """
    #Initalizing table of Extended Euclidean algorithm
    table = {'quotent':0, 'remainder_temp1':max(p, q), 'remainder_temp2':min(p, q), 'remainder':0, 'multiplicative_inverse1':0, 'multiplicative_inverse2':1, 'multiplicative_inverse':0}

    while(True):
        try:                                                                      #Break condition for loop
            table['remainder'] = table['remainder_temp1'] % table['remainder_temp2']
            if table['remainder'] < 0:
                break
        except:
            break
        #From here we calculate value of q
        table['quotent'] = (table['remainder_temp1'] - table['remainder'])/table['remainder_temp2'] 

        table['multiplicative_inverse'] = table['multiplicative_inverse1'] - table['multiplicative_inverse2'] * table['quotent']

        #From here we shift values about column to right
        table['remainder_temp1'] = table['remainder_temp2']
        table['remainder_temp2'] = table['remainder']

        table['multiplicative_inverse1'] = table['multiplicative_inverse2']
        table['multiplicative_inverse2'] = table['multiplicative_inverse']
    
    if table['multiplicative_inverse1'] > 0:                                #Returning [greatest_common_divisor, [multiplicative inverse(s)]]
        return [int(table['remainder_temp1']), [int(table['multiplicative_inverse1'])]]
    return [int(table['remainder_temp1']), [int(table['multiplicative_inverse1']), q + int(table['multiplicative_inverse1'])]]

if __name__=='__main__':
    #Defining set of random values of p and q
    p = [10, 20, 30, 40]
    q = [23, 766, 2, 98]
    
    result = extended_euclidean(p, q)

    print(result[1])
