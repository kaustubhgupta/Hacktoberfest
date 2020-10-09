
'''
Author: Aditya Mangal 
Date:  15 september,2020
Purpose: python practise problem

'''

print('\t\t**Welcome to Ram verma kirana store**\t\t')
sum = 0
user_bill_list = []
while True:

    user_input = input('Enter your number or \'q\' to quit.\n')

    if user_input is not 'q':
        sum = sum + int(user_input)
        user_bill_list.append(user_input)

        print(f"Your current bill was {sum}.")

    else:
        break

print("Ram verma kirana store.")
print(f'Total things you bought are {len(user_bill_list)}.')
for i in range(len(user_bill_list)):
    print(f"{i+1}: {user_bill_list[i]}")


print(f"Your final billing amount was {sum}.")
print('Thank You!!.Come Soon again!.\n')
