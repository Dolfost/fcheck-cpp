# fcheck
This C++ library simplifies monitoring of fstream objects.
## Usage

### Functions  
```C++
bool is_open(ifstream& inFile, char *filenmae, bool exit_if_closed);
bool is_open(ofstream& inFile, char *filename, bool exit_if_closed);
```
>`inFile`: main object,  
`filename`: filename of file,  
`exit if closed`: exit if file is closed,  
`<return>bool`: `true` - opened, `false` - closed;  


```C++
bool is_open(void (*funpt)(const char*), ifstream& inFile, char *filenmae, bool exit_if_closed);
bool is_open(void (*funpt)(const char*), ofstream& inFile, char *filename, bool exit_if_closed);
```  
>`funpt`:				  function pointer. must describe the error.  
see [readme/run/is_open_ifstream_example.cpp](https://github.com/Dolfost/fcheck-cpp/blob/update/readme/run/is_open_ifstream_example.cpp) for details,   
`inFile`: main object,  
`filename`: filename of file,  
`exit if closed`: exit if file is closed,  
`<return>bool`: `true` - opened, `false` - closed;  



```C++
short ifstrm_status(ifstream& inFile, const char *filename, bool exit_if_fail, bool eof_react, bool slient);
```
>`inFile`: main object,   
`filename`: file name,   
`exit_if_fail`: exit if something bad,  
`eof_react`: react to eof (if true, function returns true on eof),   
`slient`: `true` - print messages (call funclions), `false` - dont print messages (call functions),   
`<return>short`: 0 - all ok, 1 - eof (if eof_react is true), 2 - data missmatch, 3 - unknown reason;   

```C++
short ifstrm_status(void (*funpt[3])(const char*), ifstream& inFile, const char *filename, bool exit_if_fail, bool eof_react, bool slient);
```
>`funpt`: pointer to array of 3 functions, [0] - eof, [1] - data missmatch, [2] - unknown reason. see [readme/run/ifstream_status_example.cpp](https://github.com/Dolfost/fcheck-cpp/blob/update/readme/run/ifstream_status_example.cpp) for details,   
`inFile`: main object,  
`filename`: file name,  
`exit_if_fail`: exit if something bad,  
`eof_react`: react to eof (if true, function returns true on eof),  
`slient`: 1 - print messages (call funclions by passed pointers), 2 - dont print messages (call funclions by passed pointers),  
`<return>short`: 0 - all ok, 1 - eof (if eof_react is true, else 0), 2 - data missmatch, 3 - unknown reason;  

### Examples
[ifstream_status_example.cpp](https://github.com/Dolfost/fcheck-cpp/blob/update/readme/run/ifstream_status_example.cpp),  
[is_open_ifstream_example.cpp](https://github.com/Dolfost/fcheck-cpp/blob/update/readme/run/is_open_ifstream_example.cpp).  


### libinfo: [libinfo.txt](https://github.com/Dolfost/fcheck-cpp/blob/main/readme/libinfo.txt). 
-------------------------------------------
‎  
## License: LGPL-3.0
[GNU General Public License v3.0](https://github.com/Dolfost/fcheck-cpp/blob/main/COPYING)  




##### *Coffe...?* [PayPal](https://www.paypal.com/donate?hosted_button_id=BZ6DNYKFPBWNA)
