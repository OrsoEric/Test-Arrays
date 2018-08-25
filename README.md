# Test-Arrays
Ways to make and pass array in C++  
This is to improve my base knowledge of C++  
  
There are many ways to build arrays  
First difference is between stack and heap arrays  
All C constructs are still supported in C++. They are viable but might not make full use of the power of the language  
C++ introduces new/delete on top of malloc/free.  
The proper way to do things in C++ is to use standard classes like std::array, std:: vector and std::string  

std::array uses the stack. array size must be known at compile time. It's the fastest method.  
std::vector uses the heap and should be used for dynamic/unknown at compile time array size.  
new/delete works, but developers should strive to use them only when needed, giving priority to standard classes.  
malloc/free works, but developers should use new/delete instead as they are C++ constructs.  

Passing arrays to functions is not trivial with stack based array. Function must have an argument type that embed inside itself the array size. The usual alternative of passing explicit pointers and explicit dimensions works always.    
