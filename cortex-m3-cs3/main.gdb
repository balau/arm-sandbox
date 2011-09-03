file main
target remote localhost:1234
break main
break _open
break _close
break _read
break _write
break _fstat
break _isatty
break _sbrk
break _lseek

