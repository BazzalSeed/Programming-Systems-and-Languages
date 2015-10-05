<Team>

 [Awesome] Peiyun(Seed) Zeng(zengpeiyun@email.wustl.edu) [Amazing]Christopher Ogle(cogle@wustl.edu), [unstoppable]Mengna Lin(mengnalin@email.wustl.edu)


<File Submitted>  <--- check this before submit chris

#header files
ASTnode.h
BodyAST.h
HeadAST.h
HornClauseAST.h
LABEL.h
NUMBER.h
PredicateAST.h
sanner.h
----------------
TerminalAST.h
#source files
ASTNode.cpp
BodyAST.cpp
HeadAST.cpp
HornClauseAST.cpp
lab1_00.cpp
LABEL.cpp
NUMBER.cpp
PredicateAST.cpp
scanner.cpp
Terminals.cpp
token.cpp

#Extra Credit Done

<Design/Implementation>
After changing places we hold copy of tokens directly to only holding a shared_pointer for our first lab, we rerun the test cases for lab1.
All test cases pass, we then confidently tank for granted that we correctly parse all horn cluases according to grammar.

Now for this lab, we are left with two major tasks: (1) reformat the horncluase to follow the output grammar (2) print NUMBER and LABEL in numerical and lexical order

To achive (1), we choose to build an AST. Different parts of the horn clause will be abstracted to one type of nodes in AST, through which we can easily parentisize different parts of the hornclauses.
This is a better way to achive (1) compared to suggested method buidling a list of lists beacause it is more Object-oreitned and much more expandable for different grammars. Morover, it is how compiler will do the job anyway.

The implmentation consists of two major components. 
a. 
Construct a base class called ASTNode that contains basic methods for tracing/constructing AST
(1) children vector
(2) parent node (pointer to another Node)
(2) adopt children method
Then Inherting from the base classes are HornclauseNode, HeadNode, BodyNode,PredicateNode, TerminalNode
**Now, each subtype will define its own visit method where we have to use self-reflection by checking the tag to achvie the correct visiting pattern.
essentially, in visit method for each subtype, we check the tag on the node and decide what type its children should be. Then we dynamic cast the pointer to proper type and invoke the correct visit method.
The recursive visit will terminate the the terminal nodes where they contain pointers to LABEL and NUMBER objects (subtypes of token class)


b.
To drive the construction, we have a collection of recursive funcions (line 295 - 596) where we reparse the already-valid horn clauses and create AST.

(1) we create everything on the heap
(2) we parse the previously created node down the recursive function
(3) adopt the newly created node to the parent node that is properly passed in
*(4) Two special cases need taking care of for recursion on (body) and (head) nodes
so in the adpotion for those two nodetypes we have to check where it visit from, if it visit from itsefl, we adopt the created node the its parent.
(5) we also have to create an ASTNode called hornhaed as the parent of the initial hornclause node

Now AST is properly constructed, invoke visit method on hornclause node (should only be one) to correcty print out the output-formated hornclause


To achive (2), since all terminals contain on the leaf nodes, when we visit the terminal nodes, we differentiate NUMBER and LABEL type and push them to two sets.

Then printout the two sets to obtain the result.


Our implementation is highly oop and expandable :) ~~~~!



