# Sizing-Algorithm

This Algorithm implements a computational method of the Sizing command used in military parades.

The Sizing Command is used to sort a formation of m x n people into a new formation such that their heights descend inward and backward. This helps to make parade formations neater for the audience. An example can be found at https://www.youtube.com/watch?v=e3D_cg4G5yg.

This Algorithm is inspired by the steps used in that command to sort a matrix of random values into a new matrix that likewise has descending value as one goes inwards. The steps, in footdrill, are mimicked as code.

It is imagined that there may be a more efficient implementation that we can find using computation, which can then be later applied to real-world footdrill. That is the objective of this repository.

Further work includes extending the implementation to rows of >3 ranks; the above implementation works only for formations of 3 ranks.

To illustrate the steps in footdrill:

Say we have a random matrix like the following:
3 2 4
5 8 9
1 6 7

The command starts by getting all men to line up in a straight line in height order. Similarly:
1 2 3 4 5 6 7 8 9

Now, we separate odd and even numbers. In the command, the odd and even numbers move forward and backward respesctively:
 2  4  6  8
1  3  5  7  9
 
Then, the odd numbers turn right and the even numbers turn left less the right marker. The rows then march forward in quick time.

The odd row starts to fill up the formation's ranks. It will fill it up in a 1 - 3 - 2 manner, with 1 at the front and 3 at the back of the formation. The even row follows suit, but will fill it up in a 2 - 3 - 1 manner. This will produce the desired formation, with empty ranks later covered up through a Right Dress.
6 1 7
4 2 5
8 3 9
