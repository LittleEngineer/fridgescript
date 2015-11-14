# Introduction #
This should provide a list of all features found in the 0.1.0b version of FridgeScript, corresponding to [revision 37](https://code.google.com/p/fridgescript/source/detail?r=37) of the source in the repository.

# API #

v0.1.0b provides API calls for working with scripts, using the following (MS) C++ prototypes:
```
extern "C" unsigned int __declspec(dllimport) __stdcall FSCreateContext();
extern "C" unsigned int __declspec(dllimport) __stdcall FSDestroyContext(unsigned int context);

extern "C" unsigned int __declspec(dllimport) __stdcall FSGetVariableHandle(unsigned int context, unsigned int codeHandle, char* name);
extern "C" double __declspec(dllimport) __stdcall FSGetVariableValue(unsigned int varHandle);
extern "C" double __declspec(dllimport) __stdcall FSSetVariableValue(unsigned int varHandle, double value);

extern "C" unsigned int __declspec(dllimport) __stdcall FSCompile(unsigned int context, char* code);
extern "C" unsigned int __declspec(dllimport) __stdcall FSExecute(unsigned int context, unsigned int codeHandle);
```

# Language Features #

v0.1.0b supports:
  * all of the [mathematical operators](MathOperators.md)
  * all of the [logical operators](LogicalOperators.md) except xor
  * all [branches](if.md) and [loops](Loops.md)
  * all of the [assignment operators](AssignmentOperators.md) except the bitwise ones and the binary shifts