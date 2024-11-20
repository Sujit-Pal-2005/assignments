import matplotlib.pyplot 

with open("output.txt", "r") as file:
    points = file.read().split()

x = []
y = []

# Put the input and output in lists
for i in range(0, 997, 2):
    x.append(float(points[i]))
    y.append(float(points[i+1]))

# Create the plot
matplotlib.pyplot .scatter(x, y,s=5)
matplotlib.pyplot .title(f" Plot of quick sort")
matplotlib.pyplot .xlabel("input values")
matplotlib.pyplot .ylabel("output values")
matplotlib.pyplot .grid(True)
matplotlib.pyplot .show()
file.close()