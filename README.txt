!!!Compilation structure!!!

gcc -c hello.c -o hello.o
gcc -c hellomain.c -o hellomain.o
gcc hello.o hellomain.o -o hello

gcc -c bin-tree-lib.c -o bin-tree-lib.o
gcc -c bin-tree-test.c -o bin-tree-test.o
gcc bin-tree-lib.o bin-tree-test.o -o bin-tree-test


-c
Компилировать или ассемблировать исходные файлы, но не линковать. Стадия ликовки просто не выполняется. Конечный вывод происходит в форме объектного файла для каждого исходного файла.

По умолчанию, имя объектного файла делается из имени исходного файла заменой суффикса '.c', '.i', '.s', и.т.д. на '.o'.

Нераспознанные входные файлы, не требующие компиляции или ассемблирования, игнорируются.