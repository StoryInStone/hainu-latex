all:	once

once: 	
	pdflatex report.tex
	
alert: 	
	pdflatex -halt-on-error report.tex

view:	report.pdf
	evince report.pdf
	
clean: 
	rm *.log *.nlo *.idx report.synctex* *.aux *.toc *.out 

bib:
	make once
	bibtex report.aux
	make once
