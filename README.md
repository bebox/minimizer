# minimizer
Implementation of minimizer algorithm in Python, Ruby and C++
http://www.fer.unizg.hr/predmet/bio

Installation intructions and examples for:

--------Python---------
To run the program execute:
python minimizer.py [input_filename] [w] [k]

Test files:
Test files are located in the ./tests/ folder
Results:
The result is stored to ./output.txt in the current folder

---------Ruby----------
To run the program execute:
ruby minimizer.rb [input_filename] [w] [k]

Test files:
Test files are located in the ./tests/ folder
Results:
The result is stored to ./output.txt in the current folder

----------C++----------
Installation instructions:
Run "make all" to compile the program
Run "make clean" to clean the folder from .o and binary files

To run the program execute:
./minimizer [input_filename] [w] [k]

Test files:
Test files are located in the ./tests/ folder
Results:
The result is stored to ./output.txt in the current folder

To calculate the needed memory and execution time on Linux machines:

Clone the repository from github:
https://github.com/isovic/cgmemtime
Add the group with sudo:
$ sudo ./cgmemtime --setup -g myusergroup --perm 775
(for myusergroup add your username)
And you calculate with executing:
./cgmemtime -o measurements.txt ./testa x 10 20 30
In folder /sys/fs/memory add permissions to 777
