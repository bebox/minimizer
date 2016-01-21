# minimizer
Implementation of minimizer algorithm in Python, Ruby and C++ <br/>
Link to Univeristy class webpage: http://www.fer.unizg.hr/predmet/bio

Installation intructions and examples for:

#####--------Python---------<br/>
To run the program execute:<br/>
python minimizer.py [input_filename] [w] [k]<br/>

Test files:<br/>
Test files are located in the ./tests/ folder<br/>
Results:<br/>
The result is stored to ./output.txt in the current folder

#####---------Ruby----------<br/>
To run the program execute:<br/>
ruby minimizer.rb [input_filename] [w] [k]<br/>

Test files:<br/>
Test files are located in the ./tests/ folder<br/>
Results:<br/>
The result is stored to ./output.txt in the current folder<br/>

#####----------C++----------<br/>
Installation instructions:<br/>
Run "make all" to compile the program<br/>
Run "make clean" to clean the folder from .o and binary files<br/>

To run the program execute:<br/>
./minimizer [input_filename] [w] [k]<br/>

Test files:<br/>
Test files are located in the ./tests/ folder<br/>
Results:<br/>
The result is stored to ./output.txt in the current folder<br/>

To calculate the needed memory and execution time on Linux machines:<br/>

Clone the repository from github:<br/>
https://github.com/isovic/cgmemtime<br/>
Add the group with sudo:<br/>
$ sudo ./cgmemtime --setup -g myusergroup --perm 775<br/>
(for myusergroup add your username)<br/>
And you calculate with executing:<br/>
./cgmemtime -o measurements.txt ./testa x 10 20 30<br/>
In folder /sys/fs/memory add permissions to 777
