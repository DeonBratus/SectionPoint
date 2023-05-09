import csv
import random

# Generating coordinates values
route_points = [(i, random.uniform(-50, 50)) for i in range(100)]

# Save to scv file
with open('route_points.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['x', 'y'])  # title
    for point in route_points:
        writer.writerow(point)
# Print to console
print("Array has been save to file 'route_points.csv'")
