in = input.unif2
bin = input.bin
ps = input.ps
out = output.ps
tt = table.bin
# realdata = zonoise.su
realdata = zerooffset.su
kd = migrated.su
n1 = 250
n2 = 700
unif2params = method=spline nx=$(n2) dx=10 nz=$(n1) dz=10 ninf=2
rayt2dparams = vfile=$(bin) tfile=$(tt) nt=2000 dt=0.002 nz=$(n1) dz=10 nx=$(n2) dx=10 nxs=200 dxs=20 fxs=0
# TODO Complete parameters here
kdparams = infile=$(realdata) ttfile=$(tt) outfile=$(kd) fzt=0 nzt=$(n1) dzt=10 fxt=0 nxt=$(n2) dxt=10 fs=0 ns=200 ds=20 dxm=20

default: clean

generate-bin:
	cat $(in) | unif2 $(unif2params) | smooth2 n1=$(n1) n2=$(n2) r1=5 r2=5 > $(bin)

generate-ps: generate-bin migrate
	psimage < $(bin) > $(ps) n1=250
	supsimage < $(kd) > $(out)

generate-ray: generate-bin
	rayt2d $(rayt2dparams)

migrate: generate-ray
	sukdmig2d $(kdparams)

clean: generate-ps
	rm $(bin)
	rm $(tt)
	rm $(kd)
