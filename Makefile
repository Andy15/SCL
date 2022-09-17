template.pdf: template.tex main
	./main
	xelatex template.tex -shell-escape
	xelatex template.tex -shell-escape
	xelatex template.tex -shell-escape

template.tex: main

main: main.cpp
	g++ main.cpp -o main