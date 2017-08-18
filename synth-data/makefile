in = input.unif2
bin = input.bin
ps = input.ps
unif2params = method=spline nx=700 dx=10 nz=250 dz=10 ninf=2

default: clean

generate-bin:
	unif2 < $(in) > $(bin) $(unif2params)
generate-ps: generate-bin
	psimage < $(bin) > $(ps) n1=250

clean: generate-ps
	rm $(bin)
