all: ttc1 ttc2 tts1 tts2

tts1: tcp_server_1.cpp
	g++ -std=c++14 -w tcp_server_1.cpp -o tts1

tts2: tcp_server_2.cpp
	g++ -std=c++14 -w tcp_server_2.cpp -o tts2

ttc1: tcp_client_1.cpp
	g++ -std=c++14 -w tcp_client_1.cpp -o ttc1

ttc2: tcp_client_2.cpp
	g++ -std=c++14 -w tcp_client_2.cpp -o ttc2

clean:
	rm -f ttc1 ttc2 tts1 tts2
