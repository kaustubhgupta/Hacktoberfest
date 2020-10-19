def extended_euclidean(test_number, plane_number):
    '''
    (int, int) -> list

    Return the list : [greatest_common_divisor, multiplicative_inverse(1), multiplicative_inverse (if multiplicative_inverse(1) is negative)]

    >>> extended_euclidean(10, 23)
    [1, [7]]

    >>> extended_euclidean(11, 2)
    [1, [-5, -3]]
    '''
    table = {'quotent':0, 'remainder_temp1':max(test_number, plane_number), 'remainder_temp2':min(test_number, plane_number), 'remainder':0, 'multiplicative_inverse1':0, 'multiplicative_inverse2':1, 'multiplicative_inverse':0} #Initalizing table of Extended Euclidean algorithm

    while(True):
        try:                                                                                                #Break condition for loop
            table['remainder'] = table['remainder_temp1'] % table['remainder_temp2']
            if table['remainder'] < 0:
                break
        except ZeroDivisionError:
            break
        table['quotent'] = (table['remainder_temp1'] - table['remainder'])/table['remainder_temp2']         #From here we calculate value of plane_number
        table['multiplicative_inverse'] = table['multiplicative_inverse1'] - table['multiplicative_inverse2'] * table['quotent']

        table['remainder_temp1'] = table['remainder_temp2']                                                 #From here on we shift values about column to right
        table['remainder_temp2'] = table['remainder']
        table['multiplicative_inverse1'] = table['multiplicative_inverse2']
        table['multiplicative_inverse2'] = table['multiplicative_inverse']
    
    if table['multiplicative_inverse1'] > 0:                                                                #Returning [greatest_common_divisor, [multiplicative inverse(s)]]
        return [int(table['remainder_temp1']), [int(table['multiplicative_inverse1'])]]
    return [int(table['remainder_temp1']), [int(table['multiplicative_inverse1']), plane_number + int(table['multiplicative_inverse1'])]]

if __name__=='__main__':
    test_number  = int(input("Enter test_number  : "))                                                      #The number for which this algorithm will calculate multiplicative inverse
    plane_number = int(input("Enter plane_number : "))
    
    result = extended_euclidean(test_number, plane_number)

    print(result[1])
