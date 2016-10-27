n, k = map(int, raw_input().split())
click = []
for i in range(k):
	clk = raw_input()
	if clk == 'CLOSEALL':
		click = []
	else:
		no = (clk.split()[1])
		if no in click:
			click.remove(no)
		else:
			click.append(no)
	print len(click)
