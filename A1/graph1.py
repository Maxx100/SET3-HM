import matplotlib.pyplot as plt

res = []
with open("results.txt") as file:
	for i in file.readlines():
		res.append(i.rstrip()[3:].split(" | Area: "))

plt.plot([int(i[0]) for i in res], [float(i[1]) for i in res])
plt.show()
