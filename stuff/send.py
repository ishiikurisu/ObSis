import os
import sys

if __name__ == '__main__':
	for n in range(6):
		f = 'tardisk0%d' % (n)
		i = sys.argv[1]
		p = sys.argv[2]
		os.system('file2mail.py %s %s %s %s' % (i, p, i, f))
