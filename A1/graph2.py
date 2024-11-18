import matplotlib.pyplot as plt
from math import pi, asin

res = []
answer = 0.25 * pi + 1.25 * asin(0.8) - 1

with open("results.txt") as file:
	for i in file.readlines():
		res.append(i.rstrip()[3:].split(" | Area: "))

plt.plot([int(i[0]) for i in res], [abs(float(i[1]) - answer) / answer for i in res])
plt.show()
