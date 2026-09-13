# Lab1AlissaForde5458
Part B: build your own library
Option 1 - Calculator Library (libcalc)
Environment: macOS
--------------------------

### **Command 1: Compile calc.c**

$ gcc -c calc.c -o calc.o

Output File Generated: calc.o


### **Command 2: Archive object files in static library**

$ ar rc libcalc.a calc.o

Output File Generated: libcalc.a


### **Command 3: Index static library**

$ ranlib libcalc.a

Output File Generated: update symbol table in libcalc.a


### **Command 4: Compile calc.c**

$ gcc -fPIC -c calc.c -o calc_pic.o

Output File Generated: calc_pic.o


### **Command 5: Dynamic Library**

$ gcc -shared -o libcalc.so calc_pic.o

Output File Generated: libcalc.so


### **Command 6: Compiling main program**

$ gcc main.c -o main

Output File Generated: main


### **Command 7: Executable**

$ ./main

Expected Output:

calc_add(2.0, 2.0) = 4.00

calc_sub(2.0, 2.0) = 0.00

calc_mul(2.0, 2.0) = 4.00

calc_div(2.0, 2.0) = 1.00
