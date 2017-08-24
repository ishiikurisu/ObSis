in = input.unif2
bin = input.bin
ps = input.ps
n1 = 250
n2 = 700
unif2params = method=spline nx=$(n2) dx=10 nz=$(n1) dz=10 ninf=2

default: clean

generate-bin:
	cat $(in) | unif2 $(unif2params) | smooth2 n1=$(n1) n2=$(n2) r1=5 r2=5 > $(bin) 
generate-ps: generate-bin
	psimage < $(bin) > $(ps) n1=250

clean: generate-ps
	rm $(bin)
