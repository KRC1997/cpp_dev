/*
Problem 4

Clash Royale is a real time strategy card game. Each card has an attack power and a level.
Each player picks 8 cards to form a battle deck; the total attack power of a deck is the 
sum of the attack power of each of its cards. Players fight with each other by placing cards
from their battle decks into the battle arena. The winner of a battle is rewarded with coins,
which can be used to upgrade cards. Upgrading a card increases its attack power.

After days of arena fighting, Little Shawn has accumulated a total of M coins. He has decided
to upgrade some of his cards. Little Shawn has N cards. The i-th card can have any level from
1 through Ki; the attack power for the j-th level is Ai,j. Cards must be upgraded one level 
at a time; the price to upgrade the i-th card from level j to level j+1 costs Ci,j coins. 
The i-th card is currently at level Li before Little Shawn has upgraded any cards.

Little Shawn wants to use some or all of his coins to upgrade cards, and then form a deck of 
exactly 8 cards, so that the deck's total attack power is as large as possible. Can you help 
him do this? He can upgrade the same card more than once as long as he can afford it, and he 
does not have to upgrade every card.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test 
case starts with 2 integers M and N, the number of coins and the number of cards that Little 
Shawn possesses. Then N blocks follow. The i-th block consists of 3 lines describing the i-th 
card. The first line contains two integers Ki and Li, the maximum possible level and current 
level of the card. The second line contains Ki integers Ai,1, Ai,2, ..., Ai,Ki, the attack 
power of each level. The third line contains Ki-1 integers Ci,1, Ci,2, ..., Ci,Ki-1, the 
number of coins required to upgrade a card that is currently at level 1, 2, ..., Ki-1.

Output

For each test case, output one line containing Case #x: y, where x is the test case number
(starting from 1) and y is the maximal possible total attack power of a deck that Little Shawn
can form, using the coins that he has.

Limits

Time limit: 60 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ Ki ≤ 10.
1 ≤ Li ≤ Ki.
Ai,j < Ai,j+1.
Small dataset (Test set 1 - Visible)

1 ≤ M ≤ 1,000.
N = 8.
1 ≤ Ai,j ≤ 1,000.
1 ≤ Ci,j ≤ 1,000.
Large dataset (Test set 2 - Hidden)

1 ≤ M ≤ 1,000,000,000.
8 ≤ N ≤ 12.
1 ≤ Ai,j ≤ 1,000,000,000.
1 ≤ Ci,j ≤ 1,000,000,000.
Sample

Input

2
20 8
3 1
1 10 100
1 2
3 1
1 10 100
1 3
3 1
1 10 100
1 4
3 1
1 10 100
1 5
3 1
1 10 100
1 6
3 1
1 10 100
1 7
3 1
1 10 100
1 8
3 1
1 10 100
1 9
30 10
4 1
1 10 100 200
1 2 3
3 1
1 10 100
2 4
3 1
1 10 100
3 6
4 2
1 10 100 200
4 8 16
3 1
1 10 100
5 10
3 1
1 10 100
6 12
3 1
1 10 100
7 14
3 1
1 10 100
8 16
3 1
1 10 100
9 18
3 1
1 10 100
10 20

Output

Case #1: 422
Case #2: 504


In sample case #1, you can upgrade the first 4 cards to level 3, upgrade the 5th and 6th card
to level 2, keep the last 2 cards level 1. This will cost you (1+2)+(1+3)+(1+4)+(1+5)+1+1=20
coins and the total attack power is 100+100+100+100+10+10+1+1=422 which is the maximal possible
we can get.

Sample case #2 will only appear in large dataset.
*/