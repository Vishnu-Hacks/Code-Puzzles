#include <iostream>
typedef long long Long;
class fib {
	

public:fib() {}
	// returns the fibonacci number after num positions from 0.
	 Long findFib(Long num) {
		
		 if (num <= 2) {
			 return num == 0 ? 0 : 1;
		 }

		 Long fib = 0;
		 Long a = 1, b = 1;
		 while (num != 2) {
			 fib = a + b;
			 a = b;
			 b = fib;
			 --num;
		 }
		 return fib;
	}
	 //Slow algorithm 
	 Long findFib2(Long n) {

		 if (n <= 1)
			 return n;
		 else
			 return findFib2(n - 1) + findFib2(n - 2);
	 }
};

int main() {
	fib b;
	while (std::cin.good()) {
		std::cout << "Enter the distance of fib number to find : ";
		Long a;
		std::cin >> a;
		std::cout << "The Number is : " << b.findFib(a) << "\n";
		std::cout << "(Slow) The Number is : ";std::cout << b.findFib2(a) << "\n\n";
	}
}

/*
Fib(0)=0
Fib(1)=1
Fib(2)=1
Fib(3)=2
Fib(4)=3
Fib(5)=5
Fib(6)=8
Fib(7)=13
Fib(8)=21
Fib(9)=34
Fib(10)=55
Fib(11)=89
Fib(12)=144
Fib(13)=233
Fib(14)=377
Fib(15)=610
Fib(16)=987
Fib(17)=1597
Fib(18)=2584
Fib(19)=4181
Fib(20)=6765
Fib(21)=10946
Fib(22)=17711
Fib(23)=28657
Fib(24)=46368
Fib(25)=75025
Fib(26)=121393
6 digits
Fib(27)=196418
6 digits
Fib(28)=317811
6 digits
Fib(29)=514229
6 digits
Fib(30)=832040
6 digits
Fib(31)=1346269
7 digits
Fib(32)=2178309
7 digits
Fib(33)=3524578
7 digits
Fib(34)=5702887
7 digits
Fib(35)=9227465
7 digits
Fib(36)=14930352
8 digits
Fib(37)=24157817
8 digits
Fib(38)=39088169
8 digits
Fib(39)=63245986
8 digits
Fib(40)=102334155
9 digits
Fib(41)=165580141
9 digits
Fib(42)=267914296
9 digits
Fib(43)=433494437
9 digits
Fib(44)=701408733
9 digits
Fib(45)=1134903170
10 digits
Fib(46)=1836311903
10 digits
Fib(47)=2971215073
10 digits
Fib(48)=4807526976
10 digits
Fib(49)=7778742049
10 digits
Fib(50)=12586269025
11 digits
Fib(51)=20365011074
11 digits
Fib(52)=32951280099
11 digits
Fib(53)=53316291173
11 digits
Fib(54)=86267571272
11 digits
Fib(55)=139583862445
12 digits
Fib(56)=225851433717
12 digits
Fib(57)=365435296162
12 digits
Fib(58)=591286729879
12 digits
Fib(59)=956722026041
12 digits
Fib(60)=1548008755920
13 digits
Fib(61)=2504730781961
13 digits
Fib(62)=4052739537881
13 digits
Fib(63)=6557470319842
13 digits
Fib(64)=10610209857723
14 digits
Fib(65)=17167680177565
14 digits
Fib(66)=27777890035288
14 digits
Fib(67)=44945570212853
14 digits
Fib(68)=72723460248141
14 digits
Fib(69)=117669030460994
15 digits
Fib(70)=190392490709135
15 digits
Fib(71)=308061521170129
15 digits
Fib(72)=498454011879264
15 digits
Fib(73)=806515533049393
15 digits
Fib(74)=1304969544928657
16 digits
Fib(75)=2111485077978050
16 digits
Fib(76)=3416454622906707
16 digits
Fib(77)=5527939700884757
16 digits
Fib(78)=8944394323791464
16 digits
Fib(79)=14472334024676221
17 digits
Fib(80)=23416728348467685
17 digits
Fib(81)=37889062373143906
17 digits
Fib(82)=61305790721611591
17 digits
Fib(83)=99194853094755497
17 digits
Fib(84)=160500643816367088
18 digits
Fib(85)=259695496911122585
18 digits
Fib(86)=420196140727489673
18 digits
Fib(87)=679891637638612258
18 digits
Fib(88)=1100087778366101931
19 digits
Fib(89)=1779979416004714189
19 digits
Fib(90)=2880067194370816120
19 digits
Fib(91)=4660046610375530309
19 digits
Fib(92)=7540113804746346429
19 digits
Fib(93)=12200160415121876738
20 digits
Fib(94)=19740274219868223167
20 digits
Fib(95)=31940434634990099905
20 digits
Fib(96)=51680708854858323072
20 digits
Fib(97)=83621143489848422977
20 digits
Fib(98)=135301852344706746049
21 digits
Fib(99)=218922995834555169026
21 digits
Fib(100)=354224848179261915075
21 dig
*/