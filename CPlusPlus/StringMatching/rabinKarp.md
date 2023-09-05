# String Matching using Rabin-Karp Algorithm
String matching is the process of matching one string (the pattern) to another string (the text). The original and most basic string matching algorithm, called the "Naive String Matching" algorithm has a worst case efficiency of $\Theta ((n-m+1)m)$.  
This is because there are $n-m+1$ iterations for the outer loop to run through the text of length 'n' and for each of those iterations the inner loop runs through the pattern of length 'm'.
## How is Rabin-Karp algorithm better?
In case of the Naive string matching algorithm, every single character of the pattern is matched with the characters of the text for every iteration.  
However, in the Rabin-Karp algorithm, each 'm' sized section of text, and the pattern itself, is converted into a numeric value. Before comparing individual charcters, these numeric values are checked first. The character matching procedure is only conducted if these numeric values match.  
This process of finding the numeric values has a complexity of $\Theta(m)$  
The Rabin-Karp algorithm's worst case complexity remains the same, however its average case complexity is better.
## Some Notations
A set of alphabets that will be used, in our case to make th text or pattern, will be denoted by $\Sigma$.  
The length of this set (i.e., the number of distinct characters in the set) is denoted by $d=|\Sigma|$ (length of set $\Sigma$).
