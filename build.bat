set CodeBlocks="C:\Program Files\CodeBlocks\codeblocks.exe"

start "" /D "." %CodeBlocks% --build --target="Debug" Console.cbp
start "" /D "." %CodeBlocks% --build --target="Release" Console.cbp
exit
