import math

def haversine(lat1, lon1, lat2, lon2):
    R = 6371000  # радиус Земли в метрах
    phi1 = math.radians(lat1)
    phi2 = math.radians(lat2)
    delta_phi = math.radians(lat2 - lat1)
    delta_lambda = math.radians(lon2 - lon1)

    a = math.sin(delta_phi / 2) ** 2 + math.cos(phi1) * math.cos(phi2) * math.sin(delta_lambda / 2) ** 2
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
    distance = R * c

    return distance

# Координаты точек
points = [
    (39.709846, 47.237921),
    (39.710197, 47.237928),
    (39.710765, 47.237939),
    (39.710759, 47.238107),
    (39.710843, 47.238211),
    (39.71092, 47.23827),
    (39.711409, 47.23849),
    (39.711409, 47.23849)
]

total_distance = 0

for i in range(len(points) - 1):
    lat1, lon1 = points[i]
    lat2, lon2 = points[i + 1]
    distance = haversine(lat1, lon1, lat2, lon2)
    total_distance += distance

print(f"Общее расстояние между точками: {total_distance} метров")
