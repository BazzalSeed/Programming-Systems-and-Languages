# What's interesting 
#### Highly object-oriented design


- Use scanner classes to achieve the scanning (utilize regex) and parsing (LL[1] Parsing) of the grammar
- Base class ASTNode and derive other node types from it
- Reflectively check the type of the node dynamically and utilize the class hierarchy to invoke the correct subclass method
- Put every Node and token on the heap and only need to copy pointer to save space

#### Good design pattern 
 

-	Use enums to denote all hard-coded constants
-	Use use try catch at appropriate places to halt the parsing at appropriate situation

#### Looking forward


-	Make it more generic by abstracting the provided Grammar
-	Parsing and building the AST at the same time
