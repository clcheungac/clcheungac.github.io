//: C01:MyError.cpp
class MyError {
	const char* const data;
public:
	MyError(const char* const msg = 0) : data (msg) {}
};

void f() {
   // Here we "throw" an exception object:
   throw MyError("something bad happened");
}

int main() {
   // As you'll see shortly, 
   // we'll want a "try block" here:
	f();
} ///:~
