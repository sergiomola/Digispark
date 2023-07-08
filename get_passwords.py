import json
import base64
from Crypto.Cipher import AES
import sqlite3


#This file takes as input a file named key and the file Login Data
#It outputs a file results.csv with all the passwords

results = open("results.csv", mode="w")


keyfile = open("key", mode="rb")
key = keyfile.read()
keyfile.close()

con = sqlite3.connect("Login Data")
cur = con.cursor()
res = cur.execute('SELECT "origin_url","username_value", "password_value" FROM "logins"')
data = cur.fetchall()

for row in data:

    encrypted = row[2]


    iv  = encrypted[3:15]
    ciphertext = encrypted[15:-16]
    tag = encrypted[-16:]


    cipher = AES.new(key, AES.MODE_GCM, iv)
    try:
        dec = cipher.decrypt_and_verify(ciphertext, tag)
        results.write(row[1] + "," + dec.decode() + "," + row[0] + "\n")
    except ValueError:
        print("Decryption failed")


results.close()
