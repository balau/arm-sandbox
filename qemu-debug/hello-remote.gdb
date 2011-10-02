set solib-absolute-prefix nonexistantpath
set solib-search-path ~/CodeSourcery/Sourcery_G++_Lite/arm-none-linux-gnueabi/libc/lib/
file ./hello-2.6/src/hello
target extended-remote localhost:1234
set remote exec-file /usr/bin/hello
break main
run
