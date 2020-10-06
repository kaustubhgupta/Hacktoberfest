# -*- coding: utf-8 -*-

"""
RSA (Rivest–Shamir–Adleman) is an algorithm used by modern computers to encrypt and decrypt messages. 
It is an asymmetric cryptographic algorithm. Asymmetric means that there are two different keys. 
This is also called public key cryptography, because one of the keys can be given to anyone. 
The other key must be kept private. 
The algorithm is based on the fact that finding the factors of a large composite number is difficult: 
when the factors are prime numbers, the problem is called prime factorization. 
It is also a key pair (public and private key) generator.
"""

"""
Flow of the code:
    
    input_numbers()
    prime_number()
    e_value()
    gcd()
    d_value()
    keys()
    encrypt()
    decrypt()    
    
"""

def gcd(x, y):                                    # Code to find GCD of 2 numbers
    
    a = int(0)
                                                  # choose the smaller number
    if x > y:
        a = y                                     # a = smaller number
    else:
        a = x                                     # a = smaller number
    for i in range(1, a+1):
        if((x % i == 0) and (y % i == 0)):        # checking divisibility by the smaller number
            gcd = i 
    return gcd

       
def e_value(p,q):
    n = p*q                                       # n is the modulus for the public key and the private keys
    phi = (p-1)*(q-1)                             # phi, also known as Totient Function
    e = int(2)                                    # 1  < e < phi(n) and also, e is coprime to phi i.e. gcd(e,phi) = 1
                                                  # therefore, our next step involves finding the right value of e, such that gcd(e,phi) = 1
    print("PHI: {}".format(phi))
    
    while (True):
        a = gcd(e,phi)
        if a==1:
            d_value(n,phi,e)                      # moving to next function to calculate the value of 'd', iff gcd(e,phi)=1
            print("e: {}".format(e))
            break
        else:
            e+=1                                  # incrementing the value of 'e' if gcd(e,phi)!=1

                                                                                
def prime_number(n):                              # a prime number function to check whether our input numbers are prime or not
    flag = 0
    if n==2 or n==1:
        flag = 1
    for i in range(2,(n//2)):
        if n%i == 0:
            flag = 1
    if flag==0:
        return True
    else:
        return False

def input_numbers():
    try:
        p = int(input("Enter a prime number: "))
        q = int(input("Enter a prime number: "))
       
        if (prime_number(p) and prime_number(q)):     # if both entered numbers are prime, then we move on to the calculation of value of 'e'
            e_value(p,q)
        
        else:
            print("Please enter prime numbers.")
            input_numbers()
    except ValueError:
        print("Please enter valid integer prime numbers.")
    except:
        print("Please follow the instructions.")
       
# Messages encrypted using the public key can only be decrypted with the private key        

def decrypt(c,private_key):
    v = pow(c,private_key[1])%private_key[0]      # v = decrypted text      
    print("Decrypted Text: {}".format(v))
        
       
def encrypt(public_key,private_key):
    try:
        m = int(input("Enter message to be encrypted: ")) # m = message
        c = pow(m,public_key[1])%public_key[0]
        print("Cipher Text: {}".format(c))
        decrypt(c,private_key)
    except ValueError:
        print("Please enter message in integer format")
    except:
        print("Please follow the instructions.")
        
def keys(n,e,d):
    public_key = (n,e)
    private_key = (n,d)
    encrypt(public_key,private_key)
                
def d_value(n,phi,e):
    if (phi+1)%e == 0:
        d = int((phi+1)/e)                       
        print("d: {}".format(d))
    keys(n,e,d)
    

print("Welcome to RSA Algorithm:\n")   
input_numbers()
      