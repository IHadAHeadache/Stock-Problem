MaximumSubarrayProblem.out:MaximumSubarrayProblem.o msp.o
	g++ -o MaximumSubarrayProblem.out MaximumSubarrayProblem.o msp.o
MaximumSubarrayProblem.o:MaximumSubarrayProblem.cpp msp.h
	g++ -c MaximumSubarrayProblem.cpp
msp.o:msp.cpp msp.h
	g++ -c msp.cpp

clean:
	rm -f MaximumSubarrayProblem.o msp.o MaximumSubarrayProblem.out
