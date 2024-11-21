# testing.cpp
## Description of parameters
tl_\<something\> - Time Limit for \<something\>

type_checker - if type checker is '0', then checker.cpp is launched with bitwise file comparison, otherwise checker.\<something\> is launched with the CustomComparison function

is_py_\<something\> - flag python/cpp

path - project root, if the root is diffirent, replace path in file_\<something\> with the user's one

file_\<someething\> - value of path to you file (It is not advisable to manually specify the file extension)

path_to_\<something\> - default is path (looks path)

run_file_\<something\> - value of path to exe files

\<something\>_out - value of path to read/write files

compile - path to cpp compiler

python_interpreter - path to python interpreter
## Description
CE \<something\> - Complation error \<something\>

RE \<something\>  - Runtime error \<something\> (file didn't return 0)

TL \<something\>  - Time limit \<something\>

WA \<test\> - Wrong answer in \<test\> test

CHECKER ERROR - testing.cpp break

OK - you passed the test

\<test\> - number of test (seed random)

The program has been tested on C++ version 20
# generator.\<something\>
You should have updated the CustomGenerator function
You should output to stdin

    Paramerets of comand line {_, seed}
# checker.\<something\>
You should have updated the CustomComparison function (if you don't want bitwise comparison)
You should output to stdin

Paramerets of comand line {_, type comparison ('0' or not '0'), stress out, main out}
# (main/stress).\<something\>
    You should output to stdin
