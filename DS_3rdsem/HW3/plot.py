import matplotlib.pyplot 
colors = {
    0: "red",
    1: "blue",
    2: "green",
    3: "yellow",
    4: "purple",
    5: "orange",
    6: "black",
    7: "white",
    8: "pink",
    9: "brown"
}

with open("output.txt", "r") as file:
    points = file.read().split()

# Total number of points
n = int(points[0])

# Number of clusters
k = int(points[1])

x = []
y = []
cluster_ids = []

# Put the coordinates in lists
for i in range(2, (3*n)+1, 3):
    x.append(float(points[i]))
    y.append(float(points[i+1]))
    cluster_ids.append(int(points[i+2]))

point_colors = [colors[id] for id in cluster_ids]

# Create the plot
matplotlib.pyplot .scatter(x, y, c=point_colors)
matplotlib.pyplot .title(f"Scatter plot of {n} points in {k} clusters")
matplotlib.pyplot .xlabel("x values")
matplotlib.pyplot .ylabel("y values")
matplotlib.pyplot .grid(True)
matplotlib.pyplot .show()

file.close()