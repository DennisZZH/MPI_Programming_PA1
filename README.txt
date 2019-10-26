Last name of Student 1: Zhang
First name of Student 1: Zihao
Email of Student 1: zihaozhang@ucsb.edu
Last name of Student 2: Lin
First name of Student 2: Tiancheng
Email of Student 2: tianchenglin@ucsb.edu



Report for Question 1

number of tosses: 1,000,000,000

                               		 4 nodes(16 processes)               					8 nodes(32 processes)

parallel time 				   		2.551000	  						1.158138


speedup							6.039								13.299


efficiency						1.510								1.662



Report for Question 3.a

n = 4096, t = 1024

                               		 2 nodes(4 processes)                					4 nodes(8 processes)

parallel time 						2.345729							0.885354


speedup							4.859								12.881


efficiency						2.430								3.220



Report for Question 3.b

n = 4096, t = 1024

                                	2 nodes(4 processes)                					4 nodes(8 processes)

parallel time 						2.047593							0.838710


speedup							2.827								6.903


efficiency						1.414								1.726



The efficiency of the Problem 3.b is lower than that of Problem 3.a because matrices in 3.b have different length so that the processes become idle at some times so the efficiency is lower.


A strategy that we can address this issue is that We can use different data mapping methods. For example, instead of using 1D block, we can use 1D block cyclic or cyclic based on Round Robin or other similar strategy.