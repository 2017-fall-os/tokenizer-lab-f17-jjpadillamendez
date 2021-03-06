

# Tokenizer - Project 1 - Jesus Padilla #
   
This directory contains:
* mytoc.c: implements an algorithm that splits a string into tokens, everytime it finds a specified
  delimiter.
    - tokenize(*char, char): which is the actual procedure which splits the input string into tokens, and returns 
      a freshly-allocated vector containing a single token in each entry.
* test.c: implements a user interface in which a user can type any string to use/test this tokenizer program.
* strlib2.c: provides our own string library. This library includes some procedures such as:
    - strlen2(*char): which counts the number of characthers in a given string
    - strcomp(*char, *char): which compares two strings and returns 1 if they are equal; otherwise returns 0

To compile:
~~~
$ make all
~~~

To run it, try:
~~~
$ ./test
~~~

To exit from the program:
~~~
$ exit
~~~

To delete generated files:
~~~
$ make clean
~~~

The following test cases were taken from the Operating System website to demonstrate the robustness of this tokenizer.

      Test Cases:
            "Hello my dog's name is Darwin."
            "     Hello   World!    "
            ""
            "          "
            " HelloWorld"
            
The following screenshot displays the output of the program after running these test cases.

![Alt text](https://github.com/2017-fall-os/tokenizer-lab-f17-jjpadillamendez/blob/master/tokenizer/testcases.jpg?raw=true)

HOW TO USE THIS PROGRAM:
   <br />1. First, the program asks for specifying a delimiter:
       <br />- Enter "y", to accept change the default delimiter, which is an space [' ']
       <br />- Enter "n", to avoid this and use the default delimiter
       <br />- Any other input is rejected
   <br />2. (Optional) after accepting to change the delimiter, the program asks for the new one
       <br />- Enter the new delimiter, which is a single characther. Any other input is rejected.
   <br />3. Second, this step is a loop in which the program prints a prompt "$"
       <br />- Enter any string, and the program will output the result as vector of string
   <br />Note: At any step, enter "exit" to quit the program
    
IMPORTANT NOTES: 
<br />-This program considers continuos delimiters as a single delimiter. Similarly, delimiters that are at the beginning or at the end of a given string are ignored. For example, the following two strings are considered as similar strings.
    
                    - "      Hello     World!      "
                    - "Hello World!"
                    
-The limit of characthers in each input string is 100. However, this length can be easily increased at the code level inside test.c, in which there is a constant variable named "BUFFERLIMIT".
<br />-Finally, the file assert2.c was borrowed from the demo of Dr. Freudenthal, this procedure adds the feature of adding an error message to the traditional assert method.
    
