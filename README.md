# SysWOW64-Fs-Redirection
A tiny research and PoC of the usermode mechanism of SysWOW64 FS redirection.

Basicly, when the flag in 64bit TEB at offset 0x14c0 is 0 the wow64bit redirection is on
when its 1 then its off.
Tested on Windows 10 64 bit.
