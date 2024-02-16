all: uts1 uts2 utc1 utc2

uts1: udp_server_1.cpp
	g++ -std=c++14 -w udp_server_1.cpp -o uts1

uts2: udp_server_2.cpp
	g++ -std=c++14 -w udp_server_2.cpp -o uts2

utc1: udp_client_1.cpp
	g++ -std=c++14 -w udp_client_1.cpp -o utc1

utc2: udp_client_2.cpp
	g++ -std=c++14 -w udp_client_2.cpp -o utc2

clean:
	rm -f uts1 uts2 utc1 utc2
