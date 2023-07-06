all:
	g++ -std=c++17 src/Tasker.cpp -o tsk
	chmod +x tsk

clean:
	$(RM) tsk 