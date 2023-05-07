import csv
import random

# Generating coordinates values
route_points = [(i, random.uniform(-10, 10)) for i in range(20)]

# Save to scv file
with open('route_points.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['x', 'y'])  # title
    for point in route_points:
        writer.writerow(point)
# Print to console
print("Массив точек маршрута сохранен в файл 'route_points.csv'")
