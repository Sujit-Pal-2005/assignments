import matplotlib.pyplot as plt

# Colors dictionary (keys are integers, not floats)
colors = {
    0: "blue",   # Sorting method 0
    1: "red",    # Sorting method 1
    2: "green"   # Sorting method 2
}

with open("output2.txt", "r") as file:
    points = file.read().split()

x = []
y = []
sorting_id = []

# Parse the data (assuming the file contains x, y, and sorting ID columns)
for i in range(0, len(points) - 2, 3):
    x.append(float(points[i]))
    y.append(float(points[i + 1]))
    sorting_id.append(int(float(points[i + 2]))) 

# Ensure all sorting_ids have a corresponding color
point_colors = [colors.get(id, "black") for id in sorting_id]  # Fallback to 'black' if id is missing

# Create the scatter plot
plt.scatter(x, y, c=point_colors, s=1)

# Add title and labels
plt.title("Plot of every sort")
plt.xlabel("Number of elements in array")
plt.ylabel("Number of comparisons for sorting")
plt.grid(True)

# Show the plot
plt.show()

file.close()
