<Team>
Mengna Lin(mengnalin@email.wustl.edu), Christopher Ogle(cogle@wustl.edu), Seed Zeng(zengpeiyun@email.wustl.edu) 

<File Submitted>
	scanner.h
	token.h
	cse425_lab0.cpp
	scanner.cpp
	token.cpp
#Extra Credit Done


<DESIGN>

	For this lab we divided it up into two parts the first part was to tackle the designing and implementation
	of the scanner. 
	
	Scanner.h: This file contains the method decelerations of our Scanner class. Our Scanner is created in the 
	OpenIO method in cse425_lab0.cpp file. 
	Scanner.cpp: This file contains all the definitions of the method decelerations from Scanner.h file.

	Token.h: This file contains our TOKENS enumeration, an enumeration of all tokens, and our Token struct.
	Token.cpp: This file contains the definition of the methods from Token.h

	cse425_lab0.cpp: This file contains our recursive decent methods and our main.
	
	
	The way our lab works is like so, our program begins on line number 363 by first checking if the 
	incoming number of arguments is valid if they are not then we return a useful help message. If the 
	user has entered a valid number of arguments we proceed to the next part of the program which is trying
	to open the files that the user has provided us.
	This takes place in the method OpenIO. In this method we first check if the user has input valid files, can
	we open both of the files if not then we alert the user that the provided files are not read, writeable or
	both. If the user has provided us two valid files we create a scanner object by passing in the input file.
	While the scanner can read the input file we extract a string from the input file in the Scanner's extraction 
	operator and try and match this extracted string up with a token.
		Our LABEL token takes [A-Za-z]+
		Our NUMBER token takes [0-9]+
		Our AND token takes "^"
		Our SEPERATOR token takes ":-"
		Our LEFTPAREN token takes  "("
		Our RIGHTPAREN token takes  ")"
		Our COMMA token takes ","
		Our UNKNOWN token takes anything else
	
	After successfully reading through the entire file our token vector will be adopted by the scanner.

	Next our program will begin the Top Down Recursive Descent Parsing. We use a while loop in order to 
	drive the parsing. We must have this while loop because after our program has found a valid hornclause
	or just caught an exception we must be able to catch the error and then restart the Top Down Recursive 
	Descent if we are not at the end of the vector. It's important to note that after we catch a throw
	we will Printout what we have if our valid_index is less than or equal to start_index we don't print
	out a valid token instead that corresponds to an error being thrown. In our program you will notice an 
	if case where we only advance the stream if it is not a Label token this is because say we had the following
	construct:
		test ( t ) dog ( cat )
	Our program will throw an error at dog, but WE DO NOT want to advance rather our program realizes that 
	dog could be the start of a valid hornclause and we should explore this possibility.
	When our token_vector is exhausted the funciton will return and we will close our files.

	#Extra Credit
	We did the extra credit and we simply implemented this by modifying the grammar and inserting an extra production called x_6.

<IMPLEMENTATION>
	
	In this lab there wasn't anything tricky that we had to deal with. So our lab uses straight forward Object Oriented Design. 
	One thing that we took advantage of was Throw and how it pops off values on the stack. Thus in our error function we
	can throw our error and have our "Parsing Driver" catch is and then rsume parsing. This is really neat as it greatly minimizes the
	amount of work book keeping that we needed to do. In addition it allowed us to use a single Throw value and single error
	output function. 

	Our Scanner Class draws heavily from the Object Oriented Design pattern. With all variables being encapsulated and hidden from the user they
	must use the getter and setter methods to access them. Also, it gives us a chance to expand on it for future labs.


<Compile and Excution>

	When building we ran into very minor bugs such as forgetting to end the line with a semi-colon, curse you python, to other minor mistakes in the code
	such as incrementing incorrectly that cost us maybe 3 minutes to fix per bug. Overall we finished the lab rather fast and error free. 

<TESTING>

//////////////////////////////////////////////////////////////////////////////
Testing Error message using command line
//////////////////////////////////////////////////////////////////////////////

******************************Test 1*************************************
********************Test wrong number of arguments************** 


<1> Command /output
(a)
X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>cse425_lab0.
exe test5_extraCredit.txt
usage: cse425_lab0.exe <input_file_name> <output_file_name>
(b)
X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>cse425_lab0.
exe test5_extraCredit.txt haha haha
usage: cse425_lab0.exe <input_file_name> <output_file_name>

X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>


<2> Analysis
So we can see, we wrong number of arguments are fed in through command line ( not = 3). The prgoram prints out a useful error msg




******************************Test 2*************************************
******************Cannot open input/output files or both************** 


<1> command/output

(a)
X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>chmod 000 te
st.txt
X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>cse425_lab0.
exe test.txt cannotopen.txt
Could not open the provided input file

(b)

X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>chmod 400 ca
nnotopen.txt

X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>cse425_lab0.
exe test.txt cannotopen.txt
Could not open the provided output file or do not have write permission

(c)

X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>chmod 400 ca
nnotopen.txt

X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>chmod 000 te
st.txt

X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>cse425_lab0.
exe test.txt cannotopen.txt
There was an error opening both the input and output files.

<2> Analysis

As you can see
for each case the program performs correctly
(a)
when input file is not rwx, the program erros out and tells user the file cannot be opened
(b) 
we then set output file to be read-only
Then the program tells us we cannot write to the output file
(c)
if both we have a different error msgs


 
//////////////////////////////////////////////////////////////////////////////
Testing of the parsing
//////////////////////////////////////////////////////////////////////////////

******************************Test 1*************************************
********************Test with purely non-hornlcauses************** 

<0> command
X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>cse425_lab0.
exe test1.txt testing1.txt

<1>. Input File


Chris()
seed (
Mengna (1 , 2 , ^ )
Seed ( 1 , 2 , :- )

<2>.Output File
<Empty>

<3>. Error Message

<-----Error Message----->
From: hornclause Unknown is coming in. Delinquent token is: Chris()
We expected LABEL
Production up until error: Chris()
<-----End Error Message----->


<-----Error Message----->
From: x_5 Unknown is coming in. Delinquent token is: (1
We expected COMMA or RIGHTPAREN
Production up until error: seed ( Mengna (1
<-----End Error Message----->


<-----Error Message----->
From: hornclause Comma is coming in. Delinquent token is: ,
We expected LABEL
Production up until error: ,
<-----End Error Message----->


<-----Error Message----->
From: hornclause Digit is coming in. Delinquent token is: 2
We expected LABEL
Production up until error: 2
<-----End Error Message----->


<-----Error Message----->
From: hornclause Comma is coming in. Delinquent token is: ,
We expected LABEL
Production up until error: ,
<-----End Error Message----->


<-----Error Message----->
From: hornclause And is coming in. Delinquent token is: ^
We expected LABEL
Production up until error: ^
<-----End Error Message----->


<-----Error Message----->
From: hornclause RightParen is coming in. Delinquent token is: )
We expected LABEL
Production up until error: )
<-----End Error Message----->


<-----Error Message----->
From: args Separator is coming in. Delinquent token is: :-
We expected LABEL or NUMBER
Production up until error: Seed ( 1 , 2 , :-
<-----End Error Message----->


<-----Error Message----->
From: hornclause RightParen is coming in. Delinquent token is: )
We expected LABEL
Production up until error: )
<-----End Error Message----->

<4>Analysis
Since everything is wrong, the program outputs nothing as we expected. More importantly, we can see error message give us 
useful message about
(0)which recursive function it is at when errros out, What production it was in the midst of parsing
(1) What terminal token it had expcted  
(2) what's the incoming token 
(3) what tokens it had seen so far for the horn clause it is attempting to parse

Therefore the program pass test 1




******************************Test 2*************************************
******************Test with purely correct horn clauses************** 

<0> command
X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>cse425_lab0.
exe test2.txt testing2.txt

<1>. Input File


Chris ( ) Seed ( mengna , chris , JJ ) :- gill ( 1 , 2 , 3 )

<2>.Output File

Chris ( )
Seed ( mengna , chris , JJ ) :- gill ( 1 , 2 , 3 )

<3>. Error Message


<-----Error Message----->
From: x_6 Label is coming in. Delinquent token is: Seed
We expected AND or SEPARATOR
Production up until error: Chris ( ) Seed
<-----End Error Message----->

<*****Valid Token*****>
Chris ( )
<*****End Valid Token*****>
<*****Valid Token*****>
Seed ( mengna , chris , JJ ) :- gill ( 1 , 2 , 3 )
<*****End Valid Token*****>


<4>Analysis
The input file contains two purely valid horn clauses. Thus the program recognized them and put them 
into two seperate lines (even though in the input file they are all in one line)

Besides the error msg prints out useful info about
(0)which recursive function it is at when errros out, What production it was in the midst of parsing
(1) What terminal token it had expcted  
(2) what's the incoming token 
(3) what tokens it had seen so far for the horn clause it is attempting to parse

Interestingly, altough both horn clauses are valid, we still got an error msg 

<-----Error Message----->
From: x_6 Label is coming in. Delinquent token is: Seed
We expected AND or SEPARATOR
Production up until error: Chris ( ) Seed
<-----End Error Message----->

it is because the grammar allows a seperator comes after the rightparen starting the <body> section of the horn clause.
Thus we have to expect the seperator (we also expect and for the extra credit) after we have seen a rightparen.
In this case we see a label (start of a new horn clause), we error out, but we resume the flow and keep looking for the next valid horn clauses and the program 
did find it. 

To conclude, the program pass test 2


******************************Test 3*************************************
******************Test with mixture of corret and wrong horn clauses************** 

<0> command
X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>cse425_lab0.
exe test3.txt testing3.txt

<1>. Input File


Chris ( ) Seed ( mengna , chris , JJ ) :- gill ( 1 , 2 , 3 )

<2>.Output File

Chris ( )
Seed ( mengna , chris , JJ ) :- gill ( 1 , 2 , 3 )

<3>. Error Message


<-----Error Message----->
From: x_6 Label is coming in. Delinquent token is: Seed
We expected AND or SEPARATOR
Production up until error: Chris ( ) Seed
<-----End Error Message----->

<*****Valid Token*****>
Chris ( )
<*****End Valid Token*****>
<*****Valid Token*****>
Seed ( mengna , chris , JJ ) :- gill ( 1 , 2 , 3 )
<*****End Valid Token*****>


<4>Analysis
The input file contains two purely valid horn clauses. Thus the program recognized them and put them 
into two seperate lines (even though in the input file they are all in one line)

Besides the error msg prints out useful info about
(0)which recursive function it is at when errros out, What production it was in the midst of parsing
(1) What terminal token it had expcted  
(2) what's the incoming token 
(3) what tokens it had seen so far for the horn clause it is attempting to parse

Interestingly, altough both horn clauses are valid, we still got an error msg 

<-----Error Message----->
From: x_6 Label is coming in. Delinquent token is: Seed
We expected AND or SEPARATOR
Production up until error: Chris ( ) Seed
<-----End Error Message----->

it is because the grammar allows a seperator comes after the rightparen starting the <body> section of the horn clause.
Thus we have to expect the seperator (we also expect and for the extra credit) after we have seen a rightparen.
In this case we see a label (start of a new horn clause), we error out, but we resume the flow and keep looking for the next valid horn clauses and the program 
did find it. 

To conclude, the program pass test 2



******************************Test 4********************************
*****************Test with tricky cases ************** 

<0> command
X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>cse425_lab0.
exe test4_tricky.txt testing4.txt

<1>. Input File

this is a test ( )
1234
chris ( ) :-
88
seed ( ) :- chris ( )
h1
DOG ( ) :- test ( ^ )
test ( 1 , 2 , 3 ) :- partners ( chris , seed ) ^ hello ( world ) :- dog ( 2 )


<2>.Output File
test ( ) 
chris ( ) 
seed ( ) :- chris ( ) 
DOG ( ) 
test ( 1 , 2 , 3 ) :- partners ( chris , seed ) ^ hello ( world ) 
dog ( 2 ) 


<3>. Error Message
exe test4_tricky.txt testing4.txt

<-----Error Message----->
From: x_3 Label is coming in. Delinquent token is: is
We expected LEFTPAREN
Production up until error: this is
<-----End Error Message----->


<-----Error Message----->
From: x_3 Label is coming in. Delinquent token is: a
We expected LEFTPAREN
Production up until error: is a
<-----End Error Message----->


<-----Error Message----->
From: x_3 Label is coming in. Delinquent token is: test
We expected LEFTPAREN
Production up until error: a test
<-----End Error Message----->


<-----Error Message----->
From: x_6 Digit is coming in. Delinquent token is: 1234
We expected AND or SEPARATOR
Production up until error: test ( ) 1234
<-----End Error Message----->

<*****Valid Token*****>
test ( )
<*****End Valid Token*****>

<-----Error Message----->
From: body Digit is coming in. Delinquent token is: 88
We expected LABEL
Production up until error: chris ( ) :- 88
<-----End Error Message----->

<*****Valid Token*****>
chris ( )
<*****End Valid Token*****>

<-----Error Message----->
From: x_2 Unknown is coming in. Delinquent token is: h1
We expected AND
Production up until error: seed ( ) :- chris ( ) h1
<-----End Error Message----->

<*****Valid Token*****>
seed ( ) :- chris ( )
<*****End Valid Token*****>

<-----Error Message----->
From: x_4 And is coming in. Delinquent token is: ^
We expected RIGHTPAREN, LABEL, or NUMBER
Production up until error: DOG ( ) :- test ( ^
<-----End Error Message----->

<*****Valid Token*****>
DOG ( )
<*****End Valid Token*****>

<-----Error Message----->
From: hornclause RightParen is coming in. Delinquent token is: )
We expected LABEL
Production up until error: )
<-----End Error Message----->


<-----Error Message----->
From: x_2 Separator is coming in. Delinquent token is: :-
We expected AND
Production up until error: test ( 1 , 2 , 3 ) :- partners ( chris , seed ) ^ hel
lo ( world ) :-
<-----End Error Message----->

<*****Valid Token*****>
test ( 1 , 2 , 3 ) :- partners ( chris , seed ) ^ hello ( world )
<*****End Valid Token*****>
<*****Valid Token*****>
dog ( 2 )
<*****End Valid Token*****>





<4>Analysis
This file contains a few interesting tricky cases and the program did the correct things. Let's go through them
(a)
this is a test ( )

the program should only pick out test ( ) and it did
The program performed expectedly 
(b)
1234
chris ( ) :-

The program should overlook 1234 and more importantly
it will parse chris ( ) and filtering out :-
This is actaully not natrually in the grammar and we have to implement it manually ( more in design section)

The program performed expectedly  
(c)
88
seed ( ) :- chris ( )

The program should overlook 88 and parse seed ( ) :- chris ( )


The program performed expectedly 
(d)
DOG ( ) :- test ( ^ )
Another interesting case, The program should pick out only DOG ( ) since the <body> after seperator is invalid
The program performed expectedly 
(e)
test ( 1 , 2 , 3 ) :- partners ( chris , seed ) ^ hello ( world ) :- dog ( 2 )

This is a tricky case. The program should first recognize a long horn clause that is test ( 1 , 2 , 3 ) :- partners ( chris , seed ) ^ hello ( world )
Then since the grammar does not allow two seperators. It erros out at second seperator. Then the program RESUMES and parse out dog ( 2 )

The program performed expectedly 



Besides the error msg prints out useful info about
(0)which recursive function it is at when errros out, What production it was in the midst of parsing
(1) What terminal token it had expcted  
(2) what's the incoming token 
(3) what tokens it had seen so far for the horn clause it is attempting to parse

To conclude, the program pass test 4 (tricky tests)




#@ Testing Extra Credit

******************************Test 5*************************************
******************Test extra credits************** 
In extra credit.
We allow head be comprised of several predicates with (And- ^) in between

<0> command
X:\zengpeiyun\winprofile\desktop\lab0_FInal\kiss_my_jj_folder\Debug>cse425_lab0.
exe test5_extraCredit.txt testing5.txt

<1>. Input File


test ( 1 , 2 , 3 ) ^ seed ( is , awesome ) 
test ( 1 , 2 , 3 ) ^ seed ( is , awesome ) :- partners ( chris , seed ) 
test ( 1 , 2 , 3 ) ^ seed ( is , awesome ) :- partners ( chris , seed ) ^ hello ( world ) 


<2>.Output File

test ( 1 , 2 , 3 ) ^ seed ( is , awesome ) 
test ( 1 , 2 , 3 ) ^ seed ( is , awesome ) :- partners ( chris , seed ) 
test ( 1 , 2 , 3 ) ^ seed ( is , awesome ) :- partners ( chris , seed ) ^ hello ( world ) 


<3>. Error Message


<-----Error Message----->
From: body Unknown is coming in. Delinquent token is: chris()
We expected LABEL
Production up until error: test ( 1 , 2 , 3 ) ^ seed ( is , awesome ) :- chris()

<-----End Error Message----->

<*****Valid Token*****>
test ( 1 , 2 , 3 ) ^ seed ( is , awesome )
<*****End Valid Token*****>

<-----Error Message----->
From: x_2 Label is coming in. Delinquent token is: test
We expected AND
Production up until error: test ( 1 , 2 , 3 ) ^ seed ( is , awesome ) :- partner
s ( chris , seed ) test
<-----End Error Message----->

<*****Valid Token*****>
test ( 1 , 2 , 3 ) ^ seed ( is , awesome ) :- partners ( chris , seed )
<*****End Valid Token*****>
<*****Valid Token*****>
test ( 1 , 2 , 3 ) ^ seed ( is , awesome ) :- partners ( chris , seed ) ^ hello
( world )
<*****End Valid Token*****>



<4>Analysis
Now we have enabled head containing several predicates, all the sentences in the input should be valid horn clauses. The program parse all of them expectedly.
The error messages are due to that  the grammar is expecting an unfinished hornclause to be complete. So it erroed out at the unmatched characters. Then it resumes at the correct index and parsing the rest file


Besides the error msg prints out useful info about
(0)which recursive function it is at when errros out, What production it was in the midst of parsing
(1) What terminal token it had expcted  
(2) what's the incoming token 
(3) what tokens it had seen so far for the horn clause it is attempting to parse

Interestingly, altough both horn clauses are valid, we still got an error msg 

<-----Error Message----->
From: x_6 Label is coming in. Delinquent token is: Seed
We expected AND or SEPARATOR
Production up until error: Chris ( ) Seed
<-----End Error Message----->

it is because the grammar allows a seperator comes after the rightparen starting the <body> section of the horn clause.
Thus we have to expect the seperator (we also expect and for the extra credit) after we have seen a rightparen.
In this case we see a label (start of a new horn clause), we error out, but we resume the flow and keep looking for the next valid horn clauses and the program 
did find it. 

To conclude, the program pass test5_extraCredit


