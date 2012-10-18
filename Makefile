cube :	
	g++ -o cube -I/usr/local/include cube.cpp -L/usr/local/lib -losg -losgViewer -losgUtil
clean :	
	rm ./cube