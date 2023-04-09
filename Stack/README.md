Stack
====
MIPT Huawei course
---
---
### The task
The task is to implement a secure stack. The implementation of canaries is the main semantic part of the project.
I also practiced logging and returning error codes.
Test output with a print of everything that happens:
~~~
Stack was create, capacity is: 5, size is: 0
The stack now looks like this:
|1957747803|0|0|0|0|0|1957747803|

You pushed 1 in stack, size is: 1, capacity is: 5
The stack now looks like this:
|1957747803|1|0|0|0|0|1957747803|

You pulled an element from the stack, the value is equal to 1
New size is: 0
The stack now looks like this:
|1957747803|1|0|0|0|0|1957747803|

You pushed 3 in stack, size is: 1, capacity is: 5
The stack now looks like this:
|1957747803|3|0|0|0|0|1957747803|

You pushed 5 in stack, size is: 2, capacity is: 5
The stack now looks like this:
|1957747803|3|5|0|0|0|1957747803|

You pushed 6 in stack, size is: 3, capacity is: 5
The stack now looks like this:
|1957747803|3|5|6|0|0|1957747803|

You pushed 1 in stack, size is: 4, capacity is: 5
The stack now looks like this:
|1957747803|3|5|6|1|0|1957747803|

You pushed 2 in stack, size is: 5, capacity is: 5
The stack now looks like this:
|1957747803|3|5|6|1|2|1957747803|

You pulled an element from the stack, the value is equal to 2
New size is: 4
==================> 2
You pushed 9 in stack, size is: 5, capacity is: 5
The stack now looks like this:
|1957747803|3|5|6|1|9|1957747803|

You pushed 10 in stack, size is: 6, capacity is: 10
The stack now looks like this:
|1957747803|3|5|6|1|9|10|-1094795586|-1094795586|-1094795586|-1094795586|1957747803|

You pushed 10 in stack, size is: 7, capacity is: 10
The stack now looks like this:
|1957747803|3|5|6|1|9|10|10|-1094795586|-1094795586|-1094795586|1957747803|
~~~
Of course, such output can be disabled if desired, if it is necessary to use the stack somehow in the future.
### How to build
You should run makefile, to do this, write "make" in the console from the Stack folder. Then you will have the main.out file, just run it with "./main.out".