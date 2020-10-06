import glob
from Crypto import Random 
from Crypto.Cipher import AES

BLOCK_SIZE = 16
iv = "\x13\x33\xf7\x11\x33\x33\x77\xff\x13\x33\x07\x11\x33\x33\x77\x41"
key = "hacktober2020!!!"
def pad(s):
    return s + (BLOCK_SIZE - len(s) % BLOCK_SIZE) * chr(BLOCK_SIZE - len(s) % BLOCK_SIZE)

def encrypt_msg(data):
    dat = pad(data)
    c = AES.new(key, AES.MODE_CBC, iv)
    msg = c.encrypt(dat)
    return msg
    # return 0

def main():
    msg = raw_input("enter your secret msg: ")
    print("IV: "+ iv.encode("hex"))
    print("Key: " + key)
    print("encrypted msg: " + encrypt_msg(msg).encode('hex'))

if __name__ == "__main__":
    main()