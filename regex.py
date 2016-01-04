import re

if __name__ == "__main__":
	tests = int(raw_input())
	while tests > 0:
		reg = raw_input()
		if reg.length > 10:
			print "NO"
		else:
			match = re.match(r'^[7-9]\d{9}', reg)
			if match:
				print "YES"
			else:
				print "NO"
		tests -= 1