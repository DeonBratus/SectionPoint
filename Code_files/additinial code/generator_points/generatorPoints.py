import csv
import random

# Генерируем 20 точек маршрута с координатами в диапазоне [-10, 10]
route_points = [(i, random.uniform(-10, 10)) for i in range(20)]

# Сохраняем точки маршрута в CSV-файл
with open('route_points.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['x', 'y'])  # Записываем заголовок столбцов
    for point in route_points:
        writer.writerow(point)

print("Массив точек маршрута сохранен в файл 'route_points.csv'")